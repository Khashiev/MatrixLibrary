#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag;

  if (!is_correct(A) || !is_correct(B)) {
    flag = INCORRECT_MATRIX;
  } else if (!is_similar(A, B)) {
    flag = CALC_ERROR;
  } else if (s21_create_matrix(A->rows, A->columns, result) != OK) {
    flag = MALLOC_FAILED;
  } else {
    flag = OK;

    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }

  return flag;
}
