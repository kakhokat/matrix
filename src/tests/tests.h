#ifndef TESTS_H_
#define TESTS_H_

#include <check.h>

#include "./../s21_matrix.h"

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

void s21_suit_execution(Suite *suite, int *failed_count);

#endif  // TESTS_H_