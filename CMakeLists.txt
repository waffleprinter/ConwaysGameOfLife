cmake_minimum_required(VERSION 3.29)
project(ConwaysGameOfLife)

set(CMAKE_CXX_STANDARD 20)

add_executable(ConwaysGameOfLife src/main.cpp
        src/Cell.cpp
        headers/Cell.h
        src/Board.cpp
        headers/Board.h)

include_directories(headers c:/SFML/include)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(ConwaysGameOfLife ${SFML_LIBRARIES})
endif ()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

# Copy dlls to build directory
if (WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()
