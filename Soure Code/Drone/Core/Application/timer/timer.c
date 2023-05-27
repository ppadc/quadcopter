/*
 * timer.c
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */
#include "timer.h"
#include "user_define.h"
#include "tim.h"

static callback_t callbacks[MAX_CALLBACK_FUNC];

int timer_init(){
	//HAL_TIM_Base_Start_IT(&htim1);
	return 0;
}

timer_id_t timer_register_callback(timer_callback_func_t timer_callback_func, uint16_t period_ms, void *cxt, timer_mode_t mode){
	for(uint8_t i = 0; i < MAX_CALLBACK_FUNC; i++){
		if(callbacks[i].timer_callback_func == 0){
			callbacks[i].timer_callback_func = timer_callback_func;
			callbacks[i].period_ms = period_ms;
			callbacks[i].context = cxt;
			callbacks[i].mode = mode;
			callbacks[i].cnt = period_ms;
			callbacks[i].id = i;
			return i;
		}
	}
	return TID_INVALID;
}

timer_id_t timer_unregister_callback(timer_id_t id){
	if(id==TID_INVALID) return TID_INVALID;
	callbacks[id].timer_callback_func = 0;
	return id;
}

uint64_t milis(){
	return HAL_GetTick();
}

void user_systick()
{
	for(uint8_t i = 0; i < MAX_CALLBACK_FUNC; i++){
		if(callbacks[i].timer_callback_func != 0){
			callbacks[i].cnt--;
			if(callbacks[i].cnt == 0){
				callbacks[i].timer_callback_func(callbacks[i].context);
				callbacks[i].cnt = callbacks[i].period_ms;
				if(callbacks[i].mode == TIMER_MODE_ONE_SHOT) callbacks[i].timer_callback_func = 0;
			}
		}
	}
}

//void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
//	if(htim->Instance != htim1.Instance) return;
//	user_systick();
//}
