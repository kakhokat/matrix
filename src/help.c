#include "help.h"

int _is_correct_matrix(matrix_t *A) {
  int result = 1;
  if (A == NULL) {
    result = 0;
  } else if (A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    result = 0;
  }
  return result;
}

int _is_equal_size(matrix_t *A, matrix_t *B) {
  int result = NOT_EQUAL_SIZE;
  if (A->rows == B->rows && A->columns == B->columns) {
    result = EQUAL_SIZE;
  }
  return result;
}

void _mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  for (int i = 0; i < result->rows; i++) {
    for (int j = 0; j < result->columns; j++) {
      result->matrix[i][j] = 0;
      for (int k = 0; k < B->rows; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }
}
void _mult_number(matrix_t *A, double number, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }
}

void _transpose(matrix_t *A, matrix_t *result) {
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }
}

void _calc_complements(matrix_t *A, matrix_t *result) {
  // result->matrix[0][0] = A->matrix[0][0];
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      matrix_t *minor_matrix = _create_minor(A, i, j);  // 1, i+1
      double det = 0;
      s21_determinant(minor_matrix, &det);
      result->matrix[i][j] = pow(-1, i + j) * det;
      s21_remove_matrix(minor_matrix);
      free(minor_matrix);   //
      minor_matrix = NULL;  //
    }
  }
}

double _determinant(matrix_t *A) {
  double result = 0;
  if (A->rows == 2) {
    result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    for (int j = 0; j < A->columns; j++) {
      matrix_t *minor_matrix = _create_minor(A, 0, j);  // 1, i+1
      result += pow(-1, j) * A->matrix[0][j] * _determinant(minor_matrix);
      s21_remove_matrix(minor_matrix);
      free(minor_matrix);  //
      minor_matrix = NULL;
    }
  }
  return result;
}

int _invert_matrix(matrix_t *A, matrix_t *result) {
  int status_code = OK;
  double det = _determinant(A);
  if (det == 0) {
    status_code = CALCULATION_ERROR;
    s21_remove_matrix(result);
  }
  if (status_code == OK) {
    _calc_complements(A, result);
    //
    matrix_t tmp;
    s21_create_matrix(A->rows, A->columns, &tmp);
    _copy_matrix(result, &tmp);
    _transpose(&tmp, result);
    s21_remove_matrix(&tmp);
    //
    _mult_number(result, 1 / det, result);
  }
  return status_code;
}

matrix_t *_create_minor(matrix_t *A, int ex_i, int ex_j) {
  matrix_t *minor_matrix = calloc(1, sizeof(matrix_t));
  if (A != NULL && minor_matrix != NULL) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, minor_matrix) == OK) {
      for (int i = 0, minor_matrix_i = 0; i < A->rows; i++) {
        if (i != ex_i) {
          for (int j = 0, minor_matrix_j = 0; j < A->columns; j++) {
            if (j != ex_j) {
              minor_matrix->matrix[minor_matrix_i][minor_matrix_j] =
                  A->matrix[i][j];
              minor_matrix_j++;
            }
          }
          minor_matrix_i++;
        }
      }
    }
  }
  return minor_matrix;
}

void _copy_matrix(matrix_t *A, matrix_t *B) {
  if (A != NULL && B != NULL) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        B->matrix[i][j] = A->matrix[i][j];
      }
    }
  }
}

void fill_matrix(matrix_t *A, double start_value, double iteration_step) {
  if (A != NULL && A->matrix != NULL) {
    double value = start_value;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        A->matrix[i][j] = value;
        value += iteration_step;
      }
    }
  }
}