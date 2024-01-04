#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int flag;

  if (!is_correct(A)) {
    flag = INCORRECT_MATRIX;
  } else if (A->rows != A->columns) {
    flag = CALC_ERROR;
  } else {
    flag = OK;
    double det = 0;
    int code = s21_determinant(A, &det);

    if (fabs(det) == 0 || code) {
      return CALC_ERROR;
    }

    matrix_t adj = {0};
    if (s21_calc_complements(A, &adj)) {
      return MALLOC_FAILED;
    }

    matrix_t transp = {0};
    if (s21_transpose(&adj, &transp)) {
      return MALLOC_FAILED;
    }

    if (s21_create_matrix(A->rows, A->columns, result)) {
      return MALLOC_FAILED;
    }

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = transp.matrix[i][j] / det;
      }
    }

    s21_remove_matrix(&transp);
    s21_remove_matrix(&adj);
  }

  return flag;
}
