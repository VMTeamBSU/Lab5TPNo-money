cmake_minimum_required(VERSION 3.10)
project(AirCabSoft)

set(CMAKE_CXX_STANDARD 14)


if (WIN32)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ../../bin)
endif (WIN32)

add_subdirectory(lib/sqlite3)
add_subdirectory(src)



if (UNIX)
    add_subdirectory(tst)
    add_subdirectory(lib/googletest)
endif (UNIX)

