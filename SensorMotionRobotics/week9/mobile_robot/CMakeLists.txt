cmake_minimum_required(VERSION 3.0.2)
project(mobile_robot)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    rospy
    urdf
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    rospy
    urdf
)

#############
### BUILD ###
#############

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(state_publisher
    src/state_publisher.cpp
)

add_dependencies(state_publisher ${${PROJECT_NAME}_EXPORTED_TARGETS}
    ${catkin_EXPORTED_TARGETS})

target_link_libraries(state_publisher
    ${catkin_LIBRARIES}
)