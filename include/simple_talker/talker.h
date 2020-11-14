#ifndef TALKER_H
#define TALKER_H

#include <ros/ros.h>
#include <std_msgs/UInt8.h>


class Talker{

public:
    Talker();
  //  void publishStartCallback(const ros::TimerEvent&);
   // void publishStopCallback(const ros::TimerEvent&);
    void startRecord();
    void stopRecord();


private:
    ros::NodeHandle nh;
    ros::Publisher record_pub;
   // ros::Timer timer;
    



};

#endif