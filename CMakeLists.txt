cmake_minimum_required(VERSION 3.16)

project(uqt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core GUI)
find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(uqt SHARED
  uqt_global.h
  display.cpp
  display.h
)

target_link_libraries(uqt PRIVATE Qt6::Core Qt6::Widgets)

target_compile_definitions(uqt PRIVATE UQT_LIBRARY)
