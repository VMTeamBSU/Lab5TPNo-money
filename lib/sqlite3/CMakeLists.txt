set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.c  *.exe)

set(SOURCES ${SOURCES})

add_library(Sqlite3_lib STATIC ${SOURCES})
