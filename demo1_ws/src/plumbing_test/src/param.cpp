#include "ros/ros.h"

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"setParam");
    
    //法1：
    // ros::param::set("/turtlesim/background_r",0);
    // ros::param::set("/turtlesim/background_g",50);
    // ros::param::set("/turtlesim/background_b",100);
    //法2：
    // ros::NodeHandle nh;
    // nh.setParam("/turtlesim/background_r",30);
    // nh.setParam("/turtlesim/background_g",60);
    // nh.setParam("/turtlesim/background_b",90);
    ros::NodeHandle nh("turtlesim");
    nh.setParam("background_r",30);
    nh.setParam("background_g",60);
    nh.setParam("background_b",90);
    return 0;
}
