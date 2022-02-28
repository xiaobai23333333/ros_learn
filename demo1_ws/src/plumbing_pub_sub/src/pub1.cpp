/*
    1.添加头文件；
    2.初始化ros节点；
    3.创建节点句柄；
    4.创建发布者对象；
    5.编写发布逻辑并发布数据。
*/

#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"pubNode");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<std_msgs::String>("fang",10);
    std_msgs::String msg;
    //以1Hz发送数据
    ros::Rate rate(1);
    int count = 0;
    while (ros::ok())
    {
        ++count;
        std::stringstream ss;
        ss<<"hello ---> "<<count;
        msg.data = ss.str();
        pub.publish(msg);
        //日志输出
        ROS_INFO("发布的数据是：%s",ss.str().c_str());
        rate.sleep();
        
        ros::spinOnce();
    }
    return 0;
}
