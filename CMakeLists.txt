cmake_minimum_required(VERSION 3.16)
project(vectorized_sql CXX)
set(CMAKE_CXX_STANDARD 20)
add_executable(query_engine src/main.cpp src/column_vector.cpp)
