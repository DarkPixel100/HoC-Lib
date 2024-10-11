#include "HoCarrinho.h"


#define pin1 17   
#define pin2 18 
#define pin3 19 //NAO TA INDO
#define pin4 23 
#define LED 4
#define LED2 22
#define FAROL 21

//nao deixar o define ser 0

BluetoothSerial SerialBT;

volatile char comando;

Carrinho meuCarrinho(pin1, pin2, pin3, pin4, LED);


void setup() {
    inicializarSistema();
    Serial.println("Mudouou x3 adInfinitum final agoraVai Ladinho SuperSsom2 noMore");
    pinMode(LED2, OUTPUT);
    pinMode(FAROL, OUTPUT);
}

void Task1code(void * pvParameters) {
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
            Serial.println("Siga em frente");
        } 

        else if (comando == 'S') { //PARA
            meuCarrinho.motor_Esq(0);
            meuCarrinho.motor_Dir(0);
            Serial.println("Pare agora");
        } 

        else if (comando == 'B') { //RÉ
            meuCarrinho.motor_Esq(-1);
            meuCarrinho.motor_Dir(-1);
            Serial.println("dó RÉ mi fá sol lá si");
        } 

        else if (comando == 'R' || comando == 'E') { //FRETE DIREITA
            meuCarrinho.motor_Esq(0);
            meuCarrinho.motor_Dir(1);
            Serial.println("Bolsanaro é norte é nordeste");
        } 

        else if (comando == 'Q' || comando == 'L') { //FRENTE ESQUERDA
            meuCarrinho.motor_Esq(1);
            meuCarrinho.motor_Dir(0);
            Serial.println("ole ole ola LULA LULA");
        } 

        else if (comando == 'C') { //RÉ DIREITA
            meuCarrinho.motor_Esq(0);
            meuCarrinho.motor_Dir(-1);
            Serial.println("direitorges");
        } 

        else if (comando == 'Z') {//RÉ ESQUERDA
            meuCarrinho.motor_Esq(-1);
            meuCarrinho.motor_Dir(0);
            Serial.println("esquerdorges");
        }  

        else if (comando == 'N') {
          Serial.println("Ninho, Jun");
          digitalWrite(FAROL, HIGH);
        }

        else if (comando == 'n') {
          Serial.println("Ninho, Jun");
          digitalWrite(FAROL, LOW);
        }

        vTaskDelay(100);
        
    }
}

void Task2code(void * pvParameters) {
    Serial.println(xPortGetCoreID());

    for (;;) {
        if (xSemaphoreTake(xMutex, (TickType_t) 10) == pdTRUE) {
            if (sinal_entre_nucleos) { 
                //FORMA QUE VAI FICAR LIGADO ou PISCAR
                digitalWrite(LED, HIGH);
                digitalWrite(LED2, LOW);
                delay(200);
                digitalWrite(LED, LOW);
                digitalWrite(LED2, HIGH);
                delay(200);
            } else {
                digitalWrite(LED, LOW);
                digitalWrite(LED2, LOW);
                delay(50);
            }
            xSemaphoreGive(xMutex);
        }
        vTaskDelay(100);
    }
}

void loop() {
}
