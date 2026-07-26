cmake_minimum_required(VERSION 3.16)
project(LinkStackDemo C CXX)

# 设置C标准
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 头文件目录
include_directories(include)

# 添加源码
add_executable(linkstack_demo
    src/main.c
    src/LinkStack.c
    include/LinkStack.h
)
