#include<iostream>
#include<math.h>
#include<std_msgs/String.h>
#include<ros/ros.h>
#include<sstream>
using namespace std;

int main(int argc, char** argv){
    ros::init(argc, argv, "can_publisher");
    ros::NodeHandle nh;
    ros::Publisher can_pub = nh.advertise<std_msgs::String>("/gps", 10);
    ros::Rate(50);
    while(ros::ok()){
        stringstream ss_vx;
        double vx = 10.0;
        string s_vx;
        ss_vx << vx;
        ss_vx >> s_vx;
        std_msgs::String status_msgs;
        status_msgs.data = s_vx;
        can_pub.publish(status_msgs);
        ros::Rate sleep();
    }
    return 0;
}