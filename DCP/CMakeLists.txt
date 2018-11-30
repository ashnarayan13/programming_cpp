cmake_minimum_required (VERSION 2.6)

project (dcp)

set (CMAKE_CXX_STANDARD 11)

add_executable(search_k src/search_k_in_array.cpp)

add_executable(serialize src/serialize_tree.cpp)

add_executable(smallest_int src/smallest_positive_integer.cpp)

add_executable(function_inception src/function_inception.cpp)

add_executable(exclusive_prod src/exclusive_product.cpp)

add_executable(xor_ll src/xor_ll.cpp)

add_executable(decode src/decode.cpp)

add_executable(unival_tree src/unival_tree.cpp)

add_executable(non_adjacent_sum src/non_adjacent_sum.cpp)

add_executable(sleep_ms src/sleep_ms.cpp)

add_executable(trie_autosearch src/trie_autosearch.cpp)

add_executable(staircase src/staircase.cpp)

add_executable(monte_carlo_pi src/monte_carlo_pi.cpp)

add_executable(random_number src/random_number.cpp)

add_executable(stack src/stack.cpp)

add_executable(max_sliding_window src/max_sliding_window.cpp)

add_executable(node_intersection src/node_intersection.cpp)

add_executable(scheduling src/scheduling.cpp)

add_executable(min_path src/min_path.cpp)

add_executable(min_cost_painting src/min_cost_painting.cpp)