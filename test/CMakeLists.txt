cmake_minimum_required(VERSION 3.0)

# Test Dependencies
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        703bd9caab50b139428cea1aaff9974ebee5742e # release-1.10.0
)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        de6fe184a9ac1a06895cdd1c9b437f0a0bdf14ad # v2.13.4
)
FetchContent_MakeAvailable(googletest Catch2)

project(Test_Calc)
set(SOURCES Test.cpp)



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

# Options
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -fsanitize=address")

# Link runTests with what we want to test and the GTest and pthread library
add_executable(${PROJECT_NAME} WIN32 MACOSX_BUNDLE ${SOURCES})
target_link_libraries(
    ${PROJECT_NAME} 
    ${wxWidgets_LIBRARIES} 
    GTest::gtest_main 
    Threads::Threads
)

