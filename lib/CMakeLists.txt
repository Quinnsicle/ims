add_library(ims_inventory inventory.cpp)
add_library(ims_item item.cpp)

target_include_directories(ims_inventory PUBLIC ../include)
target_include_directories(ims_item PUBLIC ../include)
