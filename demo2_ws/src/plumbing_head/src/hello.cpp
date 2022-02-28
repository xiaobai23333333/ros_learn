#include "ros/ros.h"
#include "plumbing_head/hello.h"

namespace hello_ns{
    void MyHello::run()
    {
        ROS_INFO("run()函数运行～～");
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"head");
    ros::NodeHandle nh;
    hello_ns::MyHello hello;
    hello.run();
    return 0;
}
