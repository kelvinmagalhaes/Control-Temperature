class PID{
public:
  
  double error, errorP;
  double sample;
  double lastSample;
  double kP, kI, kD, b=1.0, c=1.0;      
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
    error = sample - setPoint;
    errorP = sample - setPoint*b;
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

//double A = 0.25*0.25;  //area da estrutura
// double Vmax = 20.63;  // variavel maxima
double Tmax= 75.00;
double setpoint_temp = 39; // temperatura desejada
int controlePwm; // pwm do motor

#define pCONTROLE 9
PID meuPid(-195, 0.02, 12.5);// ajuste Kp,Ti,Td
const int LM35 = A0; // Define o pino que lera a saída do LM35

void setup() 
{
  Serial.begin(9600);
  meuPid.setSetPoint(setpoint_temp);
  meuPid.addNewSample(1000);
  pinMode(pCONTROLE, OUTPUT);
}


void loop() 
{
  
  double temp = (float(analogRead(LM35))*5/(1023))/0.01; // solicitar temperatur do lm35 
  meuPid.addNewSample(temp);
  controlePwm = (meuPid.process());
  analogWrite(pCONTROLE, controlePwm);
  int Pwm = map(controlePwm, 0,65,0,255);
  Serial.println(temp);
  //Serial.print("    ,");
  //Serial.print(setpoint_temp);
  //Serial.print("    ,");
  Serial.println(Pwm/10);
  delay(1000);
}

