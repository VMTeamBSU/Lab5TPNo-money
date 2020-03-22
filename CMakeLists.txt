cmake_minimum_required(VERSION 3.10)
project(ExampleProject)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/sqlite3)
add_subdirectory(src)



if (UNIX)
    add_subdirectory(tst)
    add_subdirectory(lib/googletest)	
endif (UNIX)