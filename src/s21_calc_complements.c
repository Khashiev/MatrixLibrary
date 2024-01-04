#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag;

  if (!is_correct(A)) {
    flag = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    flag = CALC_ERROR;
  } else if (s21_create_matrix(A->columns, A->rows, result) != OK) {
    flag = MALLOC_FAILED;
  } else {
    flag = OK;
    adjoint(A, result);
  }

  return flag;
}