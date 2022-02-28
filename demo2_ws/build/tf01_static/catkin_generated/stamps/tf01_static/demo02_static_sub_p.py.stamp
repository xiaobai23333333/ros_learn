#! /usr/bin/env python
from logging import exception
import rospy
from rospy.timer import Rate
import tf2_ros
from tf2_ros import buffer
from tf2_geometry_msgs import tf2_geometry_msgs

if __name__ == "__main__":
    rospy.init_node("static_sub_p")
    buffer = tf2_ros.Buffer()
    sub = tf2_ros.TransformListener(buffer)
    ps = tf2_geometry_msgs.PointStamped()
    ps.header.stamp = rospy.Time.now()
    ps.header.frame_id = "laser"
    ps.point.x = 2.0
    ps.point.y = 3.0
    ps.point.z = 5.0

    rate = rospy.Rate(1)
    while not rospy.is_shutdown():
        try:
            ps_out = buffer.transform(ps, "base_link")
            rospy.loginfo("转换后的坐标：(%.2f,%.2f,%.2f), %s",
                          ps_out.point.x,
                          ps_out.point.y,
                          ps_out.point.z,
                          ps_out.header.frame_id
                          )
        except Exception as e:
            rospy.logerr("错误提示：%s", e)
        rate.sleep()
