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



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);

    // Thrusters initialization 
  thruster_FR.init();
  thruster_FL.init();
  delay(4000);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  bldc();
  delay(1000);
}


  void bldc()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);  
    thruster_FR.cw();
    thruster_FL.cw();
    delay(1500);
    thruster_FR.cw(1450);
    thruster_FL.cw(1450);
    delay(500);
    thruster_FR.stp();
    thruster_FL.stp();
    delay(3000);
    thruster_FR.ccw();
    thruster_FL.ccw();
    delay(2000);
    thruster_FR.stp();
    thruster_FL.stp();
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000); 
    
}
