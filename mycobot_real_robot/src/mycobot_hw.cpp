#include <sstream>
#include <mycobot_real_robot/mycobot_hw.h>
#include <iostream>


MyRobot::MyRobot(ros::NodeHandle &node)
{
  n_dof_ = 6;

  pos_store_.clear();
  jnt_pos_.clear();
  jnt_vel_.clear();
  jnt_eff_.clear();
  jnt_pos_cmd_.clear();
  pos_store_.resize(n_dof_);
  jnt_pos_.resize(n_dof_);
  jnt_vel_.resize(n_dof_);
  jnt_eff_.resize(n_dof_);
  jnt_pos_cmd_.resize(n_dof_);


  for(int i = 0; i < n_dof_; i++) {
    std::stringstream ss;
    ss << "joint" << i + 1;
    
    hardware_interface::JointStateHandle state_handle(ss.str(), &jnt_pos_[i], &jnt_vel_[i], &jnt_eff_[i]);
    jnt_state_interface_.registerHandle(state_handle);
    hardware_interface::JointHandle pos_handle(jnt_state_interface_.getHandle(ss.str()), &jnt_pos_cmd_[i]);
    jnt_pos_cmd_interface_.registerHandle(pos_handle);
  }
  registerInterface(&jnt_state_interface_);
  registerInterface(&jnt_pos_cmd_interface_);

  jnt_sub_ = node.subscribe("/joint_states_if", 100, &MyRobot::jointSubscribeCallback, this);
  cmd_pub_ = node.advertise<std_msgs::Float32MultiArray>("/joint_cmd_if", 10);
}

void MyRobot::jointSubscribeCallback(const std_msgs::Float32MultiArray &msg){
  std::cout << "jointSubscribeCallback in" <<std::endl; 

  for(int i = 0; i < n_dof_; i++){
    std::cout << msg.data[i] << ' ';
    pos_store_[i] = msg.data[i];
  }
  std::cout << std::endl;
  std::cout << "jointSubscribeCallback out" <<std::endl; 

}

void MyRobot::read(ros::Time time, ros::Duration period)
{
  for(int i = 0; i < n_dof_; i++){
    jnt_pos_[i] = pos_store_[i];
    jnt_vel_[i] = 0;
    jnt_eff_[i] = 0;
  }
}

void MyRobot::write(ros::Time time, ros::Duration period)
{
  std_msgs::Float32MultiArray commands;
  commands.data.resize(n_dof_);
  for(int i = 0; i < n_dof_; i++){
    commands.data[i] = jnt_pos_cmd_[i];
  }
  cmd_pub_.publish(commands);
}