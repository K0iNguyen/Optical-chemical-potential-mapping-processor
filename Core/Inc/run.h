/*
 * run.hpp
 *
 *  Created on: Jul 31, 2025
 *      Author: Admin
 */

#ifndef INC_RUN_H_
#define INC_RUN_H_

#ifdef __cplusplus
extern "C"{
#endif
#include "stm32g4xx_hal.h"
#include <stdbool.h>
#include <stdio.h>

HAL_StatusTypeDef run();
void ProcessSetup(PCD_HandleTypeDef *hpcd);
void Usb_Transmitted(PCD_HandleTypeDef *hpcd, uint8_t epnum);
void Usb_Received(PCD_HandleTypeDef *hpcd, uint8_t epnum);
void SineWaveInit();
void SquareWaveInit();

#ifdef __cplusplus
}
#endif

#endif /* INC_RUN_H_ */
