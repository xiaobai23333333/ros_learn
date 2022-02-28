#include "ros/ros.h"

int main(int argc, char *argv[])
{
    //解决乱码
    setlocale(LC_CTYPE,"zh_CN.utf8");
    
    ros::init(argc,argv,"hello_c");

    ROS_INFO("hello,哈哈");
    return 0;
}
