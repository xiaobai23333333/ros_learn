#include "ros/ros.h"
#include "turtlesim/Pose.h"

/* 
    需求：订阅乌龟的位姿信息，并在命令行输出
    1.导入功能包
    2.初始化节点
    3.创建ros句柄
    4.订阅信息
    4.回调函数

 */

void doPose(const turtlesim::Pose::ConstPtr &pose)
{
    ROS_INFO("乌龟的位姿信息：坐标（%.2f,%.2f）,朝向（%.2f）,线速度：%.2f,角速度：%.2f",
    pose->x,pose->y,pose->theta,pose->linear_velocity,pose->angular_velocity);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"sub_pose");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("/turtle1/pose",10,doPose);
    ros::spin();
    return 0;
}
