#include "item.h"

void Item::initialize_matrix() {
  matrix = Matrix<int>(height, std::vector<int>(width, 0));
}

Item::Item(int id) : height(1), width(1), itemID(id) {
  std::vector<int> tmp;
  tmp.assign(width, itemID);
  matrix.assign(height, tmp);
}

Item::Item(int id, int dimension)
    : height(dimension), width(dimension), itemID(id) {
  std::vector<int> row;
  row.assign(width, itemID);
  matrix.assign(height, row);
}

Item::Item(int id, Matrix<int> shape)
    : height(shape.size()), width(shape[0].size()), itemID(id) {
  matrix = shape;
}

Item::Item(int id, std::vector<int> shape)
    : height(1), width(shape.size()), itemID(id) {
  matrix = {shape};
  for (int i = 1; i < height; i++) {
    matrix.push_back(std::vector<int>(width, 0));
  }
}

Item::Item(int id, std::vector<std::vector<bool>> shape)
    : height(shape.size()), width(shape[0].size()), itemID(id) {
  initialize_matrix();
  for (std::size_t i = 0; i < shape.size(); i++) {
    for (std::size_t j = 0; j < shape[i].size(); j++) {
      matrix[i][j] = shape[i][j] ? itemID : 0;
    }
  }
}

Item::Item(int id, std::vector<bool> shape)
    : height(1), width(shape.size()), itemID(id) {
  initialize_matrix();
  for (std::size_t i = 0; i < shape.size(); i++) {
    matrix[0][i] = shape[i] ? itemID : 0;
  }
}
