#! /usr/bin/env python
import rospy
from tf import transformations
from tf.transformations import quaternion_from_euler
import tf2_ros
from geometry_msgs.msg import TransformStamped
import tf

if __name__ == "__main__":

    rospy.init_node("static_pub_p")
    pub = tf2_ros.StaticTransformBroadcaster()
    ts = TransformStamped()
    # 组织内容
    ts.header.stamp = rospy.Time.now()
    ts.header.frame_id = "base_link"
    ts.child_frame_id = "laser"
    ts.transform.translation.x = 2.0
    ts.transform.translation.y = 0.0
    ts.transform.translation.z = 0.5
    qtn = quaternion_from_euler(0, 0, 0)
    ts.transform.rotation.x = qtn[0]
    ts.transform.rotation.y = qtn[1]
    ts.transform.rotation.z = qtn[2]
    ts.transform.rotation.w = qtn[3]
    pub.sendTransform(ts)
    rospy.spin()
    pass
