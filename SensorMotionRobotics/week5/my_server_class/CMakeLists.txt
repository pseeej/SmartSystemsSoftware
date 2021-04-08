cmake_minimum_required(VERSION 3.0.2)
project(my_server_class)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    message_generation
)

#add_message_files(
    #DIRECTORY msg
    #FILES
    #my_msg.msg
#)

add_service_files(
    DIRECTORY srv
    FILES
    add_two_ints.srv
)

generate_messages(
    DEPENDENCIES
    std_msgs
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

add_executable(my_server_class
    src/my_server_class.cpp
)

add_dependencies(my_server_class ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(my_server_class
    ${catkin_LIBRARIES}
)
