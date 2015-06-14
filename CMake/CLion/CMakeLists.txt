cmake_minimum_required(VERSION 3.2)
project(CLion)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_PREFIX_PATH /usr/lib/x86_64-linux-gnu/cmake)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(CLion ${SOURCE_FILES})

qt5_use_modules(CLion Widgets)