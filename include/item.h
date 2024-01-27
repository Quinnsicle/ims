#ifndef ITEM_H
#define ITEM_H

#include <vector>

#include "matrix.h"

class Item {
  std::size_t height;
  std::size_t width;
  Matrix<int> matrix;

  int itemID;

  void initialize_matrix();

 public:
  Item(int id);

  Item(int id, int dimension);

  Item(int id, Matrix<int> shape);

  Item(int id, std::vector<int> shape);

  Item(int id, std::vector<std::vector<bool>> shape);

  Item(int id, std::vector<bool> shape);

  void shape(Matrix<int> shape) { matrix = shape; }
  Matrix<int> shape() { return matrix; }

  const int id() const { return itemID; }
};

#endif