cmake_minimum_required(VERSION 3.10)

project(acalc VERSION 0.8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)
include_directories(${PROJECT_SOURCE_DIR}/include/vendor)

set(SOURCES
  src/main.cpp
  src/acalc/interface/interface.cpp
)

set(INCLUDE
  include/acalc/interface/interface.hpp
  include/acalc/math/math.hpp
)

add_executable(acalc ${SOURCES})

target_include_directories(acalc PRIVATE ${PROJECT_SOURCE_DIR}/include/vendor)
