#include "ros/ros.h"
#include <std_msgs/UInt8.h>
#include "simple_talker/talker.h"

Talker::Talker()
{
     record_pub = nh.advertise<std_msgs::UInt8>("uav_agent/record", 1);
}    

void Talker::startRecord()
{
    std_msgs::UInt8 msg;
    msg.data = 1;
    record_pub.publish(msg);
    ROS_INFO("start!!");

}

void Talker::stopRecord()
{
    std_msgs::UInt8 msg;
    msg.data = 2;
    record_pub.publish(msg);
    ROS_INFO("stop published");

}



// void Talker::publishStartCallback(const ros::TimerEvent&)
// {

//     std_msgs::UInt8 msg;

//     msg.data = 1;

//     record_pub.publish(msg);

//     ROS_INFO("start published");

// }

// void Talker::publishStopCallback(const ros::TimerEvent&)
// {

//     std_msgs::UInt8 msg;

//     msg.data = 0;

//     record_pub.publish(msg);

//     ROS_INFO("stop published");

// }


int main(int argc, char **argv)
{
    ros::init(argc, argv, "talker_proc");

    Talker talker;
     
    ros::Rate loop_rate(50);

    ros::Duration(2).sleep();

    while (ros::ok())
    {

        talker.startRecord();

        ros::Duration(10).sleep();

        talker.stopRecord();

        ros::Duration(20).sleep();

         
        ros::spinOnce();

        loop_rate.sleep();
    }
}