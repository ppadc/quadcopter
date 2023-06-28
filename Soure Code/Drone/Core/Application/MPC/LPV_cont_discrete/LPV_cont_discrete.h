/*
 * LPV_cont_discrete.h
 *
 *  Created on: Jun 26, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_LPV_CONT_DISCRETE_LPV_CONT_DISCRETE_H_
#define APPLICATION_MPC_LPV_CONT_DISCRETE_LPV_CONT_DISCRETE_H_

int lpv_cont_discrete(float *roll_t,float *pitch_t,float *yaw_t,float *states_u,float *states_v,float *states_w,float *states_p,float *states_q,float *states_r,float *states_phi,float *states_theta,float *states_psi,float *Omega_total,double Ad_matrix[6][6],double Bd_matrix[6][3],double Cd_matrix[3][6], double Dd_matrix[3][3]);

#endif /* APPLICATION_MPC_LPV_CONT_DISCRETE_LPV_CONT_DISCRETE_H_ */
