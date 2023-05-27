/*
 * timer.h
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_TIMER_TIMER_H_
#define APPLICATION_TIMER_TIMER_H_

#include <stdint.h>

typedef void(*timer_callback_func_t)(void *cxt); //void(*)(void *)
typedef int8_t timer_id_t;
typedef int8_t timer1_id_t;

#define TID_INVALID -1
#define TID(x) static timer_id_t x=TID_INVALID;

typedef enum{
	TIMER_MODE_REPEAT,
	TIMER_MODE_ONE_SHOT
}timer_mode_t;

typedef struct{
	timer_callback_func_t timer_callback_func;
	uint16_t period_ms;
	uint16_t cnt;
	void *context;
	uint8_t id;
	timer_mode_t mode;
}callback_t;

int timer_init();
timer_id_t timer_register_callback(timer_callback_func_t timer_callback_func, uint16_t period_ms, void* cxt, timer_mode_t mode);
timer_id_t timer_unregister_callback(timer_id_t id);

uint64_t milis();
void user_systick();

#endif /* APPLICATION_TIMER_TIMER_H_ */
