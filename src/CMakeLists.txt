set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.c)

set(SOURCES ${SOURCES})
add_library(MainLib ${SOURCES})
add_dependencies(MainLib Sqlite3_lib)

add_executable(${BINARY}_run ${SOURCES})



target_link_libraries(${BINARY}_run PUBLIC Sqlite3_lib)

add_library(${BINARY}_lib STATIC ${SOURCES})

target_link_libraries(${BINARY}_lib PUBLIC Sqlite3_lib)
