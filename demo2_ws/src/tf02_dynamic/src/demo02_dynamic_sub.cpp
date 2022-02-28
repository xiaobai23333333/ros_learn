#include "ros/ros.h"
#include "tf2_ros/transform_listener.h"
#include "tf2_ros/buffer.h" 
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"dynamic_sub");
    ros::NodeHandle nh;
    tf2_ros::Buffer buffer;
    tf2_ros::TransformListener listener(buffer);
    geometry_msgs::PointStamped ps;
    ps.header.stamp = ros::Time(0.0);
    ps.header.frame_id = "turtle1";
    ps.point.x = 0.3;
    ps.point.y = 0.4;
    ps.point.z = 0.5;
    
    //添加休眠，保证转化时已经接受订阅的信息,也可采用try-catch解决
    // ros::Duration(2).sleep();

    ros::Rate rate(10);
    geometry_msgs::PointStamped ps_out;
    while (ros::ok())
    {
        try
        {
            ps_out = buffer.transform(ps,"world");
            ROS_INFO("转换后的坐标为(%.2f, %.2f, %.2f);参考的坐标系为：%s",
            ps_out.point.x,ps_out.point.y,ps_out.point.z,ps_out.header.frame_id.c_str());
            rate.sleep();
        }
        catch(const std::exception& e)
        {
            ROS_ERROR("再等一会儿");
        }
        ros::spinOnce();
    }
    return 0;
}
