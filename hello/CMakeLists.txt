add_library(hello SHARED hello.c)
add_compile_options(-D_FILE_OFFSET_BITS=64)