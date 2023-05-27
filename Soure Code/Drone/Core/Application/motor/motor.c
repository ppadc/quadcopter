/*
 * motor.c
 *
 *  Created on: Mar 30, 2023
 *      Author: nguye
 */

#include "motor.h"
#include <stdlib.h>

#include "tim.h"
#include "gpio.h"

typedef void (*set_speed_func_t)(int32_t speed);

static set_speed_func_t gset_speed_motor0;
static set_speed_func_t gset_speed_motor1;
static set_speed_func_t gset_speed_motor2;
static set_speed_func_t gset_speed_motor3;

static void motor0_setspeed(int32_t speed);
static void motor1_setspeed(int32_t speed);
static void motor2_setspeed(int32_t speed);
static void motor3_setspeed(int32_t speed);

void motors_init(){
	HAL_TIM_PWM_Start(&MOTOR0_TIMER, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&MOTOR1_TIMER, TIM_CHANNEL_2);
	HAL_TIM_PWM_Start(&MOTOR2_TIMER, TIM_CHANNEL_3);
	HAL_TIM_PWM_Start(&MOTOR3_TIMER, TIM_CHANNEL_4);

//	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 0);
//	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 0);
//	__HAL_TIM_SET_COMPARE(&MOTOR2_TIMER, MOTOR2_CHANNEL, 0);
//	__HAL_TIM_SET_COMPARE(&MOTOR3_TIMER, MOTOR3_CHANNEL, 0);

	gset_speed_motor0 = motor0_setspeed;
	gset_speed_motor1 = motor1_setspeed;
	gset_speed_motor2 = motor2_setspeed;
	gset_speed_motor3 = motor3_setspeed;
}

void motor_deinit(){
	__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, 0);
	__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, 0);
	__HAL_TIM_SET_COMPARE(&MOTOR2_TIMER, MOTOR2_CHANNEL, 0);
	__HAL_TIM_SET_COMPARE(&MOTOR3_TIMER, MOTOR3_CHANNEL, 0);

}

static void motor0_setspeed(int32_t speed){
		__HAL_TIM_SET_COMPARE(&MOTOR0_TIMER, MOTOR0_CHANNEL, abs(speed));
}

static void motor1_setspeed(int32_t speed){
		__HAL_TIM_SET_COMPARE(&MOTOR1_TIMER, MOTOR1_CHANNEL, abs(speed));
}

static void motor2_setspeed(int32_t speed){
		__HAL_TIM_SET_COMPARE(&MOTOR2_TIMER, MOTOR2_CHANNEL, abs(speed));
}

static void motor3_setspeed(int32_t speed){
		__HAL_TIM_SET_COMPARE(&MOTOR3_TIMER, MOTOR3_CHANNEL, abs(speed));
}

void motors_setspeed(motors_t motor, int32_t speed){
	switch(motor){
	case MOTOR_0:
		if(speed!=0) speed = speed > 0 ? (speed+params.motor0_deadband) : (speed-speed);
		if(speed > THRUST_MOTOR_MAX) speed = THRUST_MOTOR_MAX;
		gset_speed_motor0(speed);
		break;
	case MOTOR_1:
		if(speed!=0) speed = speed > 0 ? (speed+params.motor1_deadband) : (speed-speed);
		if(speed > THRUST_MOTOR_MAX) speed = THRUST_MOTOR_MAX;
		gset_speed_motor1(speed);
		break;
	case MOTOR_2:
		if(speed!=0) speed = speed > 0 ? (speed+params.motor2_deadband) : (speed-speed);
		if(speed > THRUST_MOTOR_MAX) speed = THRUST_MOTOR_MAX;
		gset_speed_motor2(speed);
		break;
	case MOTOR_3:
		if(speed!=0) speed = speed > 0 ? (speed+params.motor3_deadband) : (speed-speed);
		if(speed > THRUST_MOTOR_MAX) speed = THRUST_MOTOR_MAX;
		gset_speed_motor3(speed);
		break;
	}
}
