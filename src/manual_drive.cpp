#include "ros/ros.h"
#include "teleop_twist_joy/teleop_twist_joy.h"


/*
ros::Subscribe joyPayload;

int enable_button;
int enable_turbo_button;

std::map<std::string, int> axis_linear_map;
std::map< std::string, std::map<std::string, double> > scale_linear_map;

std::map<std::string, int> axis_angular_map;
std::map< std::string, std::map<std::string, double> > scale_angular_map;

//void Callback(const joy::Joy::ConstPtr& joy){}

void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
void sendCmdVelMsg(const sensor_msgs::Joy::ConstPtr& joy_msg, const std::string& which_map);
*/


int main(int argc, char* argv[]){

    ros::init(argc, argv, "ugv_teleop");

    ros::NodeHandle nh(""), nh_param("~");
    teleop_twist_joy::TeleopTwistJoy joy_teleop(&nh, &nh_param);


    //joyPayload = nh.subscribe<"",10, &Callback >





    ros::spin();

return 0;

}

/*
void TeleopTwistJoy::Impl::joyCallback(const sensor_msgs::Joy::ConstPtr& joy_msg)
 {


     sendCmdVelMsg(joy_msg, "normal");

 }

 void TeleopTwistJoy::Impl::sendCmdVelMsg(const sensor_msgs::Joy::ConstPtr& joy_msg,
                                          const std::string& which_map)
 {
   // Initializes with zeros by default.
   geometry_msgs::Twist cmd_vel_msg;
  
   cmd_vel_msg.linear.x = getVal(joy_msg, axis_linear_map, scale_linear_map[which_map], "x");
   cmd_vel_msg.linear.y = getVal(joy_msg, axis_linear_map, scale_linear_map[which_map], "y");
   cmd_vel_msg.linear.z = getVal(joy_msg, axis_linear_map, scale_linear_map[which_map], "z");

   cmd_vel_msg.angular.z = getVal(joy_msg, axis_angular_map, scale_angular_map[which_map], "yaw");
   cmd_vel_msg.angular.y = getVal(joy_msg, axis_angular_map, scale_angular_map[which_map], "pitch");
   cmd_vel_msg.angular.x = getVal(joy_msg, axis_angular_map, scale_angular_map[which_map], "roll");
  
   cmd_vel_pub.publish(cmd_vel_msg);
   sent_disable_msg = false;
 }

*/