#include <ros/ros.h>
#include <mycobot_real_robot/mycobot_hw.h>
#include <controller_manager/controller_manager.h>
#include <iostream>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mycobot_control");
	ros::NodeHandle nh;

	MyRobot robot(nh);
	controller_manager::ControllerManager cm(&robot, nh);

	ros::AsyncSpinner spinner(1);
	spinner.start();

	while (ros::ok())
	{
		ros::Time now = robot.getTime();
    ros::Duration dt = robot.getPeriod();

		robot.read(now, dt);
		cm.update(now, dt);
		robot.write(now, dt);

		dt.sleep();
	}
	spinner.stop();

	return 0;
}