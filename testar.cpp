#include "HoCarrinho.h"

TaskHandle_t task_movimento;
TaskHandle_t task_modulos;
SemaphoreHandle_t xMutex;
volatile bool sinal_entre_nucleos;

void inicializarSistema() {
    Serial.begin(9600);
    SerialBT.begin("Carrinho DualCore");

    xMutex = xSemaphoreCreateMutex();

    xTaskCreatePinnedToCore(Task1code, "task_movimento", 2048, NULL, 1, &task_movimento, 0);
    delay(500);
    xTaskCreatePinnedToCore(Task2code, "task_modulos", 2048, NULL, 1, &task_modulos, 1);
    delay(500);

    Serial.println("Fim Setup");
    delay(2000);
}

//nao testadis
void Carrinho::executarPiscarLED(bool &sinal_entre_nucleos, int ledPin, SemaphoreHandle_t xMutex, void (*piscarLED)(bool, int)) {
    if (xSemaphoreTake(xMutex, (TickType_t)10) == pdTRUE) {
        piscarLED(sinal_entre_nucleos, ledPin);
        xSemaphoreGive(xMutex);
    }
    vTaskDelay(100);
}

Carrinho::Carrinho(int p1, int p2, int p3, int p4, int p5) {
    pin1 = p1;
    pin2 = p2;
    pin3 = p3;
    pin4 = p4;
    LED = p5;

    //NN TESTADO
    if (pin1 == 0 || pin2 == 0 || pin3 == 0 || pin4 == 0 || LED == 0){
        Serial.println("OS PINOS NAO PODEM SER 0");
        while(1);
    }

    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
    pinMode(pin3, OUTPUT);
    pinMode(pin4, OUTPUT);
    pinMode(LED, OUTPUT);
}

void Carrinho::motor_Esq(int comando) {
    switch (comando) {
        case 1: 
            digitalWrite(pin1, HIGH);
            digitalWrite(pin2, LOW);
            break;
        case 0: 
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, LOW);
            break;
        case -1: 
            digitalWrite(pin1, LOW);
            digitalWrite(pin2, HIGH);
            break;
    }
}

void Carrinho::motor_Dir(int comando) {
    switch (comando) {
        case 1: 
            digitalWrite(pin3, HIGH);
            digitalWrite(pin4, LOW);
            break;
        case 0: 
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, LOW);
            break;
        case -1: 
            digitalWrite(pin3, LOW);
            digitalWrite(pin4, HIGH);
            break;
    }
}
