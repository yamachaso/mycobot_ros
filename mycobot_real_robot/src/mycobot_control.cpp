#include <ros/ros.h>
#include <mycobot_real_robot/mycobot_hw.h>
#include <controller_manager/controller_manager.h>

int main(int argc, char **argv)
{
	ros::init(argc, argv, "mycobot_control");
	ros::NodeHandle nh;

	MyRobot robot(nh);
	controller_manager::ControllerManager cm(&robot, nh);

	ros::AsyncSpinner spinner(1);
	spinner.start();

	ros::Time prev_time = ros::Time::now();
	ros::Rate rate(10.0); // 10 Hz rate

	while (ros::ok())
	{
		const ros::Time time = ros::Time::now();
		const ros::Duration period = time - prev_time;

		robot.read(time, period);
		ROS_WARN("read update");
		cm.update(time, period);
		ROS_WARN("update write");
		robot.write(time, period);

		rate.sleep();
	}
	spinner.stop();

	return 0;
}