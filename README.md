# s21_matrix

## Оглавление
* [Введение](#Введение)
* [Реализованные функции](#Реализованные-функции)
* [Build](#build)
* [Tests](#tests)

## Введение

Своя библиотека для обработки числовых матриц на языке программирования Си.

## Реализованные функции

| Название | Функция                                                                            | 
| ------ |------------------------------------------------------------------------------------|
| int s21_create_matrix(int rows, int columns, matrix_t *result) | Создание матриц |
| void s21_remove_matrix(matrix_t *A) | Очистка матриц |
| int s21_eq_matrix(matrix_t *A, matrix_t *B) | Сравнение матриц |
| int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | Сложение матриц |
| int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | Вычитание  матриц |
| int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | Вычитание  матриц |
| int s21_mult_number(matrix_t *A, double number, matrix_t *result) | Умножение матрицы на число |
| int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) | Умножение двух матриц |
| int s21_transpose(matrix_t *A, matrix_t *result) | Транспонирование матрицы |
| int s21_calc_complements(matrix_t *A, matrix_t *result) | Матрица алгебраических дополнений |
| int s21_determinant(matrix_t *A, double *result) | Определитель матрицы |
| int s21_inverse_matrix(matrix_t *A, matrix_t *result) | Обратная матрица |




## Build
```
cd matrix/src
make
```

## Tests
Unit-тесты реализованы при помощи [Check](https://libcheck.github.io/check/), отчет о покрытии при помощи [LCOV](https://github.com/linux-test-project/lcov)
```
cd matrix/src
make test
```
Отчет о покрытии:
```
cd matrix/src
make gcov_report
```
