#!/usr/bin/env python3

import rospy

if __name__ == "__main__":
    rospy.init_node("delParam")
    rospy.delete_param("type")
    rospy.delete_param("radius")