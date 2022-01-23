#include <algorithm>
#include <cctype>
#include <iostream>
#include <stack>
#include <utility>
#include <vector>

#include "inventory.h"
#include "item.h"

template <typename T> void print_matrix(std::vector<std::vector<T>> matrix) {
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
        std::cout << matrix[i][j] << ", ";
      }
    }
  }
  std::cout << "]\n";
}

int main(int, char **) {
  std::cout << "Starting matrix:" << std::endl;
  Inventory inv = Inventory(5, 5);
  print_matrix(inv.get_matrix());
  std::cout << std::endl;

  std::vector<bool> itemShape = {1, 1};
  Item item = Item(1, itemShape);
  std::cout << "Place item:" << std::endl;
  inv.place(item, std::pair<int, int>{0, 0});
  print_matrix(inv.get_matrix());
  std::cout << std::endl;

  std::vector<std::vector<bool>> itemShape2 = {{0, 1}, {1, 1}};
  // std::vector<std::vector<bool>> itemShape2 = {{0, true},{true, true}};
  std::cout << "Place item:" << std::endl;
  Item item2 = Item(2, itemShape2);
  inv.place(item2, std::pair<int, int>{1, 0});
  print_matrix(inv.get_matrix());
  std::cout << std::endl;

  std::cout << "Remove item " << item2.id() << std::endl;
  inv.remove(item2);
  print_matrix(inv.get_matrix());
  std::cout << std::endl;

  std::cout << "Remove item " << item.id() << std::endl;
  inv.remove(item);
  print_matrix(inv.get_matrix());
  std::cout << std::endl;
}
