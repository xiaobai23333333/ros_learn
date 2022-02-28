#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

/* 
    需求：定时发送乌龟行进数据
 */

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"pub_twist");
    ros::NodeHandle nh;

    geometry_msgs::Twist msg;
    msg.linear.x = 1.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 1.0;

    ros::Rate rate(10);
    ros::Publisher pub = nh.advertise<geometry_msgs::Twist>("turtle1/cmd_vel",10);
    while (ros::ok())
    {
        pub.publish(msg);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
