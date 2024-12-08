cmake_minimum_required(VERSION 3.10)

# Set the project name
project(CircularBufferRateLimiter)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(rate_limiter main.cpp)