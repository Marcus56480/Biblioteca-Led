#include "LED.h"

Led::Led(uint8_t pin) :
pino(pin), 
estado(LOW),
desligarNoMomento(0),
tempoAnteriorPiscar(0),
tempoEspera(0),
estadoPiscar(false),
repeticoes(0)

{
    pinMode(pino, OUTPUT);
}

void Led::ligar()
{
    reset();
    estado = HIGH;
}

void Led::ligar(uint32_t tempoligado_ms)
{
    estadoPiscar = false;
    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = millis() + tempoligado_ms;
}

void Led::desligar()
{
    reset();
    estado = LOW;
}

void Led::alternar()
{
    estado = !estado;
}

void Led::update()
{
    if(desligarPorTempo)
        funcaoDesligamento();
    

    if (estadoPiscar)
        funcaoPiscar();

    digitalWrite(pino, estado);
}

bool Led::getEstado()
{
    return estado;
}

uint8_t Led::getPino()
{
    return pino;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
    reset();
}

void Led::piscar()
{
    desligarPorTempo = false;
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led::piscar(float frequencia)
{
    desligarPorTempo = false;
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led::piscar(float frequencia, uint16_t repeticoes)
{
    desligarPorTempo = false;
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
}

void Led::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();

        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

void Led::reset()
{
    estadoPiscar = false;
    desligarPorTempo = false;
}

void Led::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
            estado = LOW;
            desligarPorTempo = false;
    }
}
