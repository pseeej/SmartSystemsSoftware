cmake_minimum_required(VERSION 3.0.2)
project(pub_major)

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

###############
#### BUILD ####
###############

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(pub_major
    src/pub_major.cpp
)

add_dependencies(pub_major ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(pub_major
    ${catkin_LIBRARIES}
)