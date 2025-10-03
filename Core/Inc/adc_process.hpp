/*
 * adc_process.hpp
 *
 *  Created on: Sep 24, 2025
 *      Author: khoi-anh-nguyen
 */

#ifndef INC_ADC_PROCESS_HPP_
#define INC_ADC_PROCESS_HPP_

#include "stm32g4xx.h"

class adc_process{
public:
	static void adc1ProcessEndOfSample (ADC_HandleTypeDef * hadc);
	static void adc2ProcessEndOfSample (ADC_HandleTypeDef * hadc);
	static void adc3ProcessEndOfSample (ADC_HandleTypeDef * hadc);
	static void adc4ProcessEndOfSample (ADC_HandleTypeDef * hadc);
private:

};


#endif /* INC_ADC_PROCESS_HPP_ */
