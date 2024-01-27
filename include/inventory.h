#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>

#include "item.h"

class Inventory {
  std::size_t height;
  std::size_t width;
  Matrix<int> m;

  std::pair<int, int> selectedItemUniqueID;
  std::pair<int, int> previousOrigin;

  void revert_location(std::pair<int, int> item);

  void matrix(Matrix<int> newMatrix);

  friend void swap(Inventory &a, Inventory &b) {
    using std::swap;
    swap(a.m, b.m);
  }

 public:
  Inventory();

  Inventory(int h, int w);

  Matrix<int> matrix();

  void clear();

  void remove(const Item &item);

  void remove(const int &item_id);

  void place(Item &item, std::pair<int, int> origin);
};

#endif