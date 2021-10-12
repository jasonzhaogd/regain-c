cmake_minimum_required(VERSION 3.20)
project(regain_c C)

set(CMAKE_C_STANDARD 11)

add_executable(regain_c main.c)
add_executable(guess_number 00_basic/guess_number.c)
