cmake_minimum_required(VERSION 3.24)
project(vaccine_order_processing)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

add_executable(vaccine_order_processing
        src/customer.cpp
        src/customer.hpp
        src/order.cpp
        src/order.hpp
        src/ordering.cpp
        src/ordering.hpp)
