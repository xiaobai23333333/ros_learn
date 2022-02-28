#include "ros/ros.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"getParam");
    ros::NodeHandle nh;
    std::string str; 
    bool flag = nh.getParam("type",str);
    if(flag)
    {
        ROS_INFO("参数type的值为：%s",str.c_str());
    }
    else
    {
        ROS_INFO("参数type获取失败！");
    }
    flag = nh.getParam("type_p",str);
    if(flag)
    {
        ROS_INFO("参数type_p的值为：%s",str.c_str());
    }
    else
    {
        ROS_INFO("参数type_p获取失败！");
    }
    return 0;
}
