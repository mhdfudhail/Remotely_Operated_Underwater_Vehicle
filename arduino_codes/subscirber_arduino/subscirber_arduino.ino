#include <ros.h>
#include <std_msgs/Int8.h>
#include <Servo.h>

#define TFR 9
#define TFL 10


/* ------------Brush-Less DC motor class------------- */
//BLDC class created

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
/* ------------Brush-Less DC motor class ends------------- */




BLDC thruster_FR(TFR);
BLDC thruster_FL(TFL);


ros::NodeHandle  nh;

void messageCb( const std_msgs::Int8& toggle_msg){
  if (toggle_msg.data >2){
//    digitalWrite(LED_BUILTIN, HIGH-digitalRead(LED_BUILTIN));
      bldc();

//    
//    
  }
}

ros::Subscriber<std_msgs::Int8> sub("to_arduino", &messageCb );

void setup()
{ //Other peripheral initialization
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
  // Thrusters initialization 
  thruster_FR.init();
  thruster_FL.init();
  // ROS initialization
  nh.initNode();
  nh.subscribe(sub);
}

void loop()
{  
  nh.spinOnce();
  delay(1);
}

void bldc()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);  
    thruster_FR.cw();
    thruster_FL.cw();
    delay(2000);
    thruster_FR.stp();
    thruster_FL.stp();
    delay(1000);
    thruster_FR.ccw();
    thruster_FL.ccw();
    delay(2000);
    thruster_FR.stp();
    thruster_FL.stp();
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); 
    
}
