cmake_minimum_required(VERSION 3.10)

project(neocalc VERSION 0.9)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR}/include/vendor)

set(SOURCES
  src/main.cpp
  src/neocalc/interface/interface.cpp
)

set(INCLUDE
  include/neocalc/interface/interface.hpp
  include/neocalc/math/math.hpp
)

add_executable(neocalc ${SOURCES})

target_include_directories(neocalc PRIVATE ${PROJECT_SOURCE_DIR}/include/vendor)
