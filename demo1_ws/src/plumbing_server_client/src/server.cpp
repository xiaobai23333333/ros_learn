#include "ros/ros.h"
#include "plumbing_server_client/AddInts.h"

bool doNum(plumbing_server_client::AddInts::Request &request,
            plumbing_server_client::AddInts::Response &response)
{
    int num1 = request.num1;
    int num2 = request.num2;
    int sum = num1+num2;
    response.sum = sum;
    ROS_INFO("两个加数为：%d, %d, 求和结果为：%d",num1,num2,sum);
    return true;
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("服务端启动成功！");
    ros::init(argc,argv,"Server");
    ros::NodeHandle nh;
    ros::ServiceServer server = nh.advertiseService("AddInts",doNum);
    ros::spin();
    return 0;
}
