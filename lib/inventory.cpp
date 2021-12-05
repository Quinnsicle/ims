#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#include "inventory.h"

void Inventory::revert_location(std::pair<int, int> item) {}

void Inventory::set_matrix(std::vector<std::vector<int>> newMatrix) {
  matrix = newMatrix;
}

Inventory::Inventory() : height(2), width(2) {
  matrix.assign(height, std::vector<int>(width));
}

Inventory::Inventory(int h, int w) : height(h), width(w) {
  matrix.assign(height, std::vector<int>(width));
}

std::vector<std::vector<int>> Inventory::get_matrix() { return matrix; }

void Inventory::remove(Item &item) {
  for (size_t row = 0; row < matrix.size(); row++) {
    for (size_t col = 0; col < matrix.size(); col++) {
      if (matrix[row][col] == item.id()) {
        matrix[row][col] = 0;
      }
    }
  }
}

void Inventory::place(Item &item, std::pair<int, int> origin) {
  auto itemMatrix = item.shape();
  auto invMatrix = get_matrix();
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
    set_matrix(invMatrix);
  }
}
