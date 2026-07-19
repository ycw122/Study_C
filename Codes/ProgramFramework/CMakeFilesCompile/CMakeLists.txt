cmake_minimum_required(VERSION 3.16)
project(CMakeDemo C CXX)

# 设置C标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 头文件目录
include_directories(include)

# 添加源码
add_executable(cmake_demo
    src/main.c
    src/LinkList.c
    include/LinkList.h
)
