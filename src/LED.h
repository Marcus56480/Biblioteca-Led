#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um Led.
 * Permite ligar, desligar, ligar por tempo determinado, 
 * piscar continuamente e piscar por quantidade definida.
 * 
 * @note O método Update deve ser chamado continuamente dentro 
 * do loop().
 */
class Led
{
    private:
        uint8_t pino;
        bool estado; 
        bool desligarPorTempo = false;
        uint32_t desligarNoMomento;
        void funcaoPiscar(); 
        /**
         * @brief Processa a logica de piscada do LED.
         */

        uint32_t tempoAnteriorPiscar;
        uint32_t tempoEspera;
        bool estadoPiscar;
        uint16_t repeticoes;
        /**
         * @brief Reseta o estado anterior do Led
         */       
        void reset();
        void funcaoDesligamento();
        /**
         * @brief Processa o desligamento temporizado.
         */

    public: 
    /**
     * @brief Constroi um objeto Led.
     * @param pin Número do pino digital onde o Led está conectado.
     */
        Led(uint8_t pin); 
      
        /**
         * @brief Liga o Led continuamente.
         */
        
         void ligar();
        /**
         * @brief Liga o Led por um tempo determinado.
         * @param tempoligado_ms Tempo, em millisegundos, que o Led ficará ligado.
         */
        void ligar(uint32_t tempoLigado_ms);

        /**
         * @brief Desliga o LED e cancela os modos automáticos.
         */
        void desligar();

        /**
         * @brief Inicia a piscada contínua em um 1 hz.
         */
        void piscar();

        /**
         * @brief Inicia a piscada do Led com uma frequencia determinada.
         * @param frequencia Frequencia da piscada em hz.
         */
        void piscar(float frequencia);

        /**
         * @brief Pisca o LED uma quantidade definida de vezes.
         * @param frequencia Frequencia da piscada em hz.
         * @param repeticoes Quantidade de piscadas completas.
         */
        void piscar(float frequencia, uint16_t repeticoes);

        /**
         * @brief Dá ao usuario uma visão do estado do Led sem permitir alterações no atributo. 
         */
        bool getEstado();

        /**
         * @brief Retorna o estado do Pino.
         */
        uint8_t getPino();

        /**
         * @brief Define manualmente o estado do Led.
         * @param estado true para ligado, false para desligado.
         */
        void setEstado(bool estado);

        /**
         * @brief Alterna o estado do Led para ligado ou desligado.
         */
        void alternar();

        /**
         * @brief Atualiza o estado do Led.
         */
        void update();


};

#endif