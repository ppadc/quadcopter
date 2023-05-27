/*
 * delay_us.c
 *
 *  Created on: Apr 1, 2023
 *      Author: nguye
 */

#include "tim.h"
#include "user_define.h"

void delay_us(uint32_t us){
	__HAL_TIM_SET_COUNTER(&TIM_DELAY_US,0);
	while (__HAL_TIM_GET_COUNTER(&TIM_DELAY_US) < us);
}

void delay_ms(uint32_t ms){
	__HAL_TIM_SET_COUNTER(&TIM_DELAY_MS,0);
	while (__HAL_TIM_GET_COUNTER(&TIM_DELAY_US) < ms*1000);
}
