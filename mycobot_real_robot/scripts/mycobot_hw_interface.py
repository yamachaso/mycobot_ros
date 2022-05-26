#!/usr/bin/env python2
import subprocess
import rospy


from std_msgs.msg import Float32MultiArray
from pymycobot import MyCobot

class MycobotHwInterface:
  def __init__(self, n_dof = 6):
    port_str = rospy.get_param("/hardware_interface/mycobot_port", "default")
    if port_str == "default":
      port = subprocess.run(['echo -n /dev/ttyUSB*'], shell=True, stdout=subprocess.PIPE, check=True).stdout.decode()
    else:
      port = subprocess.run(['echo -n ' + port_str], shell=True, stdout=subprocess.PIPE, check=True).stdout.decode()

    self.mycobot_ = MyCobot(port)
    self.mycobot_.power_on()

    rospy.init_node('mycobot_hw_interface', anonymous=True)
    self.joint_state_msg_pub_ = rospy.Publisher('/joint_states_if', Float32MultiArray, queue_size=10)
    self.joint_cmd_sub_ = rospy.Subscriber("/joint_cmd_if", Float32MultiArray, self.jointCommandCallback)

    self.rate_ = rospy.Rate(10) # 10hz

    self.n_dof_ = n_dof

    self.pre_data_list = None


  def __del__(self):
    self.mycobot_.power_off()

  def main_loop(self):
    while not rospy.is_shutdown():
      self.joint_state_msg_sender()
      self.rate_.sleep()

  def joint_state_msg_sender(self):
    # NEED CHECK!
    # deep copy here, otherwise MyRobot::jointSubscribeCallback in mycobot_hw.cpp cannnot get the adequate value sometimes and the process dies
    angles = self.mycobot_.get_radians().copy()
    # str = "angles: %s" % angles
    # rospy.loginfo(str)

    joint_state_msg = Float32MultiArray(data=angles)
    self.joint_state_msg_pub_.publish(joint_state_msg)

  def jointCommandCallback(self, msg):
    data_list = [*msg.data]
    if self.pre_data_list is None or self.pre_data_list != data_list:
      rospy.loginfo(rospy.get_caller_id() + "%s", msg.data)
      self.mycobot_.send_radians(data_list, 50)
      self.pre_data_list = data_list.copy()

if __name__ == '__main__':
  try:
    mc_hw_if = MycobotHwInterface()
    mc_hw_if.main_loop()
  except rospy.ROSInterruptException:
    pass

