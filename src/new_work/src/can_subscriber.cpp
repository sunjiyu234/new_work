#include<iostream>
#include<math.h>
#include<std_msgs/String.h>
#include<ros/ros.h>
#include<sstream>
#include<string>
using namespace std;
double now_vx = 0.0;
void state_call_back(const std_msgs::String::ConstPtr &msgs){
    //cout << "here"<<endl;
    stringstream ss_vx;
    string now = msgs->data.c_str();
    //cout << now<<endl;
    ss_vx << now;
    ss_vx >> now_vx;
}

int main(int argc, char** argv){
    ros::init(argc, argv, "can_listener");
    ros::NodeHandle nh;
    ros::Subscriber can_sub = nh.subscribe("/gps", 10, state_call_back);
    ros::Duration(0.5).sleep();
    ros::Rate(50);
    while(ros::ok()){
        ros::spinOnce();
        cout << now_vx<<endl;
    }
}