
#include <Arduino.h>
#include <LED.h>

Led led1(45); 
const char pinBotao = 0;
void setup() 
{
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop() 
{
  led1.update();
  bool estadoAtualBotao = digitalRead(pinBotao);
  static bool estadoAnteriorBotao = true;

  if (estadoAnteriorBotao && !estadoAtualBotao)
  {
    led1.alternar(); //Muda o estado do botão entre ligado e desligado. 
  }
 estadoAnteriorBotao = estadoAtualBotao; 
}