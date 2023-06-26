/*
 * posision_control.h
 *
 *  Created on: Jun 25, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_POSISION_CONTROLLER_POSISION_CONTROL_H_
#define APPLICATION_MPC_POSISION_CONTROLLER_POSISION_CONTROL_H_

int pos_controller(float *roll_t,float *pitch_t,float *yaw_t,float *X_ref,float *X_dot_ref,float *X_dot_dot_ref,float *Y_ref,float *Y_dot_ref,float *Y_dot_dot_ref,float *Z_ref,float *Z_dot_ref,float *Z_dot_dot_ref,float *Psi_ref,float *states_u,float *states_v,float *states_w,float *states_x,float *states_y,float *states_z,float *states_phi,float *states_theta,float *states_psi,double *U1_callback, double *Phi_ref_callback,double *Theta_ref_callback);

#endif /* APPLICATION_MPC_POSISION_CONTROLLER_POSISION_CONTROL_H_ */
