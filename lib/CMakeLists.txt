# QtSingleApplication

set(UQT_SINGLETON_INCLUDE_DIR "../include/QtSingleApplication")

list(APPEND UQT_SINGLETON_SRC_FILE
  ${UQT_SINGLETON_INCLUDE_DIR}/qtlocalpeer.h
  ${UQT_SINGLETON_INCLUDE_DIR}/qtlockedfile.h
  ${UQT_SINGLETON_INCLUDE_DIR}/qtsingleapplication.h
  ${UQT_SINGLETON_INCLUDE_DIR}/qtsinglecoreapplication.h

  QtSingleApplication/qtlocalpeer.cpp
  QtSingleApplication/qtlockedfile.cpp
  QtSingleApplication/qtsingleapplication.cpp
  QtSingleApplication/qtsinglecoreapplication.cpp
)

if (WIN32)
  list(APPEND UQT_SINGLETON_SRC_FILE QtSingleApplication/qtlockedfile_win.cpp)
elseif(UNIX)
  list(APPEND UQT_SINGLETON_SRC_FILE QtSingleApplication/qtlockedfile_unix.cpp)
endif(WIN32)

# uqt

add_library(uqt SHARED
  display.cpp
  ${UQT_SINGLETON_SRC_FILE}
)

target_compile_definitions(uqt PRIVATE UQT_LIBRARY)

target_include_directories(uqt PRIVATE
  ../include
  ${UQT_SINGLETON_INCLUDE_DIR}
)

target_link_libraries(uqt PRIVATE
  Qt6::Core
  Qt6::Widgets
  Qt6::Network
)

install(TARGETS uqt)
