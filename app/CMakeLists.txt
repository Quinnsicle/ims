add_executable(main main.cpp)

target_link_libraries(main PRIVATE ims_inventory)
target_link_libraries(main PRIVATE ims_item)