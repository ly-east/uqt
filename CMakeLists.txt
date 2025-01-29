cmake_minimum_required(VERSION 3.16)

# ref: https://cmake.org/cmake/help/latest/prop_tgt/MSVC_RUNTIME_LIBRARY.html
if (POLICY CMP0091)
  cmake_policy(SET CMP0091 NEW)
endif (POLICY CMP0091)

project(uqt LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(WIN32)
  if(MSVC)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
  endif(MSVC)
endif(WIN32)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_library(uqt SHARED
  uqt_global.h
  display.cpp
  display.h
)

target_link_libraries(uqt PRIVATE Qt6::Core Qt6::Widgets)

target_compile_definitions(uqt PRIVATE UQT_LIBRARY)
