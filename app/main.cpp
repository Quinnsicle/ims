#include <iostream>
#include <vector>

#include "inventory.h"
#include "item.h"

int main(int, char **) {
  std::cout << "Starting matrix:" << std::endl;
  Inventory inv = Inventory(5, 5);
  print(inv.matrix());
  std::cout << std::endl;

  std::vector<bool> itemShape = {1, 1};
  Item item = Item(1, itemShape);
  std::cout << "Place item:" << std::endl;
  inv.place(item, std::pair<int, int>{0, 0});
  print(inv.matrix());
  std::cout << std::endl;

  std::vector<std::vector<bool>> itemShape2 = {{0, 1}, {1, 1}};
  // std::vector<std::vector<bool>> itemShape2 = {{0, true},{true, true}};
  std::cout << "Place item:" << std::endl;
  Item item2 = Item(2, itemShape2);
  inv.place(item2, std::pair<int, int>{1, 0});
  print(inv.matrix());
  std::cout << std::endl;

  std::cout << "Remove item " << item2.id() << std::endl;
  inv.remove(item2);
  print(inv.matrix());
  std::cout << std::endl;

  std::cout << "Remove item " << item.id() << std::endl;
  inv.remove(item);
  print(inv.matrix());
  std::cout << std::endl;
};
