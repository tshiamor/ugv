#include "ros/ros.h"
#include "std_msgs/String.h"


#include <geometry_msgs/Twist.h>
#include <sensor_msgs/Joy.h>

#include <sstream>
using namespace std;


void jCallback(const sensor_msgs::Joy::ConstPtr& joy);

void motionCommands(const geometry_msgs::Twist::ConstPtr& vel)
{
   geometry_msgs::Twist new_vel = *vel;

   std::cout<< "linear speed : " << vel->linear.x <<std::endl;
   std::cout<< "angular speed: " << vel->angular.z <<std::endl;

   ROS_INFO("cmd..");

   /*
   if (vel->linear.x > 0.7) {
     new_vel.linear.x = 0.7;
   }
   pub.publish(new_vel);
   */

}


int main(int argc, char* argv[] ){

    ros::init(argc,argv, "ugv");
    ros::NodeHandle n;

    ros::Publisher MotionComms =  n.advertise<geometry_msgs::Twist>("cmd_val",1000);
    ros::Subscriber sub =  n.subscribe<geometry_msgs::Twist>("cmd_vel", 1, motionCommands);

    ROS_INFO("starting ugv with joy-callback..");



    ros::Rate loop_rate(10);


   /// while(ros::ok()){

        geometry_msgs::Twist velocity;
        velocity.linear.x = 10;
        velocity.angular.z = 5;

        MotionComms.publish(velocity);
        loop_rate.sleep();


        ros::spin();  

        //ROS_INFO("heart-beat..");

   /// }

    return 0;

}//end main


void jCallback(const sensor_msgs::Joy::ConstPtr& joy){

    int linear_, angular_;
    std_msgs::String msg;

}
