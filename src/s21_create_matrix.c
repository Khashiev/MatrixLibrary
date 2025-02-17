#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = OK;

  if (rows < 1 || columns < 1) {
    flag = INCORRECT_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    flag = OK;
  }

  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (!result->matrix[i]) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
      }
    }
    flag = OK;
  }

  return flag;
}
