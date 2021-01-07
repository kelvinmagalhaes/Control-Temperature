class PID{
public:
  
  double error, errorP;
  double sample;
  double lastSample;
  double kP, kI, kD, b, c;      
  double P, I, D;
  double pid;
  
  double setPoint;
  long lastProcess;
  
  PID(double _kP, double _kI, double _kD){
    kP = _kP;
    kI = _kI;
    kD = _kD;
  }

  PID_2DOF(double _kP, double _kI, double _kD, double _b, double _c){
    kP = _kP;
    kI = _kI;
    kD = _kD;
  }
  
  void addNewSample(double _sample){
    sample = _sample;
  }
  
  void setSetPoint(double _setPoint){
    setPoint = _setPoint;
  }
  
  double process(){
    // Implementação P ID
    error = setPoint - sample;
    errorP = setPoint*b - sample;
    float deltaTime = (millis() - lastProcess) / 1000.0;
    lastProcess = millis();
    
    //P
    //P = error * kP;
    P = errorP*kP;
    //I
    I = I + (error * kI) * deltaTime;
    
    //D
    //D = (lastSample - sample) * kD / deltaTime;
    D = (c*lastSample - sample) * kD / deltaTime;
    lastSample = sample;
    
    // Soma tudo
    pid = P + I + D;

    if (pid >=255) pid = 255;
    else if (pid <= 0) pid = 0;

      
    return pid;
  }
};

#include <Ultrasonic.h>
double A = 0.25*0.25;
double Vmax = 20.63;
double setpoint_lvl = 50;
int controlePwm;

#define pino_trigger 4
#define pino_echo 5
#define pCONTROLE 9
#define pCONTROLE1 10

Ultrasonic ultrasonic(pino_trigger, pino_echo);
PID meuPid(100, 5, 5);


void setup() 
{
  Serial.begin(9600);
  meuPid.setSetPoint(setpoint_lvl);
  meuPid.addNewSample(100);
  pinMode(pCONTROLE, OUTPUT);
  pinMode(pCONTROLE1, OUTPUT);
}


void loop() 
{
  
  double h = altura();
  double vol = volume(h, A);
  meuPid.addNewSample(vol);
  controlePwm = (meuPid.process());
  analogWrite(pCONTROLE, controlePwm);
  analogWrite(pCONTROLE1, controlePwm);
  controlePwm = (controlePwm/255)*100; 
  Serial.print(vol);
  Serial.print(",");
  Serial.println(setpoint_lvl);
  
  
   
}

double altura()
{

  double cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = (33-(ultrasonic.convert(microsec, Ultrasonic::CM)))/100; // devolve a altura do volume vázio do tanque
  //cmMsec = (ultrasonic.convert(microsec, Ultrasonic::CM)); // devolve a altura do volume vázio do tanque


  return cmMsec;

}


double volume (double altura, double area)
{
  double Vol;
  //Vol = (0.37 - (altura/100))*(area)*1000;
  Vol = (altura)*(area)*1000;
  Vol = (Vol/Vmax)*100;

  return Vol;
}
