#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"srvClient");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    
    turtlesim::Spawn span;
    span.request.x = 1;
    span.request.y = 4;
    span.request.theta = 1.57;
    span.request.name = "turtle2";

    client.waitForExistence();
    bool flag = client.call(span);
    if(flag)
    {
        ROS_INFO("乌龟%s生成成功！",span.response.name.c_str());
    }
    else
    {
        ROS_INFO("乌龟生成失败！");
    }
    return 0;
}
