cmake_minimum_required (VERSION 2.6)

project (dcp)

set (CMAKE_CXX_STANDARD 11)

add_executable(search_k src/search_k_in_array.cpp)

add_executable(serialize src/serialize_tree.cpp)

add_executable(smallest_int src/smallest_positive_integer.cpp)

add_executable(function_inception src/function_inception.cpp)

add_executable(exclusive_prod src/exclusive_product.cpp)