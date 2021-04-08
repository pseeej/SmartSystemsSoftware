cmake_minimum_required(VERSION 3.0.2)
project(my_subscriber_class)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    my_publisher_class
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
    my_publisher_class
)

###############
#### BUILD ####
###############

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(my_subscriber_class
    src/my_subscriber_class.cpp
)

add_dependencies(my_subscriber_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_subscriber_class
    ${catkin_LIBRARIES}
)