#ifndef SRC_S21_MATRIX_TEST_H
#define SRC_S21_MATRIX_TEST_H

#include <check.h>
#include <time.h>
#include <unistd.h>

#include "../s21_matrix.h"

Suite *suite_matrix_gather(void);
Suite *suite_create_matrix(void);
Suite *suite_transpose_matrix(void);
Suite *suite_eq_matrix(void);
Suite *suite_sum_matrix(void);
Suite *suite_sub_matrix(void);
Suite *suite_mult_matrix(void);
Suite *suite_mult_number_matrix(void);

Suite *suite_calc_complements(void);
Suite *suite_determinant(void);
Suite *suite_inverse_matrix(void);

void run_testcase(Suite *testcase);
double get_rand(double min, double max);

#endif  // SRC_S21_MATRIX_TEST_H