cmake_minimum_required(VERSION 3.1)

project(eng)

set(PROJECT_SOURCE_DIR "../src/")

#set(HEADERS)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp)

add_executable(eng.o ${SOURCES})
