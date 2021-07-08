cmake_minimum_required(VERSION 2.8.3)
project(drive_man)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
  std_msgs
)

## Generate services in the 'srv' folder
add_service_files(
   FILES
   DriveToTarget.srv
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES drive_man
#  CATKIN_DEPENDS message_generation roscpp std_msgs
#  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)


## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
add_executable(drive_bot src/drive_bot.cpp)
add_executable(drive_man src/drive_man.cpp)
add_executable(process_image src/process_image.cpp)



## Add cmake target dependencies of the executable
## same as for the library above
add_dependencies(drive_bot ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(drive_man ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(process_image ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
target_link_libraries(drive_bot
  ${catkin_LIBRARIES}
)

target_link_libraries(drive_man
  ${catkin_LIBRARIES}
)

target_link_libraries(process_image
  ${catkin_LIBRARIES}
)

