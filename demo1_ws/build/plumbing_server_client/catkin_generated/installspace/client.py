#!/usr/bin/env python3

import  rospy
from plumbing_server_client.srv import *
import sys

if __name__ == "__main__":
    
    #先判断参数长度
    if len(sys.argv) != 3:
        rospy.logerr("传入参数不对")
        sys.exit(1)

    rospy.init_node("client")
    client = rospy.ServiceProxy("ints",AddInts)

    # 挂起操作
    client.wait_for_service()
    #rospy.wait_for_service("ints")
    num1 = int(sys.argv[1])
    num2 = int(sys.argv[2])
    response = client.call(num1,num2)
    rospy.loginfo("响应的数据：%d",response.sum)