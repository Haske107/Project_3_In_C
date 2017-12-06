cmake_minimum_required(VERSION 3.8)
project(Project_3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Worker.h Scheduler.h Semaphore.h)
add_executable(Project_3 ${SOURCE_FILES})