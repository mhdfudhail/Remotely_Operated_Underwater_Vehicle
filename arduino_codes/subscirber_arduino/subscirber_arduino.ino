#include <ros.h>
#include <std_msgs/Int8.h>
#include <Servo.h>


class BLDC
{
  private:
    byte pin;
    Servo thruster;
  public:
    BLDC(){}
    BLDC(byte pin)
    {
      this -> pin = pin;
    }
    void init()
    {
      
      thruster.attach(pin,1000,2000);
      thruster.writeMicroseconds(1516);//93 degree
      
    }
    void stp()
    {
      thruster.writeMicroseconds(1516);
    }
    void cw(int frequency=1300)
    {
      thruster.writeMicroseconds(frequency);
      
    }
    void ccw(int frequency=1700)
    {
      thruster.writeMicroseconds(frequency);
    }
};









ros::NodeHandle  nh;

void messageCb( const std_msgs::Int8& toggle_msg){
  if (toggle_msg.data >2){
    digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));
  }
}

ros::Subscriber<std_msgs::Int8> sub("to_arduino", &messageCb );

void setup()
{ 
  pinMode(LED_BUILTIN, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}
