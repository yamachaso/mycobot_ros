cmake_minimum_required(VERSION 3.0.2)
project(mycobot_real_robot)


find_package(catkin REQUIRED COMPONENTS
  controller_manager
  hardware_interface
  roscpp
  rospy
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  # The packages in CATKIN_DEPENDS MUST be declared in pacakge.xml
  CATKIN_DEPENDS controller_manager hardware_interface roscpp rospy std_msgs
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(mycobot_control src/mycobot_control.cpp src/mycobot_hw.cpp)
target_link_libraries(mycobot_control
  ${catkin_LIBRARIES}
)

catkin_install_python(PROGRAMS
  scripts/mycobot_hw_interface.py
  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})
