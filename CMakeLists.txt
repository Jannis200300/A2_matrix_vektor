cmake_minimum_required(VERSION 3.29)
project(A2_matrix_vektor C)

set(CMAKE_C_STANDARD 90)

add_executable(A2_matrix_vektor
        A2_matrix_vektor.c)

add_compile_options(Praktikum5 -ansi -std=c90 -pedantic -pedantic-errors -Wall -Wextra -Werror -Wconversion)
