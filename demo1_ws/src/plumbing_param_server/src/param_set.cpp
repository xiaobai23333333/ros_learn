#include "ros/ros.h"
/*
    两种方法
    1.nodeHandle 
    2.ros::param中的方法
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"setParam");

    ros::NodeHandle nh;
    
    nh.setParam("type","车");

    ros::param::set("type_p","che");
    
    return 0;
}
