# 1. Overview
Unofficial myCobot moveit repositiry

# 2. Environment
|  |  |
|---|---|
| OS | Ubuntu 20.04 |
| ROS | noetic |
| HW | myCobot 280 M5Stack

# 3. Installation
```
$ cd catkin_ws/src
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
$ roslaunch mycobot_moveit_config moveit_planning_execution.launch sim:=true is_fake:=true
```

## 4-2. Simple Controller + Gazebo

```
$ roslaunch mycobot_moveit_config moveit_planning_execution.launch sim:=true
```


## 4-3. Simple Controller + Real Robot

```
$ roslaunch mycobot_moveit_config moveit_planning_execution.launch
```

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