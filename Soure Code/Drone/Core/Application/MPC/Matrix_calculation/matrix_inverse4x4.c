/*
 * matrix_inverse4x4.c
 *
 *  Created on: Jul 4, 2024
 *      Author: nguye
 */

#include<stdio.h>
#include<math.h>

void matrix_invert_4x4(double a[4][4], int k, double return_callback[4][4]);
double determinant_4x4(double a[4][4], int k);
void cofactor_4x4(double num[4][4], int f, double return_callback[4][4]);
void transpose_4x4(double num[4][4], double fac[4][4], int r, double return_callback[4][4]);

void matrix_invert_4x4(double a[4][4], int k, double return_callback[4][4]) {
    double d;
    d = determinant_4x4(a, k);
    if (d == 0) {
//        printf("\nInverse of Entered Matrix is not possible\n");
    } else {
        cofactor_4x4(a, k, return_callback);
    }
}

double determinant_4x4(double a[4][4], int k) {
    double det = 0;
    double b[4][4];
    int i, j, m, n, c;
	float s = 1;
    if (k == 1) {
        return (a[0][0]);
    } else {
        det = 0;
        for (c = 0; c < k; c++) {
            m = 0;
            n = 0;
            for (i = 0; i < k; i++) {
                for (j = 0; j < k; j++) {
                	b[i][j] = 0;
                    if (i != 0 && j != c) {
                        b[m][n] = a[i][j];
                        if (n < (k - 2))
                            n++;
                        else {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            det = det + s * (a[0][c] * determinant_4x4(b, k - 1));
            s = -1*s;
        }
    }

    return (det);
}

void cofactor_4x4(double num[4][4], int f, double return_callback[4][4]) {
    double b[4][4], fac[4][4];
    int p, q, m, n, i, j;
    for (q = 0; q < f; q++) {
        for (p = 0; p < f; p++) {
            m = 0;
            n = 0;
            for (i = 0; i < f; i++) {
                for (j = 0; j < f; j++) {
                    if (i != q && j != p) {
                        b[m][n] = num[i][j];
                        if (n < (f - 2))
                            n++;
                        else {
                            n = 0;
                            m++;
                        }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant_4x4(b, f - 1);
        }
    }
    transpose_4x4(num, fac, f,return_callback);
}

void transpose_4x4(double num[4][4], double fac[4][4], int r, double return_callback[4][4]) {
    int i, j;
    double b[4][4], inverse[4][4], d;

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            b[i][j] = fac[j][i];
        }
    }
    d = determinant_4x4(num, r);
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            inverse[i][j] = b[i][j] / d;
        }
    }
    for (i = 0;i < r; i++)
    {
     for (j = 0;j < r; j++)
       {
    	 return_callback[i][j]=inverse[i][j];
        }
     }
}
