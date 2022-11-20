cmake_minimum_required(VERSION 3.14)

# Project
project(Test_Calc)
set(SOURCES Test.cpp)

# WxWidget
find_package(wxWidgets 3.1.4 REQUIRED)
include(${wxWidgets_USE_FILE})

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -fsanitize=address")
enable_testing()

# PThread
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

# Test Dependencies
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})
target_link_libraries(
    ${PROJECT_NAME} 
    ${wxWidgets_LIBRARIES} 
    GTest::gtest_main 
    Threads::Threads
)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})

