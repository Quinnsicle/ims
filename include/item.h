#ifndef ITEM_H
#define ITEM_H

#include <vector>

class Item {
  std::size_t height;
  std::size_t width;
  std::vector<std::vector<int>> matrix;

  int itemID;

  void initialize_matrix();

public:
  Item(int id);

  Item(int id, int dimension);

  Item(int id, std::vector<std::vector<int>> shape);

  Item(int id, std::vector<int> shape);

  Item(int id, std::vector<std::vector<bool>> shape);

  Item(int id, std::vector<bool> shape);

  std::vector<std::vector<int>> get_matrix();

  int id();
};

#endif