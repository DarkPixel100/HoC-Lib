#include "HoCarrinho.h"

#define pin1 17   
#define pin2 18 
#define pin3 19 //NAO TA INDO
#define pin4 23 
#define LED 4

//nao deixar o define ser 0

BluetoothSerial SerialBT;

volatile char comando;

Carrinho meuCarrinho(pin1, pin2, pin3, pin4, LED);  


void setup() {
    inicializarSistema();
}

void Task1code(void * pvParameters) {
    Serial.print("tarefa 1 rodando no core ");
    Serial.println(xPortGetCoreID());

    for (;;) {
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
        vTaskDelay(100);
        
    }
}

void Task2code(void * pvParameters) {
    Serial.print("tarefa 2 rodando no core: ");
    Serial.println(xPortGetCoreID());

    for (;;) {
        if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
            if (sinal_entre_nucleos) { 
                //FORMA QUE VAI FICAR LIGADO ou PISCAR
                digitalWrite(LED, HIGH);
                delay(200);
                digitalWrite(LED, LOW);
                delay(200);
            } else {
                digitalWrite(LED, LOW);
                delay(50);
            }
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(100);
    }
}

void loop() {
}
