/*
 * square_process.cpp
 *
 *  Created on: Sep 24, 2025
 *      Author: khoi-anh-nguyen
 */
#include "square_process.hpp"

void square_process::checkPins(bool * portAvail, uint8_t * buffer_list, uint8_t * buffer_pointer){
	if (portAvail[0]){
		GPIO_PinState PinState = HAL_GPIO_ReadPin(ADC1_GPIO_Port, ADC1_Pin);
		if (PinState == GPIO_PIN_SET){
			buffer_list[0] |= 0x1 << buffer_pointer[0];
		}
		else{
			buffer_list[0] &= ~(0x1 << buffer_pointer[0]);
		}
		buffer_pointer[0] += 1;
		//ADC1
		if (buffer_pointer[0] == 7){ //Sampling last bit of each byte
			buffer_pointer[0] = 0;
			fprintf(stdout, "%d\n", buffer_list[0]);
		}
	}
	//ADC2 (+ Voltage Range only)
	if (portAvail[1]){
		GPIO_PinState PinState = HAL_GPIO_ReadPin(ADC2_GPIO_Port, ADC2_Pin);
		if (PinState == GPIO_PIN_SET){
			buffer_list[1] |= 0x1 << buffer_pointer[1];
		}
		else{
			buffer_list[1] &= ~(0x1 << buffer_pointer[1]);
		}
		buffer_pointer[1] += 1;
		//ADC1
		if (buffer_pointer[1] == 7){ //Sampling last bit of each byte
			buffer_pointer[1] = 0;
			fprintf(stdout, "%d\n", buffer_list[1]);
		}
	}
	//ADC3 (+ Voltage Range Only)
	if (portAvail[2]){
		GPIO_PinState PinState = HAL_GPIO_ReadPin(ADC3_GPIO_Port, ADC3_Pin);
		if (PinState == GPIO_PIN_SET){
			buffer_list[2] |= 0x1 << buffer_pointer[2];
		}
		else{
			buffer_list[2] &= ~(0x1 << buffer_pointer[2]);
		}
		buffer_pointer[2] += 1;
		//ADC1
		if (buffer_pointer[2] == 7){ //Sampling last bit of each byte
			buffer_pointer[2] = 0;
			fprintf(stdout, "%d\n", buffer_list[2]);
		}
	}
	//ADC4 (+ Voltage Range only)
	if (portAvail[3]){
		GPIO_PinState PinState = HAL_GPIO_ReadPin(ADC4_GPIO_Port, ADC4_Pin);
		if (PinState == GPIO_PIN_SET){
			buffer_pointer[3] |= 0x1 << buffer_pointer[3];
		}
		else{
			buffer_pointer[3] &= ~(0x1 << buffer_pointer[3]);
		}
		buffer_pointer[3] += 1;
		//ADC1
		if (buffer_pointer[3] == 7){ //Sampling last bit of each byte
			buffer_pointer[3] = 0;
			fprintf(stdout, "%d\n", buffer_pointer[3]);
		}
	}
}
