/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define ADC4_IDLE_IND_Pin GPIO_PIN_0
#define ADC4_IDLE_IND_GPIO_Port GPIOC
#define ADC1_IDLE_IND_Pin GPIO_PIN_1
#define ADC1_IDLE_IND_GPIO_Port GPIOC
#define ADC1_MOD1_IND_Pin GPIO_PIN_2
#define ADC1_MOD1_IND_GPIO_Port GPIOC
#define ADC1_MOD2_IND_Pin GPIO_PIN_3
#define ADC1_MOD2_IND_GPIO_Port GPIOC
#define ADC1_MOD3_IND_Pin GPIO_PIN_0
#define ADC1_MOD3_IND_GPIO_Port GPIOA
#define ADC1_MOD4_IND_Pin GPIO_PIN_1
#define ADC1_MOD4_IND_GPIO_Port GPIOA
#define ADC_MOD4_IND_Pin GPIO_PIN_7
#define ADC_MOD4_IND_GPIO_Port GPIOA
#define ADC_MOD3_IND_Pin GPIO_PIN_4
#define ADC_MOD3_IND_GPIO_Port GPIOC
#define ADC3_MOD2_IND_Pin GPIO_PIN_5
#define ADC3_MOD2_IND_GPIO_Port GPIOC
#define ADC3_MOD1_IND_Pin GPIO_PIN_0
#define ADC3_MOD1_IND_GPIO_Port GPIOB
#define ADC3_IDLE_IND_Pin GPIO_PIN_2
#define ADC3_IDLE_IND_GPIO_Port GPIOB
#define ADC4_MOD4_IND_Pin GPIO_PIN_11
#define ADC4_MOD4_IND_GPIO_Port GPIOB
#define ADC4_MOD3_IND_Pin GPIO_PIN_12
#define ADC4_MOD3_IND_GPIO_Port GPIOB
#define ADC4_MOD2_IND_Pin GPIO_PIN_13
#define ADC4_MOD2_IND_GPIO_Port GPIOB
#define ADC4_MOD1_IND_Pin GPIO_PIN_14
#define ADC4_MOD1_IND_GPIO_Port GPIOB
#define ADC2_MOD3_IND_Pin GPIO_PIN_6
#define ADC2_MOD3_IND_GPIO_Port GPIOC
#define ADC2_MOD3_INDC7_Pin GPIO_PIN_7
#define ADC2_MOD3_INDC7_GPIO_Port GPIOC
#define ADC2_MOD2_IND_Pin GPIO_PIN_8
#define ADC2_MOD2_IND_GPIO_Port GPIOC
#define ADC2_MOD1_IND_Pin GPIO_PIN_9
#define ADC2_MOD1_IND_GPIO_Port GPIOC
#define ADC2_IDLE_IND_Pin GPIO_PIN_8
#define ADC2_IDLE_IND_GPIO_Port GPIOA
#define RX_IND_Pin GPIO_PIN_9
#define RX_IND_GPIO_Port GPIOA
#define TX_IND_Pin GPIO_PIN_10
#define TX_IND_GPIO_Port GPIOA

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
