cmake_minimum_required(VERSION 3.31)
project(Reflection)

set(CMAKE_CXX_STANDARD 17)

add_executable(Reflection source/main.cpp
        include/Person.cpp
        include/Person.h
        include/Enum.h
        include/Type.hpp
        include/Factory.cpp
        include/Factory.h
        include/Property.cpp
        include/Property.h
)
