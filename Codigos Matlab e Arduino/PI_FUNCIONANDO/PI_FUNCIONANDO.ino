/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>

//Define Variables we'll be connecting to
double Setpoint, Input, Output;
int tempset=40;
const int LM35=A0;
float Kp= 200;
float Ki= 0;
float Kd= 0;

//Specify the links and initial tuning parameters
PID myPID(&Input, &Output, &Setpoint,Kp,Ki,Kd, REVERSE);
float temperatura;
int fan =9;


void setup()
{
  Serial.begin(9600);
  Input=(float(analogRead(LM35))*5/(1023))/0.01;
  //initialize the variables we're linked to
  myPID.SetMode(AUTOMATIC);
}

void loop()
{
  Setpoint= tempset;
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Input = temperatura;
  myPID.Compute();
  analogWrite(9,Output);
  int saida = map(Output, 0,65,0,255);
  //int velocidade = map(temperatura, 24,50,0,255);
  Serial.print(saida/10);
//  Serial.print('%');
  Serial.print(' ');
  Serial.println(temperatura);
  delay(100);
}
