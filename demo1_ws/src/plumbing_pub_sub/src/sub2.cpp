#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

void doPerson(const plumbing_pub_sub::Person::ConstPtr &person)
{
    ROS_INFO("订阅的人的信息：%s， %d, %f,",person->name.c_str(),person->age,person->height);
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ROS_INFO("订阅方实现");
    ros::init(argc,argv,"sub");
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe("person",10,doPerson);
    ros::spin();
    return 0;
}
