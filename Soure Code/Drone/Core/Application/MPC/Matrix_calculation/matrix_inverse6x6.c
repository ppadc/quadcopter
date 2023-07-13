/*
 * matrix_inverse6x6.c
 *
 *  Created on: Jul 14, 2023
 *      Author: nguye
 */

#include<stdio.h>
#include<math.h>

void matrix_invert_6x6(double a[6][6], int k, double return_callback[6][6]);
double determinant_6x6(double a[6][6], int k);
void cofactor_6x6(double num[6][6], int f, double return_callback[6][6]);
void transpose_6x6(double num[6][6], double fac[6][6], int r, double return_callback[6][6]);

void matrix_invert_6x6(double a[6][6], int k, double return_callback[6][6]) {
    double d;
    d = determinant_6x6(a, k);
    if (d == 0) {
//        printf("\nInverse of Entered Matrix is not possible\n");
    } else {
        cofactor_6x6(a, k, return_callback);
    }
}

double determinant_6x6(double a[6][6], int k) {
    double det = 0;
    double b[6][6];
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
            det = det + s * (a[0][c] * determinant_6x6(b, k - 1));
            s = -1*s;
        }
    }

    return (det);
}

void cofactor_6x6(double num[6][6], int f, double return_callback[6][6]) {
    double b[6][6], fac[6][6];
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
            fac[q][p] = pow(-1, q + p) * determinant_6x6(b, f - 1);
        }
    }
    transpose_6x6(num, fac, f,return_callback);
}

void transpose_6x6(double num[6][6], double fac[6][6], int r, double return_callback[6][6]) {
    int i, j;
    double b[6][6], inverse[6][6], d;

    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            b[i][j] = fac[j][i];
        }
    }
    d = determinant_6x6(num, r);
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
