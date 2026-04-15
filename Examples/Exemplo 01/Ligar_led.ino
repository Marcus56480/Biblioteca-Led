#include <Arduino.h>
#include <LED.h>

Led led1(45);
void setup() 
{
  led1.ligar(); // Função usada para ligar o Led.
}

void loop() 
{
  led1.update();
}

