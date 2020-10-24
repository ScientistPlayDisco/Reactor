cmake_minimum_required(VERSION 3.10)
project(v4_threadPool)

set(CMAKE_CXX_STANDARD 14)

add_executable(v4_threadPool main.cpp Eventloop.h Eventloop.cpp TcpConnection.h TcpConnection.cpp TestV2.cpp TcpServer.h TcpServer.cpp TcpConnection.h)