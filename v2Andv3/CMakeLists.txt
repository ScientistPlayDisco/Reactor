cmake_minimum_required(VERSION 3.10)
project(v3)

set(CMAKE_CXX_STANDARD 14)

add_executable(v3 Acceptor.cpp Acceptor.h TcpConnection.cpp TcpConnection.h Eventloop.cpp Eventloop.h TestV2.cpp)