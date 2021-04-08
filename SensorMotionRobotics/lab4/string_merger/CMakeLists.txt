cmake_minimum_required(VERSION 3.0.2)
project(string_merger)

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

###########
## Build ##
###########

include_directories(
    include
    ${catkin_INCLUDE_DIRS}
)

add_executable(string_merger
    src/string_merger.cpp
)
add_dependencies(string_merger ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(string_merger
    ${catkin_LIBRARIES}
)