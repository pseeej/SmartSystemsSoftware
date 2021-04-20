cmake_minimum_required(VERSION 3.0.2)
project(eigen_practice)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
)

#############
### BUILD ###
#############

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(eigen_practice
    src/eigen_practice.cpp
)

add_dependencies(eigen_practice ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(eigen_practice
    ${catkin_LIBRARIES}
)