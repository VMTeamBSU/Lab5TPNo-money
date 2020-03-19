set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES ${SOURCES})

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_executable(${BINARY}_run ${SOURCES})

add_library(${BINARY}_lib STATIC ${SOURCES})