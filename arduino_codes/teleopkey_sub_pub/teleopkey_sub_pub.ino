#include <ros.h>
#include <std_msgs/Int8.h>
#include <std_msgs/Float32.h>
//#include <std_msgs/String.h>
#include <geometry_msgs/Twist.h>

ros::NodeHandle nh;
std_msgs::Int8 msg;


ros::Publisher chatter("from_arduino", &msg);

int vel_left = 0;
int vel_right = 0;
int vel_front = 0;


void callback(const geometry_msgs::Twist& twist)
{
  vel_left = round(double(twist.linear.x));
  vel_right = round(double(twist.linear.y));
  vel_front = round(double(twist.linear.z));
  msg.data = vel_left;
  chatter.publish(&msg);
  delay(100);
  
  
}
ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", &callback);


void setup() {
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
  

}

void loop() {
  nh.spinOnce();
  delay(1);
}
