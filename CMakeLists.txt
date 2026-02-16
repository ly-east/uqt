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

find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network)

# ===================================================================
# QtSingleApplication

set(UQT_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include/uqt)
set(UQT_SINGLETON_INCLUDE_DIR "${UQT_INCLUDE_DIR}/QtSingleApplication")

list(APPEND UQT_SINGLETON_SRC_FILE
  ${UQT_SINGLETON_INCLUDE_DIR}/qtlocalpeer.h
  ${UQT_SINGLETON_INCLUDE_DIR}/qtlockedfile.h
  ${UQT_SINGLETON_INCLUDE_DIR}/qtsingleapplication.h
  ${UQT_SINGLETON_INCLUDE_DIR}/qtsinglecoreapplication.h

  lib/QtSingleApplication/qtlocalpeer.cpp
  lib/QtSingleApplication/qtlockedfile.cpp
  lib/QtSingleApplication/qtsingleapplication.cpp
  lib/QtSingleApplication/qtsinglecoreapplication.cpp
)

if (WIN32)
  list(APPEND UQT_SINGLETON_SRC_FILE lib/QtSingleApplication/qtlockedfile_win.cpp)
elseif(UNIX)
  list(APPEND UQT_SINGLETON_SRC_FILE lib/QtSingleApplication/qtlockedfile_unix.cpp)
endif(WIN32)

# ===================================================================
# uqt

add_library(uqt SHARED
  lib/Filesystem/Browse.cpp
  lib/String/TitleLimitation.cpp
  lib/display.cpp
  ${UQT_SINGLETON_SRC_FILE}
)

target_compile_definitions(uqt PRIVATE UQT_LIBRARY)

target_include_directories(uqt PUBLIC
  ${UQT_INCLUDE_DIR}
  ${UQT_SINGLETON_INCLUDE_DIR}
)

target_link_libraries(uqt PRIVATE
  Qt6::Core
  Qt6::Widgets
  Qt6::Network
)

install(TARGETS uqt)

