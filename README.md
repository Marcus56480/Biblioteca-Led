# Biblioteca para controle de Led

A presente biblioteca é uma forma simples de controle de LEDs realizada de forma não bloqueante para Arduino e ESP32.

A biblioteca tem as seguintes funcionalidades:

- Ligar e desligar o LED
- Ligar por um tempo determinado 
- Alternar estado 
- Piscar continuamente
- Piscar uma quantidade definida de vezes 

Para pleno funcionamento é necessario que o método `update()` seja chamado repetidamente dentro do `loop()`.

## Autores

- [@marcus56480](https://github.com/Marcus56480)
## Estrutura da biblioteca 

`````text
LED/
├── library.json
├── README.md
├── LICENSE
├── src/
│   ├── LED.h
│   └── LED.cpp
└── examples/


