cmake_minimum_required(VERSION 3.5)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
find_package(Qt5Core REQUIRED)

option(SHOW_MEMORY_LEAKS "Show memory leak information" OFF)
if(SHOW_MEMORY_LEAKS)
  add_definitions(-DSHOW_MEMORY_LEAKS)
endif()

add_subdirectory(lib)
add_subdirectory(src)
