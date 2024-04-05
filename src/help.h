#ifndef HELP_H_
#define HELP_H_

#include "s21_matrix.h"

#define EQUAL_SIZE 1
#define NOT_EQUAL_SIZE 0

/**
 * @brief check if matrices have equal size
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @return 0 - NOT_EQUAL_SIZE, 1 - EQUAL_SIZE
 */
int _is_equal_size(matrix_t *A, matrix_t *B);

/**
 * @brief check if matrix is correct
 * @param A pointer to matrix
 * @return 0 - OK or 1 - Error, incorrect matrix
 */
int _is_correct_matrix(matrix_t *A);

/**
 * @brief matrix multiplication helper
 * @param A pointer to matrix A
 * @param B pointer to matrix B
 * @param result pointer to matrix
 */
void _mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief matrix multiplication by number helper
 * @param A pointer to matrix
 * @param number number
 * @param result pointer to matrix
 */
void _mult_number(matrix_t *A, double number, matrix_t *result);
/**
 * @brief transpose helper
 * @param A pointer to matrix
 * @param result pointer to matrix
 */
void _transpose(matrix_t *A, matrix_t *result);

/**
 * @brief calc complements helper
 * @param A pointer to matrix
 * @param result pointer to matrix
 */
void _calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief determinant helper
 * @param A pointer to matrix
 * @param result pointer to result
 */
double _determinant(matrix_t *A);

int _invert_matrix(matrix_t *A, matrix_t *result);

/**
 * @brief create minor
 * @param A pointer to source matrix
 * @param result pointer to result matrix
 * @param i excluded row
 * @param j excluded column
 */
matrix_t *_create_minor(matrix_t *A, int i, int j);

void _copy_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief fill matrix with values
 * @param A pointer to matrix
 * @param start_value start value
 * @param iteration_step value step
 */
void fill_matrix(matrix_t *A, double start_value, double iteration_step);

#endif  // HELP_H_