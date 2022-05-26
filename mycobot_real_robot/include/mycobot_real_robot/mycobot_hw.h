#include <ros/ros.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <std_msgs/Float32MultiArray.h>
#include <vector>



class MyRobot : public hardware_interface::RobotHW
{
public:
  MyRobot(ros::NodeHandle &node);

  ros::Time getTime() const { return ros::Time::now(); }
  ros::Duration getPeriod() const { return ros::Duration(0.1); }

  void read(ros::Time, ros::Duration);
  void write(ros::Time, ros::Duration);

private:
  ros::Publisher cmd_pub_;
  ros::Subscriber jnt_sub_;

  unsigned int n_dof_;

  hardware_interface::JointStateInterface jnt_state_interface_;
  hardware_interface::PositionJointInterface jnt_pos_cmd_interface_;


  std::vector<double> pos_store_;
  
  std::vector<double> jnt_pos_;
  std::vector<double> jnt_vel_;
  std::vector<double> jnt_eff_;
  std::vector<double> jnt_pos_cmd_;

  void jointSubscribeCallback(const std_msgs::Float32MultiArray &msg);
};