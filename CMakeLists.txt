cmake_minimum_required(VERSION 3.13)


set(CMAKE_C_FLAGS
		"-ggdb -Wall -Wextra -pedantic -std=gnu11 -Wno-unused-parameter")

project (VUFUSE3_TEST)
set(CMAKE_SHARED_LIBRARY_PREFIX "vufuse3")
add_subdirectory (hello)
