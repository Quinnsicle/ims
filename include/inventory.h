#include <vector>

#include "item.h"

class Inventory {
  std::size_t height;
  std::size_t width;
  std::vector<std::vector<int>> matrix;

  std::pair<int, int> selectedItemUniqueID;
  std::pair<int, int> previousOrigin;

  void revert_location(std::pair<int, int> item);

  void set_matrix(std::vector<std::vector<int>> newMatrix);

 public:
  Inventory();

  Inventory(int h, int w);

  std::vector<std::vector<int>> get_matrix();

  void remove(const Item &item);

  void remove(const int &item_id);

  void place(Item &item, std::pair<int, int> origin);
};
