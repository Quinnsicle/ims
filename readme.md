## Description: 
This project is a grid based inventory management system similar to what is found in Escape from Tarkov. I plan to use this library to implement an inventory system in a game. The example main program showcases a 5x5 grid inventory. A 2x1 item is added to the inventory at location (0,0). Then an angled shaped item is added at location (1,0). The library also supports removing items by calling the remove function from the inventory class. Each item has a unique item id to keep track of each item.

### Author: Quinn O'Connor

### Requirements:
* CMake 3.0 or better
* A C++17 compatible compiler
* Git
* Doxygen (optional)

## Instructions:

### To Configure:
```bash
cmake -S . -B build
```

Add `-GNinja` if you have Ninja.

### To Build:
```bash
cmake --build build
```

### To Run:
```bash
./build/app/main
```

### Example Output:
![ims showcase](images/ims_showcase.png)
