cmake_minimum_required(VERSION 3.16)
project(c_plus_plus_playground)

set(CMAKE_CXX_STANDARD 14)

add_executable(c_plus_plus_playground main.cpp Person.cpp Person.h Tweeter.cpp Tweeter.h status.h Utility.cpp Utility.h Accum.h Resource.cpp Resource.h)