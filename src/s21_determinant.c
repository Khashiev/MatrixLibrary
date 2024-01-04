#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int flag;

  if (!is_correct(A)) {
    flag = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    flag = CALC_ERROR;
  } else {
    flag = OK;

    *result = det(A->matrix, A->rows);
  }

  return flag;
}
