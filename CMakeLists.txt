cmake_minimum_required(VERSION 3.2)
project(CompileTimeRandom)

if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "Build type is default defined as Release. change it by define -DCMAKE_BUILD_TYPE=Debug as param to cmake")
    set(CMAKE_BUILD_TYPE Release)
endif()

include(env/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

set(CMAKE_CXX_STANDARD 17)

add_executable(${CMAKE_PROJECT_NAME}
  src/Main.cpp
  src/CompileTimeRandom.cpp
  src/CompileTimeRandom.h
        src/EncrypedString.h)

target_link_libraries(${CMAKE_PROJECT_NAME} ${CONAN_LIBS})

# Tests
set(TEST_FILES
  	src/CompileTimeRandom.cpp
  	src/CompileTimeRandom.h
	tests/CompileTimeRandomTest.cpp
	tests/Main.cpp
        src/EncrypedString.h)
set(TEST_NAME ${CMAKE_PROJECT_NAME}Test)

add_executable(${TEST_NAME} ${TEST_FILES})
target_link_libraries(${TEST_NAME} ${CONAN_LIBS})

