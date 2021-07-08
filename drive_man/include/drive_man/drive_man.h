#ifndef DRIVE_MAN_H
#define DRIVE_MAN_H

#include "ros/ros.h"
#include "geometry_msgs/Twist.h"


class driveman
{

private:

    // PUBLISHER
    ros::Publisher pub;

public:

    //***************** NODE HANDLES ***************//
    driveman(ros::NodeHandle *nh)
    {
     
        pub = nh->advertise<geometry_msgs::Twist>("man/cmd_vel", 10);
        movetable1();
        ros::Duration(0.3).sleep();
        moveforward(2.5);
        turnleft(10);
        moveforward(0.1);
        turnleft(10);
        moveforward(0.1);
        turnleft(10);
        moveforward(0.1);
        turnleft(10);
        moveforward(0.1);
        moveforward(1.5);
        turnleft(55);
        moveforward(4.0);
        ROS_INFO("Stopped");
    }


    void moveforward(float meter)
    {
        // this function will move the man forward in meters specified
        geometry_msgs::Twist msg;
        msg.linear.x = 0.5;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        ros::Duration(0.001).sleep();
        pub.publish(msg);

        msg.linear.x = 0.0;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        ros::Duration(meter / 0.5).sleep();
        pub.publish(msg);
    }

    void turnleft(float degree)
    {
        // this function will turn the man left in degrees specified
        geometry_msgs::Twist msg;
        msg.linear.x = 0.0;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        msg.angular.z = 0.7854;
        ros::Duration(0.001).sleep();
        pub.publish(msg);

        msg.linear.x = 0.0;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        msg.angular.z = 0.0;
        ros::Duration(((degree * 3.14) / 180) / 0.7854).sleep();
        pub.publish(msg);
    }

    void turnright(float degree)
    {
        // this function will turn the man right in degrees specified
        geometry_msgs::Twist msg;
        msg.linear.x = 0.0;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        msg.angular.z = -0.7854;
        ros::Duration(0.001).sleep();
        pub.publish(msg);

        msg.linear.x = 0.0;
        msg.linear.y = 0.0;
        msg.linear.z = 0.0;
        msg.angular.z = 0.0;
        ros::Duration(((degree * 3.14) / 180) / 0.7854).sleep();
        pub.publish(msg);
    }

    void movetable1()
    {
        // this function will move the man to table-1 in world 
        moveforward(2.5);
        ros::Duration(0.5).sleep();
        turnleft(10);
        moveforward(0.1);
        turnleft(10);
        moveforward(0.1);
        turnleft(10);
        moveforward(0.1);
        turnleft(10);
        moveforward(0.1);
        moveforward(2.0);
        turnleft(45);
        ROS_INFO("Reached table 1");
    }
};

#endif