#!/usr/bin/env python3
from geometry_msgs import msg
import geometry_msgs
import rospy
from geometry_msgs.msg import Twist

if __name__ == "__main__":
    rospy.init_node("pub_twist")
    
    pub = rospy.Publisher("turtle1/cmd_vel",Twist,queue_size=10)
    msg = Twist()
    msg.linear.x = 1.0
    msg.linear.y = 0.0
    msg.linear.z = 0.0
    msg.angular.x = 0.0
    msg.angular.y = 0.0
    msg.angular.z = 1.0
    rate =  rospy.Rate(10)
    while not rospy.is_shutdown():
        pub.publish(msg)
        rate.sleep()
        