#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

template <typename T>
using Matrix = std::vector<std::vector<T>>;

template <typename T>
void print(Matrix<T> matrix, char delimiter = 0) {
  std::cout << "[";
  for (size_t i = 0; i < matrix.size(); i++) {
    for (size_t j = 0; j < matrix[i].size(); j++) {
      if (j == 0) {
        if (i == 0) {
          std::cout << "[";
        } else {
          std::cout << " [";
        }
      }

      if (j == matrix[i].size() - 1) {
        if (i == matrix.size() - 1) {
          std::cout << matrix[i][j] << "]";
        } else {
          std::cout << matrix[i][j] << "],\n";
        }
      } else {
        std::cout << matrix[i][j] << delimiter;
      }
    }
  }
  std::cout << "]\n";
}

#endif