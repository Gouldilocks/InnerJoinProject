cmake_minimum_required(VERSION 3.12)
project(program3)

set(CMAKE_CXX_STANDARD 17)

add_executable(program3 main.cpp functions.cpp functions.h)

configure_file("Results.csv" "Results.csv")
configure_file("UsersTable.csv" "UsersTable.csv")
configure_file("CarsTable.csv" "CarsTable.csv")