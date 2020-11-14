cmake_minimum_required(VERSION 3.0.2)
project(simple_talker)

## Compile as C++11, supported in ROS Kinetic and newer
 add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
    std_msgs
   
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(simple_talker_node src/talker.cpp)

target_link_libraries(simple_talker_node
  ${catkin_LIBRARIES}
)
