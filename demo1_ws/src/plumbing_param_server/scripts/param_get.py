#! /usr/bin/env python

import rospy

if __name__=="__main__":
    rospy.init_node("getParam")
    #1. get_param
    type = rospy.get_param("type","")
    radius = rospy.get_param("radius",0.5)
    rospy.loginfo("radius = %.2f", radius)
    #2. get_param_cached
    #3. get_param_names
    #4. has_param
    #5. search_param