
#include <Arduino.h>
#include <LED.h>

Led led1(45); 
void setup() 
{
  led1.piscar(10, 40); // LED pisca com frequencia e quantidade de vezes (respectivamnente) determinada
}

void loop() 
{
  led1.update();
}