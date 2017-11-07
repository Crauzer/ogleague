cmake_minimum_required(VERSION 2.8)
if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")
endif()
add_subdirectory(dep)
add_library(oglib STATIC
oglib/file/inibin.cpp
oglib/file/initext.cpp
)
target_include_directories(oglib PUBLIC "${CMAKE_CURRENT_LIST_DIR}")
target_link_libraries(oglib dep)
