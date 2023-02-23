cmake_minimum_required(VERSION 3.1)

project(eng)

set(PROJECT_SOURCE_DIR "../src/")
set(LINEARA ${PROJECT_SOURCE_DIR}/components/linearA.h ${PROJECT_SOURCE_DIR}/components/linearA.cpp)
set(OBJECTS ${PROJECT_SOURCE_DIR}/objects/objects.h ${PROJECT_SOURCE_DIR}/objects/objects.cpp)

set(SOURCES ${PROJECT_SOURCE_DIR}/main.cpp ${LINEARA} ${OBJECTS})

add_executable(eng ${SOURCES})
