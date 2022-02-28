#include "ros/ros.h"
#include "std_msgs/String.h"
/*
    实现流程:
        1.包含头文件 
        2.初始化 ROS 节点:命名(唯一)
        3.实例化 ROS 句柄
        4.实例化 订阅者 对象
        5.处理订阅的消息(回调函数)
        6.设置循环调用回调函数

*/

void doMsg(const std_msgs::String::ConstPtr &msg){
    ROS_INFO("sub订阅的数据%s",msg->data.c_str());
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"subNode");

    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("fang",10,doMsg);

    ros::spin();    //循环读取接收的数据，并调用回调函数处理
    return 0;
}
