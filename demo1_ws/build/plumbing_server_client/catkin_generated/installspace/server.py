#!/usr/bin/env python3

import rospy
from plumbing_server_client.srv import AddInts, AddIntsRequest, AddIntsResponse
"""
    服务端：解析客户端请求，产生响应。

        1.导包；
        2.初始化ROS节点；
        3.创建服务端对象；
        4.处理逻辑（回调函数）；
        5.spin()
"""

def doNum(request):
    num1 = request.num1
    num2 = request.num2

    sum = num1 + num2

    response = AddIntsResponse()
    response.sum = sum
    rospy.loginfo("服务器解析的数据num1 = %d, num2 = %d,", num1,num2);
    return response

if __name__ == "__main__":
    rospy.init_node("server")
    server = rospy.Service("ints",AddInts,doNum)
    rospy.loginfo("服务器已启动。")
    rospy.spin()
    pass