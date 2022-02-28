#!/usr/bin/env python3

import rospy

if __name__=="__main__":
    rospy.init_node("setParam")
    rospy.set_param("type","车")
    rospy.set_param("radius",0.15)
    