
#include <Arduino.h>
#include <LED.h>

Led led1(45); 

void setup() 
{
  led1.piscar(20); //Apenas a frequencia é necessaria como parametro, ou seja, sem tempo definido para desligar
}

void loop() 
{
  led1.update();
}