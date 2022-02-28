#!/usr/bin/env python3

"""
    使用Python实现消息发布：
    1.导包；
    2.初始化ros节点；
    3.创建发布者对象；
    4.编写发布逻辑并发布数据。
"""


import rospy
from std_msgs.msg import String

if __name__ == "__main__":
    rospy.init_node("pub1")
    pub = rospy.Publisher("che",String,queue_size=10)
    msg = String()
    rate = rospy.Rate(1)
    count = 0
    while not rospy.is_shutdown():
        count += 1
        msg.data = "hello"+str(count)
        pub.publish(msg)
        rospy.loginfo("发布的数据： %s",msg.data)
        rate.sleep()