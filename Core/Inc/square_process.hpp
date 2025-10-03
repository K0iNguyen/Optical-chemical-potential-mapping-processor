/*
 * digital_process.hpp
 *
 *  Created on: Sep 24, 2025
 *      Author: khoi-anh-nguyen
 */

#ifndef INC_SQUARE_PROCESS_HPP_
#define INC_SQUARE_PROCESS_HPP_

#include "stm32g4xx.h"
#include "port_def.hpp"
#include <stdbool.h>
#include <stdio.h>

class square_process{
public:
	void checkPins(bool * portAvail, uint8_t * buffer_list, uint8_t * buffer_pointer);
};


#endif /* INC_SQUARE_PROCESS_HPP_ */
