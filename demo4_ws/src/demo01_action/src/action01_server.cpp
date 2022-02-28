#include "ros/ros.h"
#include "actionlib/server/simple_action_server.h"
#include "demo01_action/AddIntsAction.h"

typedef actionlib::SimpleActionServer<demo01_action::AddIntsAction> Server;

// 回调函数
void cb(const demo01_action::AddIntsGoalConstPtr &goalPtr, Server *server)
{
    int goal_num = goalPtr->num;
    ROS_INFO("客户端提交的目标值是：%d",goal_num);
    ros::Rate rate(10);
    int result = 0;
    for(int i=1;i<=goal_num;i++)
    {
        // 累加
        result += i;
        // 休眠
        rate.sleep();
        // 产生连续反馈
        demo01_action::AddIntsFeedback fb;
        fb.progress_bar = i / (double)goal_num;
        server->publishFeedback(fb);
    }
    // 设置最终结果
    ROS_INFO("最终响应结果为%d", result);
    demo01_action::AddIntsResult r;
    r.result= result;
    server->setSucceeded(r);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"addInts_server");
    ros::NodeHandle nh;
    Server server(nh,"addInts",boost::bind(&cb,_1,&server),false);
    server.start();
    ROS_INFO("服务端启动成功！");
    ros::spin();
    return 0;
}
