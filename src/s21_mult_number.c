#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag;

  if (!is_correct(A)) {
    flag = INCORRECT_MATRIX;
  } else if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    flag = MALLOC_FAILED;
  } else {
    flag = OK;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }

  return flag;
}