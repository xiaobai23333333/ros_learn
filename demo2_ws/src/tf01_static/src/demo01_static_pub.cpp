#include "ros/ros.h"
#include "tf2_ros/static_transform_broadcaster.h"
#include "tf2_geometry_msgs/tf2_geometry_msgs.h"
#include "tf/LinearMath/Quaternion.h"
/*
    1.初始化设置 编码，节点，句柄
    2.设置发布对象
    3.组织发布内容
    4.发布数据
*/

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"static_pub");
    ros::NodeHandle nh;
    tf2_ros::StaticTransformBroadcaster pub;
    geometry_msgs::TransformStamped tfs;
    tfs.header.stamp = ros::Time::now();
    tfs.header.frame_id = "base_link";
    tfs.child_frame_id = "laser";
    tfs.transform.translation.x = 0.2;
    tfs.transform.translation.y = 0;
    tfs.transform.translation.z = 0.5;

    //通过欧拉角获取四元数
    tf::Quaternion qtn;
    qtn.setRPY(0,0,0);
    tfs.transform.rotation.x = qtn.getX();
    tfs.transform.rotation.y = qtn.getY();
    tfs.transform.rotation.z = qtn.getZ();
    tfs.transform.rotation.w = qtn.getW();
    pub.sendTransform(tfs);
    ros::spin();

    return 0;
}
