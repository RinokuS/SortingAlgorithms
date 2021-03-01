cmake_minimum_required(VERSION 3.17)
project(SAComparison)

set(CMAKE_CXX_STANDARD 17)

add_executable(SAComparison main.cpp bubble_sort.h selection_sort.h insertion_sort.h counting_sort.h radix_sort.h quick_sort.h merge_sort.h heap_sort.h data_creator.h)