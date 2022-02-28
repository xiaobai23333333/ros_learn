#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    if(argc !=3)
    {
        ROS_INFO("输入参数错误！");
        return 1;
    }
    ros::init(argc,argv,"Client");
    ros::NodeHandle nh;
    ros::ServiceClient client = nh.serviceClient<plumbing_server_client::AddInts>("AddInts");
    plumbing_server_client::AddInts ai;
    ai.request.num1 = atoi(argv[1]);
    ai.request.num2 = atoi(argv[2]);

    ROS_INFO("问题: %d + %d = ?",ai.request.num1,ai.request.num2);
    //两种方法等待服务端启动
    client.waitForExistence();
    // ros::service::waitForService("AddInts");

    bool flag = client.call(ai);
    if(flag)
    {
        ROS_INFO("结果：%d + %d = %d",ai.request.num1,ai.request.num2,ai.response.sum);    
    }
    else
    {
        ROS_ERROR("请求处理失败。。。");
        return 1;
    }
    return 0;
}
