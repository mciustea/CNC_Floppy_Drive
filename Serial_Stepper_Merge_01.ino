#include <Stepper.h>
 
 const int stepsPerRevolution = 48;  // change this to fit the number of steps per revolution
                          // for your motor
 int comanda = 0; 
 int comandafin = 0; 
 //int Stanga;
 //int Dreapta;
 //int Sus;
 //int Jos;
 
 // initialize the stepper library on the motor shield
 Stepper myStepperX(stepsPerRevolution, 9, 10, 11 ,12);
 Stepper myStepperZ(stepsPerRevolution, 3, 4, 5, 6); 
 
 // give the motor control pins names:
 const int En2A = 2; 
 const int En2B = 7;
 const int EnA = 8;
 const int EnB = 13;
 

void setup() {
 Serial.begin(9600);
 // set the PWM and brake pins so that the direction pins  // can be used to control the motor:
 pinMode(EnA, OUTPUT);
 pinMode(EnB, OUTPUT);
 pinMode(En2A, OUTPUT);
 pinMode(En2B, OUTPUT);
 
 digitalWrite(EnA, HIGH);
 digitalWrite(EnB, HIGH);
 digitalWrite(En2A, HIGH);
 digitalWrite(En2B, HIGH);
 // initialize the serial port:

 // set the motor speed (for multiple steps only):
 myStepperX.setSpeed(250);
 myStepperZ.setSpeed(250);
 }

 
 void loop() {
 
  //myStepper.step(500);
  //delay(500);
  //myStepper.step(-500);
  //myStepper2.step(500);
  //delay(500);
  //myStepper2.step(-500);
 
 
 
 }
 void serialEvent()
 {
   if(Serial.available() )
  {
    comanda = Serial.read();
    comandafin = comanda - '0';
    Serial.print("Received: ");
    Serial.print(comandafin);
    if (comandafin == 4)
    {
      MotorSt();
      Serial.println(" =>  Stanga");
    }
   
    if (comandafin == 6)
    {
      MotorDr();
      Serial.println(" =>  Dreapta");
    }
   
    if (comandafin == 8)
    {
      MotorFt();
      Serial.println(" =>  Fata");
    }
    
    if(comandafin == 2)
    
    {
      MotorSp();
      Serial.println(" =>  Spate");
    }
    
    if(comandafin == 7)
    {
      MotorFt();
      MotorSt();
      Serial.println(" => Stanga Fata");
    }
    if(comandafin == 9)
    {
      MotorFt();
      MotorDr();
      Serial.println(" => Dreapta Fata");
    }
    
    if(comandafin == 3)
    {
      MotorSp();
      MotorDr();
      Serial.println(" => Dreapta Spate");
    }
    
    if(comandafin == 1)
    {
      MotorSp();
      MotorSt();
      Serial.println(" => Stanga Spate");
    }
    
    
     if(comandafin != 1)
    {
      comandafin = 0;
    }
  }
}

void MotorDr()
{
  myStepperZ.step(-25);
}

void MotorSt()
{
  myStepperZ.step(25);
}

void MotorFt()
{
  myStepperX.step(25);
}

void MotorSp()
{
  myStepperX.step(-25);
}

   
