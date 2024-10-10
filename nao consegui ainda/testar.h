#ifndef CARRINHO_H
#define CARRINHO_H

#include <Arduino.h>
#include "BluetoothSerial.h"
 
#define PARAMETROS SerialBT, comando, xMutex, sinal_entre_nucleos

extern BluetoothSerial SerialBT;

extern SemaphoreHandle_t xMutex;
extern TaskHandle_t task_movimento;
extern TaskHandle_t task_modulos;
extern volatile bool sinal_entre_nucleos;

 
void inicializarSistema(); 
void movimentar(void *pvParameters); 

//TESTAR SE EH DENTRO OU FORA
//void nucleosControle(BluetoothSerial &SerialBT, char &comando, SemaphoreHandle_t xMutex, bool &sinal_entre_nucleos);
//void executarPiscarLED(bool &sinal_entre_nucleos, int ledPin, SemaphoreHandle_t xMutex, void (*piscarLED)(bool, int));

class Carrinho {
public:
    Carrinho(int p1, int p2, int p3, int p4, int p5);
    void motor_Esq(int comando);
    void motor_Dir(int comando);

    //nao testados
    void nucleosControle(BluetoothSerial &SerialBT, char &comando, SemaphoreHandle_t xMutex, bool &sinal_entre_nucleos);
    void executarPiscarLED(bool &sinal_entre_nucleos, int ledPin, SemaphoreHandle_t xMutex, void (*piscarLED)(bool, int));

private:
    int pin1, pin2, pin3, pin4, LED;
};

#endif
