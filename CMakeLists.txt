cmake_minimum_required(VERSION 3.20)
project(superheroes_poo)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(superheroes_poo
        src/main.cpp
        include/Superheroe.h

)