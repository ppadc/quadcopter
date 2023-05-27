/*
 * motor.h
 *
 *  Created on: Mar 30, 2023
 *      Author: nguye
 */

#ifndef CORE_APPLICATION_MOTOR_MOTOR_H_
#define CORE_APPLICATION_MOTOR_MOTOR_H_

#include "user_define.h"
#include <stdbool.h>

#include "motor_common.h"

void motors_init();
void motor_deinit();
void motors_setspeed(motors_t motor, int32_t speed); //Speed range 0 - 2000 but choose max 1800

#endif /* CORE_APPLICATION_MOTOR_MOTOR_H_ */
