/*
 * open_loop_new_states.h
 *
 *  Created on: Jul 7, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_OPEN_LOOP_NEW_STATES_OPEN_LOOP_NEW_STATES_H_
#define APPLICATION_MPC_OPEN_LOOP_NEW_STATES_OPEN_LOOP_NEW_STATES_H_

int open_new_loop_states(double states[12], double *omega_total,double *U1, double *U2,double *U3,double *U4,double new_states_r[12],double states_ani_r[5][6],double U_ani_r[5][4]);

#endif /* APPLICATION_MPC_OPEN_LOOP_NEW_STATES_OPEN_LOOP_NEW_STATES_H_ */
