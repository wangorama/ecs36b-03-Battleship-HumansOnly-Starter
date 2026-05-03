cmake_minimum_required(VERSION 3.28)
project(ECS36BBattleShipHumansOnly) # make sure to update

set(CMAKE_CXX_STANDARD 23)
set(CXX_WARNINGS -Wall -Werror -Wextra)

# make sure to update
set(SRC_LIB_NAME ECS36BBattleShipHumansOnlyLib)
set(EXE_NAME ECS36BBattleShipHumansOnlyExe)
set(TESTING_NAME ECS36BBattleShipHumansOnlyTests)

add_subdirectory(src)
add_subdirectory(testing)
