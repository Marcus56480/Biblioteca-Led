
#include <Arduino.h>
#include <LED.h>

Led led1(45); //Classe definida para controle do objeto(LED)
const char pinBotao = 0;
void setup() 
{
  pinMode(pinBotao, INPUT_PULLUP);
}

void loop() 
{
  led1.update(); // É necessario que o update esteja no Loop para verificação constante
  bool estadoAtualBotao = digitalRead(pinBotao);
  static bool estadoAnteriorBotao = HIGH;

  if (estadoAnteriorBotao && !estadoAtualBotao)
  {
    led1.ligar(5000); //Parametro utilizado para monstrar o tempo em millisegundos que ficará ligado
  }
  estadoAnteriorBotao = estadoAtualBotao;
}