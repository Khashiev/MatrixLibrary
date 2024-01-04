#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

enum Flag { OK, INCORRECT_MATRIX, CALC_ERROR, MALLOC_FAILED };

#define SUCCESS 1
#define FAILURE 0

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// helpers
int is_similar(matrix_t *A, matrix_t *B);
int is_correct(matrix_t *A);
double det(double **matrix, int size);
void cofactor(double **matrix, double **new_matrix, int size, int row, int col);
void adjoint(matrix_t *A, matrix_t *result);

#endif  // SRC_S21_MATRIX_H