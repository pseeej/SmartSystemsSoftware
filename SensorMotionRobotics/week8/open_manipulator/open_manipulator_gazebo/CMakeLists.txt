cmake_minimum_required(VERSION 3.0.2)
project(open_manipulator_gazebo)

# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    urdf
)

catkin_package(

)

#############
### BUILD ###
#############

include_directories(
    #include
    ${catkin_INCLUDE_DIRS}
)