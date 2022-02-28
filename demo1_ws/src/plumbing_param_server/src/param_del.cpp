#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"delParam");
    ros::NodeHandle nh;
    bool flag =  nh.deleteParam("type");
    if(flag)
    {
        ROS_INFO("type删除成功。");
    }
    else
    {
        ROS_INFO("type删除失败！");
    }
    flag = ros::param::del("type");
        if(flag)
    {
        ROS_INFO("type删除成功。");
    }
    else
    {
        ROS_INFO("type删除失败！");
    }
    return 0;
}
