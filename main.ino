#include "HoCarrinho.h"


#define pin1 17   
#define pin2 18 
#define pin3 19 
#define pin4 23 
#define LED 4
#define LED_2 22
#define FAROL 21

BluetoothSerial SerialBT;

volatile char comando;

Carrinho meuCarrinho(pin1, pin2, pin3, pin4, LED, LED_2, FAROL);


void setup() {
    inicializarSistema();
    Serial.println("Sistema inicializado");
}

void Task1code(void * pvParameters) {
    Serial.println(xPortGetCoreID());

    while(1) {
        if (SerialBT.available()) {
            if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
                comando = SerialBT.read();
                if (comando == 'M') {
                    sinal_entre_nucleos = true;
                } else if (comando == 'm') {
                    sinal_entre_nucleos = false;
                }

                xSemaphoreGive(xMutex);
            }
        }

        if (comando == 'F') { //FRENTE
            meuCarrinho.motor_Esq(1);
            meuCarrinho.motor_Dir(1);
        } 

        else if (comando == 'S') { //PARA
            meuCarrinho.motor_Esq(0);
            meuCarrinho.motor_Dir(0);
        } 

        else if (comando == 'B') { //RÉ
            meuCarrinho.motor_Esq(-1);
            meuCarrinho.motor_Dir(-1);
        } 

        else if (comando == 'R' || comando == 'E') { //FRETE DIREITA
            meuCarrinho.motor_Esq(0);
            meuCarrinho.motor_Dir(1);
        } 

        else if (comando == 'Q' || comando == 'L') { //FRENTE ESQUERDA
            meuCarrinho.motor_Esq(1);
            meuCarrinho.motor_Dir(0);
        } 

        else if (comando == 'C') { //RÉ DIREITA
            meuCarrinho.motor_Esq(0);
            meuCarrinho.motor_Dir(-1);
        } 

        else if (comando == 'Z') {//RÉ ESQUERDA
            meuCarrinho.motor_Esq(-1);
            meuCarrinho.motor_Dir(0);
        }  

        else if (comando == 'N') {
          digitalWrite(FAROL, HIGH);
        }

        else if (comando == 'n') {
          digitalWrite(FAROL, LOW);
        }

        vTaskDelay(100);      
    }
}

void Task2code(void * pvParameters) {
    Serial.println(xPortGetCoreID());

    while(1) {
        if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
            if (sinal_entre_nucleos) { 
                digitalWrite(LED, HIGH);
                digitalWrite(LED_2, LOW);
                delay(200);
                digitalWrite(LED, LOW);
                digitalWrite(LED_2, HIGH);
                delay(200);
            } 
            else {
                digitalWrite(LED, LOW);
                digitalWrite(LED_2, LOW);
                delay(50);
            }
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(100);
    }
}

void loop() {
}
