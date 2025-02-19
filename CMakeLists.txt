cmake_minimum_required(VERSION 3.27)
project(GameOfLife)

set(CMAKE_PREFIX_PATH "D:/Qt/6.8.2/mingw_64/lib/cmake")

find_package(Qt6 REQUIRED COMPONENTS Gui Core Widgets)

find_package(Vulkan REQUIRED)

set(CMAKE_CXX_STANDARD 23)

add_executable(GameOfLife main.cpp
        Simulation.cpp
        Simulation.h
        Cell.cpp
        Cell.h)
target_link_libraries(GameOfLife Qt6::Gui Qt6::Core Qt6::Widgets)