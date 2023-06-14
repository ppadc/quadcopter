/*
 * rotation_matrix.h
 *
 *  Created on: May 27, 2023
 *      Author: nguye
 */

#ifndef APPLICATION_MPC_ROTATIONAL_MATRIX_ROTATIONAL_MATRIX_H_
#define APPLICATION_MPC_ROTATIONAL_MATRIX_ROTATIONAL_MATRIX_H_

#include <stdint.h>
#include <stdbool.h>
#include "timer.h"
#include "bno055.h"

typedef struct{
	float rotational_matrix[3][3];
}rotational_t;

#endif /* APPLICATION_MPC_ROTATIONAL_MATRIX_ROTATIONAL_MATRIX_H_ */
