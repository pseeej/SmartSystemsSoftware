cmake_minimum_required(VERSION 3.0.2)
project(my_client)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    my_server
)

catkin_package(
    CATKIN_DEPENDS
    roscpp
)

###########
## BUILD ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(my_client
    src/my_client.cpp
)

add_dependencies(my_client ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_client
    ${catkin_LIBRARIES}
)
