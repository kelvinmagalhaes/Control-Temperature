#include <dht.h>
// DTH22
dht DHT; // Cria um objeto da classe dht

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{ 
  float tempDHT=0,humDHT=0;
     DHT.read22(A0); // chama método de leitura da classe dht, com o pino de transmissão de dados ligado no pino A1
     tempDHT = DHT.temperature;
     humDHT = DHT.humidity;
     Serial.print(tempDHT);
     Serial.print("      ");  
     Serial.println(humDHT);  
     
     analogWrite(9,0);//Controle motor 100%
     analogWrite(10,0);//Controle Lampada - controle invertido 0 eh 100%

     //analogWrite(9,153);//Controle motor 60%
     //analogWrite(10,102);//Controle Lampada 60%

     //analogWrite(9,102);//Controle motor 60%
     //analogWrite(10,153);//Controle Lampada 60%

}
