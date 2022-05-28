# 1. Overview
[![CI](https://github.com/yamachaso/mycobot_ros/actions/workflows/industrial_ci_action.yml/badge.svg)](https://github.com/yamachaso/mycobot_ros/actions/workflows/industrial_ci_action.yml)

Unofficial myCobot moveit repositiry

# 2. Environment
| item | value |
|---|---|
| OS | Ubuntu 20.04 |
| ROS | noetic |
| HW | myCobot 280 M5Stack

# 3. Installation
```
$ mkdir -p ~/catkin_ws/src
$ cd ~/catkin_ws/src
$ git clone https://github.com/yamachaso/mycobot_ros.git
$ rosdep install --from-paths . --ignore-src -r -y
$ cd ..
$ catkin build
```

# 4. Usage
* [Fake Controller](https://github.com/ros-planning/moveit/tree/master/moveit_plugins/moveit_fake_controller_manager)
* [Simple Controller](https://github.com/ros-planning/moveit/tree/master/moveit_plugins/moveit_simple_controller_manager) + [Gazebo](https://gazebosim.org/)
* [Simple Controller](https://github.com/ros-planning/moveit/tree/master/moveit_plugins/moveit_simple_controller_manager) + [Real Robot](https://www.elephantrobotics.com/en/mycobot-en/)

## 4-1. Fake Controller
```
$ roslaunch mycobot_bringup bringup.launch sim:=true is_fake:=true
```
* Appearance
<div align="center"><img src="https://user-images.githubusercontent.com/55785032/170192387-c2dd96f9-5d1a-414b-b135-2445eed6526f.png" width="50%"></div>

* Node Graph
![fake](https://user-images.githubusercontent.com/55785032/170192417-5ee8af34-f426-4c8b-b993-a418c81faed7.png)

## 4-2. Simple Controller + Gazebo

```
$ roslaunch mycobot_bringup bringup.launch sim:=true
```
* Appearance
<div align="center"><img src="https://user-images.githubusercontent.com/55785032/170192453-9a6e709b-3f1f-463c-81af-d4a2e084f4cd.png" width="50%"></div>

* Node Graph
![simple_gazebo](https://user-images.githubusercontent.com/55785032/170192467-3233d306-dafb-4502-9199-277d35574963.png)

## 4-3. Simple Controller + Real Robot

```
$ roslaunch mycobot_bringup bringup.launch
```
* Node Graph
![simple_real_robot](https://user-images.githubusercontent.com/55785032/170192488-686d4aae-d2fb-4c8c-bede-f159e0961dc4.png)

# 5. License

This repository is licensed under the MIT license, see [LICENSE](./LICENSE).  
Unless attributed otherwise, everything in this repository is licensed under the MIT license.

### Acknowledgements

* [elephantrobotics/mycobot_ros](https://github.com/elephantrobotics/mycobot_ros)
    * `Copyright (c) 2020, Elephant Robotics`
* [Tiryoh/mycobot_ros](https://github.com/Tiryoh/mycobot_ros)
    * `Copyright (c) 2020, Daisuke Sato`
* [nisshan-x/mycobot_moveit](https://github.com/nisshan-x/mycobot_moveit)
    * `Copyright (c) 2021, Shinya Nishimoto`
