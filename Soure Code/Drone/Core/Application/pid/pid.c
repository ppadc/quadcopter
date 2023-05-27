/*
 * pid.c
 *
 *  Created on: Mar 14, 2023
 *      Author: nguye
 */
#include "math.h"

#include "pid.h"

#if PID_CONTROL_TYPE == 0
float pid_compute(pid_params_t *pid_params, float sp, float fb, float dt){
		// Save set point, feed back and error
		pid_params->sp = sp;
		pid_params->fb = fb;
		pid_params->err = sp-fb;
		// Compute P part
		pid_params->P_Part = pid_params->KP*pid_params->err;

		// Compute I part and saturate it
		pid_params->I_Part = pid_params->preIPart + pid_params->KI*pid_params->err*dt;
		if(pid_params->I_Part < pid_params->minIpart) pid_params->I_Part = pid_params->minIpart;
		if(pid_params->I_Part > pid_params->maxIpart) pid_params->I_Part = pid_params->maxIpart;
		pid_params->preIPart = pid_params->I_Part;

		// Compute D part and saturate it
		if(pid_params->isFirstCompute){
			pid_params->preError = pid_params->err;
			pid_params->isFirstCompute = false;
		}
		pid_params->D_Part = pid_params->KD*(pid_params->err-pid_params->preError)/dt;
		if(pid_params->D_Part < pid_params->minDpart) pid_params->D_Part = pid_params->minDpart;
		if(pid_params->D_Part > pid_params->maxDpart) pid_params->D_Part = pid_params->maxDpart;
		pid_params->preError = pid_params->err;

		// Compute control signal and saturate it
		pid_params->U = pid_params->P_Part + pid_params->I_Part + pid_params->D_Part;
		if(pid_params->U < pid_params->minOut) pid_params->U = pid_params->minOut;
		if(pid_params->U > pid_params->maxOut) pid_params->U = pid_params->maxOut;

		return pid_params->U;
}
#elif PID_CONTROL_TYPE == 1
float pid_compute(pid_params_t *pid_params, float sp, float fb, float dt){
		// Save set point, feed back and error
		pid_params->sp = sp;
		pid_params->fb = fb;
		pid_params->err = sp-fb;

		// Compute alpha_part
		pid_params->alpha_part = 2*dt*pid_params->KP+pid_params->KI*dt*dt+2*pid_params->KD;
		// Compute beta_part
		pid_params->beta_part =	dt*dt*pid_params->KI-4*pid_params->KD-2*dt*pid_params->KP;
		// Compute gamma_part
		pid_params->gamma_part = 2*pid_params->KD;
		// Compute control signal and saturate it
		if(pid_params->isFirstCompute){
			pid_params->preError  = pid_params->err;
			pid_params->pre2Error = pid_params->preError;
			pid_params->isFirstCompute = false;
		}
		pid_params->U = (pid_params->alpha_part*pid_params->err+pid_params->beta_part*pid_params->preError+pid_params->gamma_part*pid_params->pre2Error+2*dt*pid_params->preOutput)/2*dt;
		if(pid_params->U < pid_params->minOut) pid_params->U = pid_params->minOut;
		if(pid_params->U > pid_params->maxOut) pid_params->U = pid_params->maxOut;

		pid_params->pre2Error = pid_params->preError;
		pid_params->preError = pid_params->err;
		return pid_params->U;
#endif
}

void pid_reset(pid_params_t *pid_params){
#if PID_CONTROL_TYPE == 0
			pid_params->isFirstCompute=true;
			pid_params->preIPart = 0;
			pid_params->preError = 0;
			pid_params->P_Part=0;
			pid_params->I_Part=0;
			pid_params->D_Part=0;
			pid_params->U=0;
#elif PID_CONTROL_TYPE == 1
			pid_params->isFirstCompute=true;
			pid_params-> preError  	= 0;
			pid_params-> pre2Error 	= 0;
			pid_params-> alpha_part = 0;
			pid_params-> beta_part 	= 0;
			pid_params-> gamma_part = 0;
			pid_params-> U=0;
#endif
}
