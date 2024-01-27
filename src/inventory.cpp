#include "inventory.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

Inventory::Inventory() : height(2), width(2) {
  m.assign(height, std::vector<int>(width));
}

Inventory::Inventory(int h, int w) : height(h), width(w) {
  m.assign(height, std::vector<int>(width));
}

void Inventory::matrix(Matrix<int> newMatrix) { m = newMatrix; }

void Inventory::revert_location(std::pair<int, int> item) {}

Matrix<int> Inventory::matrix() { return m; }

void Inventory::clear() {
  Inventory empty;
  swap(empty, *this);
}

void Inventory::remove(const Item &item) {
  for (size_t row = 0; row < m.size(); row++) {
    for (size_t col = 0; col < m.size(); col++) {
      if (m[row][col] == item.id()) {
        m[row][col] = 0;
      }
    }
  }
}

void Inventory::remove(const int &item_id) {
  for (size_t row = 0; row < m.size(); row++) {
    for (size_t col = 0; col < m.size(); col++) {
      if (m[row][col] == item_id) {
        m[row][col] = 0;
      }
    }
  }
}

void Inventory::place(Item &item, std::pair<int, int> origin) {
  auto itemMatrix = item.shape();
  auto invMatrix = matrix();
  int x = origin.first;
  int y = origin.second;
  bool success = true;

  for (size_t itemRow = 0; itemRow < itemMatrix.size(); itemRow++) {
    for (size_t itemCol = 0; itemCol < itemMatrix[itemRow].size(); itemCol++) {
      if (itemMatrix[itemRow][itemCol] == 0) {
        continue;
      }
      if (invMatrix[y + itemRow][x + itemCol] != 0) {
        success = false;
        break;
      }
      invMatrix[y + itemRow][x + itemCol] = itemMatrix[itemRow][itemCol];
    }
    if (!success) {
      break;
    }
  }

  if (success) {
    matrix(invMatrix);
  }
}
