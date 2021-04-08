cmake_minimum_required(VERSION 3.0.2)
project(random_turtlesim_controller)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    geometry_msgs
    random_gen_x
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    random_gen_x
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(random_turtlesim_controller
    src/random_turtlesim_controller.cpp
)

add_dependencies(random_turtlesim_controller ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(random_turtlesim_controller
    ${catkin_LIBRARIES}
)