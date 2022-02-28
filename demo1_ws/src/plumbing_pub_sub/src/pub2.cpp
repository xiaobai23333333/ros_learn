#include "ros/ros.h"
#include "plumbing_pub_sub/Person.h"

int main(int argc, char *argv[])
{
    setlocale(LC_ALL,"");
    ros::init(argc,argv,"pub");
    ros::NodeHandle nh;
    ros::Publisher pub = nh.advertise<plumbing_pub_sub::Person>("person",10);
    plumbing_pub_sub::Person person;
    person.name = "wc组合";
    person.age = 0;
    person.height = 100;
    ros::Rate rate(1);
    while (ros::ok())
    {
        ++person.age;
        pub.publish(person);
        ROS_INFO("发布的消息%s, %d, %f, ",person.name.c_str(),person.age,person.height);
        rate.sleep();
        ros::spinOnce();
    }
    return 0;
}
