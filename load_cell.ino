#include "HX711.h"  
#define DOUT  4
#define CLK  5
 
HX711 celula(DOUT, CLK);
 
void setup() 
{
  Serial.begin(115200);
  
  celula.set_scale(); //Inicia a escala
  celula.tare(); //Tara a escala
  
  inicio();
  
}

void loop() 
{
  if(Serial.available())
  {
    Serial.println("Deseja calibrar novamente? Digite 1 para sim e 2 para não");
    char t = Serial.read();
    if(t=='1')
    {
      calibragem();
    }
    else
      Serial.println(celula.get_units(10));
  }

  delay(100);
}

void inicio()
{
  Serial.println("Pressione 1 para calibrar, 2 para ler valores");
  if(Serial.available())
  {
    char t = Serial.read();
    switch(t)
    {
      case 1:
        calibragem();
        break;
      case 2:
        break;
    }
  }  
}
void calibragem()
{
  if(Serial.available())
  {
    int valor = Serial.readStringUntil("\n").toInt();
    celula.set_scale(valor);
    Serial.println(celula.get_units(10));
  }
}

