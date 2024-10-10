#ifndef CARRINHO_H
#define CARRINHO_H

#include <Arduino.h>
#include "BluetoothSerial.h"
 
extern BluetoothSerial SerialBT;

extern SemaphoreHandle_t xMutex;
extern TaskHandle_t task_movimento;
extern TaskHandle_t task_modulos;
extern volatile bool sinal_entre_nucleos;

 
void inicializarSistema(); 
void Task1code(void *pvParameters); 
void Task2code(void *pvParameters);

class Carrinho {
public:
    Carrinho(int p1, int p2, int p3, int p4, int p5);
    void motor_Esq(int comando);
    void motor_Dir(int comando);
    
private:
    int pin1, pin2, pin3, pin4, LED;
};

#endif
