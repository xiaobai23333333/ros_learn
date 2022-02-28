#include "ros/ros.h"
#include "turtlesim/Spawn.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"create_turtle2");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<turtlesim::Spawn>("/spawn");
    ros::service::waitForService("/spawn");
    turtlesim::Spawn spawn;
    spawn.request.x = 1.0;
    spawn.request.y = 2.0;
    spawn.request.theta = 2.22;
    spawn.request.name = "turtle2";
    bool flag = client.call(spawn);
    if (flag)
    {
        ROS_INFO("乌龟%s创建成功!",spawn.response.name.c_str());
    }
    else
    {
        ROS_INFO("乌龟2创建失败!");
    }
    ros::spin();
    return 0;
}
