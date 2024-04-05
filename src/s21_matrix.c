#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status_code = OK;
  if (result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  } else if (rows < 1 || columns < 1) {
    result->matrix = NULL;
    status_code = INCORRECT_MATRIX_ERROR;
  }
  if (status_code == OK) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
  }
  return status_code;
}

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      if (A->matrix[i] != NULL) {
        free(A->matrix[i]);
      }
    }
    free(A->matrix);
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (_is_correct_matrix(A) && _is_correct_matrix(B) && _is_equal_size(A, B)) {
    for (int i = 0; i < A->rows && result == SUCCESS; i++) {
      for (int j = 0; j < A->columns && result == SUCCESS; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-6) {
          result = FAILURE;
        }
      }
    }
  } else {
    result = FAILURE;
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || !_is_correct_matrix(B) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  } else if (_is_equal_size(A, B)) {
    status_code = s21_create_matrix(A->rows, A->columns, result);
    if (status_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  } else {
    status_code = CALCULATION_ERROR;
  }
  return status_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || !_is_correct_matrix(B) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  } else if (_is_equal_size(A, B)) {
    status_code = s21_create_matrix(A->rows, A->columns, result);
    if (status_code == OK) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  } else {
    status_code = CALCULATION_ERROR;
  }
  return status_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  } else {
    status_code = s21_create_matrix(A->rows, A->columns, result);
    if (status_code == OK) {
      _mult_number(A, number, result);
    }
  }
  return status_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || !_is_correct_matrix(B) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  } else if (A->columns == B->rows) {
    status_code = s21_create_matrix(A->rows, B->columns, result);
    if (status_code == OK) {
      _mult_matrix(A, B, result);
    }
  } else {
    status_code = CALCULATION_ERROR;
  }
  return status_code;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  }
  if (status_code == OK) {
    status_code = s21_create_matrix(A->columns, A->rows, result);
    if (status_code == OK) {
      _transpose(A, result);
    }
  }
  return status_code;
}
//

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  }
  if (status_code == OK) {  //  && A->rows == A->columns
    status_code = s21_create_matrix(A->rows, A->columns, result);
    if (status_code == OK) {
      _calc_complements(A, result);
    }
  }
  return status_code;
}

int s21_determinant(matrix_t *A, double *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  } else if (A->rows != A->columns) {
    status_code = CALCULATION_ERROR;
  }
  if (status_code == OK) {
    *result = A->matrix[0][0];
    if (A->rows > 1) {
      *result = _determinant(A);
    }
  }
  return status_code;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status_code = OK;
  if (!_is_correct_matrix(A) || result == NULL) {
    status_code = INCORRECT_MATRIX_ERROR;
  }
  if (status_code == OK) {
    if (A->rows != A->columns) {
      status_code = CALCULATION_ERROR;
    } else {
      status_code = s21_create_matrix(A->rows, A->columns, result);
    }
    if (status_code == OK) {
      if (A->rows == 1) {
        result->matrix[0][0] = 1 / A->matrix[0][0];
      } else {
        status_code = _invert_matrix(A, result);
      }
    }
  }
  return status_code;
}
