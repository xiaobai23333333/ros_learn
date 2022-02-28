#! /usr/bin/env python

import rospy
from turtlesim.srv import *

if __name__=="__main__":
    rospy.init_node("srvClient")
    client =  rospy.ServiceProxy("/spawn",Spawn)
    spawn = SpawnRequest()
    spawn.x = 1.0
    spawn.y = 6.0
    spawn.theta = 3.14
    spawn.name = "turtle3"

    client.wait_for_service()
    try:
        response = client.call(spawn)
        rospy.loginfo("生成乌龟%s",response.name)
    except Exception as e:
        rospy.logerr("请求处理异常")
