
#include <Arduino.h>
#include <LED.h>

Led led1(45); 
const char pinBotao = 0;
void setup() 
{
  led1.piscar(10, 40); //Função com parametros de frequencia(hz) e tempo(Segundos).
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop() 
{
  led1.update();
  bool estadoAtualBotao = digitalRead(pinBotao);
  static bool estadoAnteriorBotao = true;

  if (estadoAnteriorBotao && !estadoAtualBotao)
  {
    led1.desligar(); // Led desliga depois do acionamento do botão.
  }
 estadoAnteriorBotao = estadoAtualBotao; 
}