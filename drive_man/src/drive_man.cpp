
#include <ros/ros.h>
#include "drive_man/drive_man.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "driveman"); // register the node on ROS
    ros::NodeHandle nh;  // get a handle to ROS
    driveman nc = driveman(&nh);  // initiate class object
    ros::spin();   // check for new messages and call the callback if got one
}