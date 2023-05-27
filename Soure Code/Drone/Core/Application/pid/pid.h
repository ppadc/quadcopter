/*
 * pid.h
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_PID_PID_H_
#define APPLICATION_PID_PID_H_

#include <stdbool.h>
#include "user_define.h"

#if PID_CONTROL_TYPE == 0
typedef struct{
	//public variables
	float KP;
	float KI;
	float KD;

	//private parameters
	float minIpart;
	float maxIpart;
	float minDpart;
	float maxDpart;
	float minOut;
	float maxOut;

	//private variables
	bool isFirstCompute;
	float sp;
	float fb;
	float err;
	float preIPart;
	float preError;
	float P_Part;
	float I_Part;
	float D_Part;
	float U;
}pid_params_t;
#elif PID_CONTROL_TYPE == 1
typedef struct{
	//public variables
	float KP;
	float KI;
	float KD;

	//private parameters
	float min_alpha_part;
	float max_alpha_part;
	float min_beta_part;
	float max_beta_part;
	float min_gamma_part;
	float max_gamma_part;
	float minOut;
	float maxOut;

	//private variables
	bool isFirstCompute;
	float sp;
	float fb;
	float err;
	float preOutput;
	float preError;
	float pre2Error;
	float alpha_part;
	float beta_part;
	float gamma_part;
	float U;
}pid_params_t;
#endif

float pid_compute(pid_params_t *pid_params, float sp, float fb, float dt);
void  pid_reset(pid_params_t *pid_params);

#endif /* APPLICATION_PID_PID_H_ */
