cmake_minimum_required(VERSION 3.0.2)
project(random_gen_x)

add_compile_options(-O -Wall -std=c++14 -fpermissive)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    std_msgs
    roscpp
    message_generation
)

add_message_files(
    DIRECTORY msg
    FILES
    control_msg.msg
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

add_executable(random_gen_x
    src/random_gen_x.cpp
)

add_dependencies(random_gen_x ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(random_gen_x
    ${catkin_LIBRARIES}
)