/*
 * run.cpp
 *
 *  Created on: Jul 31, 2025
 *      Author: Admin
 */
//Good Study Ref:
//https://www.beyondlogic.org/usbnutshell/usb5.shtml

#include "run.h"
#include "usblib.hpp"
#include "usbsetup.hpp"
#include "adc_process.hpp"
#include "square_process.hpp"

extern "C"{
	extern PCD_HandleTypeDef hpcd_USB_FS;
	extern ADC_HandleTypeDef hadc1;
	extern ADC_HandleTypeDef hadc2;
	extern ADC_HandleTypeDef hadc3;
	extern ADC_HandleTypeDef hadc4;
	extern DAC_HandleTypeDef hdac1;
	extern TIM_HandleTypeDef htim2;
	extern UART_HandleTypeDef huart5;
}

Usb_Com usb = Usb_Com(&hpcd_USB_FS);
Usb_Setup usb_setup = Usb_Setup(&hpcd_USB_FS);
Usb_Setup::DeviceDescriptor usb_descriptor;
bool portMode[5] = {true, true, true, true, true};    //True means Square Mode, False means Sine Mode
bool portStatus[5] {true, true, false, false, false}; //True means On, False means Off
uint8_t adcbitPointer [4] = {0,0,0,0};
uint8_t adcTransmitBuffer[5] = {0,0,0,0};

adc_process adc_config;
square_process square_config;

void ProcessSetup(PCD_HandleTypeDef *hpcd){
	Usb_Setup::SetupUsbPacket * setup_packet = (Usb_Setup::SetupUsbPacket *) (*usb_setup.usb_instance).Setup;
	
	switch (setup_packet->bRequest) {
		case Usb_Setup::SET_ADDRESS: {
			if (HAL_PCD_SetAddress(usb_setup.usb_instance, setup_packet->wValue) != HAL_OK){
				fprintf(stderr, "Cannot Setup Device Address\n");
				break;
			}
			fprintf(stdout, "Device Address Setup\n");
			break;
		}

		case Usb_Setup::SET_INTERFACE:{
			if (setup_packet->wValue == Usb_Setup::SineWave){
				SineWaveInit();
				fprintf(stdout, "Switiching to Sine Wave Mode\n");
				usb_setup.isSquareWave = false;
			}
			else{
				SquareWaveInit();
				fprintf(stdout, "Switching to Square Wave Mode\n");
				usb_setup.isSquareWave = true;
			}
			break;
		}
		
		case Usb_Setup::GET_INTERFACE:{
			uint8_t currentMode = (uint8_t) usb_setup.isSquareWave;
			if (HAL_PCD_EP_Transmit(usb_setup.usb_instance, Usb_Com::OUTDEFAULT + 1, &currentMode , 1) != HAL_OK){
				fprintf(stderr, "Cannot Send Device Configuration");
				break;
			}
			fprintf(stdout, "Device Configuration Sent\n");
			break;
		}
		case Usb_Setup::GET_DESCRIPTOR: {
			uint8_t * usb_descriptor_bytes = (uint8_t *)&usb_descriptor;
			if (HAL_PCD_EP_Transmit(usb_setup.usb_instance, Usb_Com::OUTDEFAULT + 1, usb_descriptor_bytes, usb_descriptor.bLength) != HAL_OK){
				fprintf(stderr, "Cannot Send Device Descriptor");
				break;
			}
			fprintf(stdout, "Device Descriptor Sent\n");
			break;
		}
		default:
			break;
	}
}

void Usb_Transmitted(PCD_HandleTypeDef *hpcd, uint8_t epnum){
	usb.Transmitted = true;
}

void Usb_Received(PCD_HandleTypeDef *hpcd, uint8_t epnum){
	usb.Received = true;
}

void SquareWaveInit(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = ADC1_Pin | ADC2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(ADC1_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = ADC3_Pin | ADC4_Pin;
	HAL_GPIO_Init(ADC3_GPIO_Port, &GPIO_InitStruct);
}

void SineWaveInit(){
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = ADC1_Pin | ADC2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(ADC1_GPIO_Port, &GPIO_InitStruct);

	GPIO_InitStruct.Pin = ADC3_Pin | ADC4_Pin;
	HAL_GPIO_Init(ADC3_GPIO_Port, &GPIO_InitStruct);
}

void CheckSquareVal(TIM_HandleTypeDef * htim2){

}

void CheckSineVal(TIM_HandleTypeDef * htim2){
	fprintf(stdout, "CAV");
}

extern "C" HAL_StatusTypeDef run(){
//USB Config
//	fprintf(stdout, "Started Usb Config\n");
//	uint8_t tracked_ep = 1;
//
//	if (usb.Usb_Init() != HAL_OK){
//		fprintf(stderr, "Cannot Initialize USB Components\n");
//		return;
//	}
//	fprintf(stdout, "USB Components Initialized\n");
//
//	(*usb_setup.usb_instance).SetupStageCallback = ProcessSetup;
//	(*usb.usb_instance).DataInStageCallback = Usb_Received;
//	(*usb.usb_instance).DataOutStageCallback = Usb_Transmitted;
//
//	if (usb.OpenEndpoint(tracked_ep) != HAL_OK){
//		fprintf(stderr, "Cannot Open Endpoint %d\n", tracked_ep);
//		return;
//	}
//	fprintf(stdout, "Endpoint %d Opened\n", tracked_ep);
//	fprintf(stdout, "Usb Config Finished\n");

//ADC Config

	hadc1.EndOfSamplingCallback = adc_config.adc1ProcessEndOfSample;
	hadc2.EndOfSamplingCallback = adc_config.adc2ProcessEndOfSample;
	hadc3.EndOfSamplingCallback = adc_config.adc3ProcessEndOfSample;
	hadc4.EndOfSamplingCallback = adc_config.adc4ProcessEndOfSample;

	if (!portMode[0]){
		if (HAL_ADC_Start(&hadc1) != HAL_OK){
			return HAL_ERROR;
		}
	}
	if (!portMode[1]){
		if (HAL_ADC_Start(&hadc2) != HAL_OK){
			return HAL_ERROR;
		}
	}
	if (!portMode[2]){
		if (HAL_ADC_Start(&hadc2) != HAL_OK){
			return HAL_ERROR;
		}
	}
	if (!portMode[3]){
		if (HAL_ADC_Start(&hadc2) != HAL_OK){
			return HAL_ERROR;
		}
	}

//Timer Config
	if (portMode[3]){
		SquareWaveInit();
		htim2.PeriodElapsedCallback = CheckSquareVal;
	}
	else{
		htim2.PeriodElapsedCallback = CheckSineVal;
	}


//	if (HAL_TIM_Base_Start_IT(&htim2) != HAL_OK){     //Issue Enable it using HAL
//		fprintf(stdout, "Failed to config Timer\n");
//		return;
//	}

	//Manually Enable TIM2 Interrupt
	htim2.Instance->DIER = TIM_DIER_UIE;
	htim2.Instance->CR1 = TIM_CR1_CEN;


	while (1){
		__WFI();
	}
}
