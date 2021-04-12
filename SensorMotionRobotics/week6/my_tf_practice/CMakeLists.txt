cmake_minimum_required(VERSION 3.0.2)
project(my_tf_practice)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    tf
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    tf
)

#############
### BUILD ###
#############

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(my_tf_practice
    src/my_tf_practice.cpp
)

add_dependencies(my_tf_practice ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_tf_practice
    ${catkin_LIBRARIES}
)