cmake_minimum_required(VERSION 3.0.2)
project(get_homogeneous_transform)

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

add_executable(get_homogeneous_transform
    src/get_homogeneous_transform.cpp
)

add_dependencies(get_homogeneous_transform ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(get_homogeneous_transform
    ${catkin_LIBRARIES}
)