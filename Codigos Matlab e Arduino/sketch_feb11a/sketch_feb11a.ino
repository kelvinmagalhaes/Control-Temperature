
const int LM35 = A1; // Define o pino que lera a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  int val = analogRead(0);
  Serial.println(val);
  analogWrite(9,255);
  
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  delay(2000);
}
