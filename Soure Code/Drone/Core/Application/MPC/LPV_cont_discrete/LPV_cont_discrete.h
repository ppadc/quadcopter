/*
 * LPV_cont_discrete.h
 *
 *  Created on: Jun 26, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_LPV_CONT_DISCRETE_LPV_CONT_DISCRETE_H_
#define APPLICATION_MPC_LPV_CONT_DISCRETE_LPV_CONT_DISCRETE_H_

int lpv_cont_discrete(double *states_u,double *states_v,double *states_w,double *states_p,double *states_q,double *states_r,double *states_phi,double *states_theta,double *states_psi,float *Omega_total,double Ad_matrix[6][6],double Bd_matrix[6][3],double Cd_matrix[3][6], double Dd_matrix[3][3],double *x_dot_r,double *y_dot_r,double *z_dot_r,double *phi_r, double *phi_dot_r,double *theta_r,double *theta_dot_r,double *psi_r,double *psi_dot_r);

#endif /* APPLICATION_MPC_LPV_CONT_DISCRETE_LPV_CONT_DISCRETE_H_ */
