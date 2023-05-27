/*
 * motor_common.h
 *
 *  Created on: Mar 31, 2023
 *      Author: nguye
 */

#ifndef CORE_APPLICATION_MOTOR_MOTOR_COMMON_H_
#define CORE_APPLICATION_MOTOR_MOTOR_COMMON_H_

#include "params.h"
#include "pid.h"
#include "timer.h"
#include "user_define.h"

#include "imu.h"
#include "mav.h"
#include "motor.h"

typedef enum{
	MOTOR_0,
	MOTOR_1,
	MOTOR_2,
	MOTOR_3,
}motors_t;

#endif /* CORE_APPLICATION_MOTOR_MOTOR_COMMON_H_ */
