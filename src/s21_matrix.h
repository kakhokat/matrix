#ifndef S21_MATRIX_H_
#define S21_MATRIX_H_

/**
 * @brief struct of matrix
 * @param matrix pointer to matrix
 * @param rows number of rows
 * @param columns number of columns
 */
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

#include <math.h>
// #include <stdarg.h>
// #include <stdio.h>
#include <stdlib.h>

#include "help.h"

// STATUS_CODE:
#define OK 0
#define INCORRECT_MATRIX_ERROR 1
#define CALCULATION_ERROR 2

/**
 * @brief create matrix
 * @param rows number of rows
 * @param columns number of columns
 * @param result pointer to matrix
 * @return 0 - OK or 1 - Error, incorrect matrix
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief remove matrix
 * @param A pointer to matrix
 * @return 0 - OK or 1 - Error
 */
void s21_remove_matrix(matrix_t *A);

#define SUCCESS 1
#define FAILURE 0
/**
 * @brief matrix comparison
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @return 0 - FAILURE or 1 - SUCCESS
 * @note The matrices A, B are equal |A = B| if they have the same dimensions
 * and the corresponding elements are identical, thus for all i and j: A(i,j) =
 * B(i,j)
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief matrix addition
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @param result pointer to matrix result (result = A + B)
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief matrix subtraction
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @param result pointer to matrix result (result = A - B)
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief matrix multiplication by number
 * @param A pointer to matrix A
 * @param number number
 * @param result pointer to matrix result (result = A * number)
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief matrix multiplication
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @param result pointer to matrix result (result = A * B)
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief matrix transpose
 * @param A pointer to matrix A
 * @param result pointer to matrix result
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief Minor of matrix and matrix of algebraic complements
 * @param A pointer to matrix A
 * @param result pointer to matrix result
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief Determinant of matrix
 * @param A pointer to matrix A
 * @param result pointer to result
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief Inverse matrix
 * @param A pointer to matrix A
 * @param result pointer to matrix result
 * @return 0 - OK, 1 - Error, incorrect matrix, 2 - Calculation error
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#define S21_ACCURACY 6

#endif  // S21_MATRIX_H_