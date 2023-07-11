/*
 * trajectory.h
 *
 *  Created on: Jul 2, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_TRAJECTORY_TRAJECTORY_H_
#define APPLICATION_MPC_TRAJECTORY_TRAJECTORY_H_

int generate_trajectory(float time[251],double x[251],double x_dot[251],double x_dot_dot[251],double y[251],double y_dot[251],double y_dot_dot[251],double z[251],double z_dot[251],double z_dot_dot[251],double psiInt[251]);

#endif /* APPLICATION_MPC_TRAJECTORY_TRAJECTORY_H_ */
