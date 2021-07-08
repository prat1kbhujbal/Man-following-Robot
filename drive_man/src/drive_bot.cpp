#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "drive_man/DriveToTarget.h"

ros::Publisher motor_cmd_pub;

bool drive_request_callback(drive_man::DriveToTarget::Request &req,
                            drive_man::DriveToTarget::Response &res)
{
    ROS_INFO("DriveToTargetRequest received - linear_x: %1.2f, angular_z: %1.2f", (float)req.linear_x, (float)req.angular_z);

    geometry_msgs::Twist cmd_vel_;

    cmd_vel_.linear.x = req.linear_x;
    cmd_vel_.angular.z = req.angular_z;
    

    motor_cmd_pub.publish(cmd_vel_);

    res.msg_feedback = "Velocity cmd sent: linear_x = " + std::to_string(cmd_vel_.linear.x) + ", angular_z = " + std::to_string(cmd_vel_.angular.z);

    ROS_INFO_STREAM(res.msg_feedback);

    return true;
}

int main(int argc, char **argv)
{
    // Initialize a ROS node
    ros::init(argc, argv, "drive_bot");

    // Create a ROS NodeHandle object
    ros::NodeHandle nh;

    motor_cmd_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

    ros::ServiceServer service = nh.advertiseService("/drive_man/command_robot", drive_request_callback);
    ROS_INFO("Ready");

    // Handle ROS communication events
    ros::spin();

    return 0;
}
