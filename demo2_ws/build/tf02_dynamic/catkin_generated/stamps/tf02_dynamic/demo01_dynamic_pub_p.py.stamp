#! /usr/bin/env python
import rospy
import tf2_ros
from turtlesim.msg import Pose
from geometry_msgs.msg import TransformStamped
from tf.transformations import quaternion_from_euler


def doPose(pose):
    # 创建发布对象
    # 将pose位姿信息转换为相对关系
    pub = tf2_ros.TransformBroadcaster()
    ts = TransformStamped()
    ts.header.frame_id = "world"
    ts.header.stamp = rospy.Time.now()
    ts.child_frame_id = "turtle1"
    ts.transform.translation.x = pose.x
    ts.transform.translation.y = pose.y
    ts.transform.translation.z = 0

    # 四元数
    qtn = quaternion_from_euler(0, 0, pose.theta)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.x = qtn[3]
    pub.sendTransform(ts)


if __name__ == "__main__":
    rospy.init_node("dynamic_pub_p")
    # 1.订阅乌龟信息
    sub = rospy.Subscriber("/turtle1/pose", Pose, doPose, queue_size=100)
    # 2.发布出去
    rospy.spin()
