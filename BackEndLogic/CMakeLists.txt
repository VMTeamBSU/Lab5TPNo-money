set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.c *.o .exe)

set(SOURCES ${SOURCES})

add_library(BackEnd_lib STATIC ${SOURCES})