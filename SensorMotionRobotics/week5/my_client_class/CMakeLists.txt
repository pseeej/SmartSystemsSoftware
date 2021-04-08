cmake_minimum_required(VERSION 3.0.2)
project(my_client_class)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    my_server_class
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

add_executable(my_client_class
    src/my_client_class.cpp
)

add_dependencies(my_client_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_client_class
    ${catkin_LIBRARIES}
)
