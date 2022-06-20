cmake_minimum_required(VERSION 3.22)
project(yaftpd)

set(CMAKE_CXX_STANDARD 14)
# Set to a local copy of boost. Another approach is to use find_package
set(BOOST_ROOT /Users/jiab/boost_1_79_0)

include_directories(${BOOST_ROOT})

add_executable(yaftpd
        main.cpp tcp_connection.cpp tcp_connection.h ftpserver.cpp ftpserver.h utils.h)
