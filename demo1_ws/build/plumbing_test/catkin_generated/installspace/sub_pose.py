#!/usr/bin/env python3

import rospy

from turtlesim.msg import Pose

def doPose(pose):
    rospy.loginfo("乌龟坐标:x=%.2f, y=%.2f,theta=%.2f",pose.x,pose.y,pose.theta)


if __name__ == "__main__":
    rospy.init_node("sub_pose")
    sub =  rospy.Subscriber("turtle1/pose",Pose,doPose,queue_size=10)
    rospy.spin()