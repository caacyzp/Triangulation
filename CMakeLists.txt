cmake_minimum_required(VERSION 3.0.0)
project(Triangulation VERSION 0.1.0)


SET(MSYS2_INCLUDE "C:/msys64/mingw64/include")
  
add_executable(Triangulation 
triangulation.cpp
main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
