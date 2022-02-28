#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h" 
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    geometry_msgs::PointStamped ps;
    ps.header.stamp = ros::Time::now();
    ps.header.frame_id = "laser";
    ps.point.x = 0.3;
    ps.point.y = 0.4;
    ps.point.z = 0.5;
    
    //添加休眠，保证转化时已经接受订阅的信息
    ros::Duration(2).sleep();

    ros::Rate rate(10);
    geometry_msgs::PointStamped ps_out;
    while (ros::ok())
    {
        ps_out = buffer.transform(ps,"base_link");
        ROS_INFO("转换后的坐标为(%.2f, %.2f, %.2f);参考的坐标系为：%s",
        ps_out.point.x,ps_out.point.y,ps_out.point.z,ps_out.header.frame_id.c_str());
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
