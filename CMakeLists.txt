cmake_minimum_required(VERSION 3.13)


set(CMAKE_C_FLAGS
		"-Wall -D_FILE_OFFSET_BITS=64")

project (VUFUSE3_TEST)
set(CMAKE_SHARED_LIBRARY_PREFIX "vufuse3")
add_subdirectory (hello)
