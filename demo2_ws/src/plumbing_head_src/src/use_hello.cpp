#include "ros/ros.h"
#include "plumbing_head_src/hello.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"headsrc");
    hello_ns::MyHello hello;
    hello.run();
    return 0;
}

