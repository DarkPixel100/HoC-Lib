#include "HoCarrinho.h"

#define pin1 17   
#define pin2 18 
#define pin3 19 //NAO TA INDO
#define pin4 23 
#define LED 4

BluetoothSerial SerialBT;

volatile char comando;

Carrinho meuCarrinho(pin1, pin2, pin3, pin4, LED);  

void setup() {
    inicializarSistema();
}

void movimentar(void * pvParameters) {
    Serial.println(xPortGetCoreID());

    for (;;) {
        //NAO TESTADO
        meuCarrinho.nucleosControle(PARAMETROS); // ta na biblioteca o define//PARAMETROS = SerialBT, comando, xMutex, sinal_entre_nucleos

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

//nao testado
void piscarLED(bool sinal_entre_nucleos, int ledPin) {
    if (sinal_entre_nucleos) { 
        digitalWrite(ledPin, HIGH);
        delay(200);
        digitalWrite(ledPin, LOW);
        delay(200);
    } else {
        digitalWrite(ledPin, LOW);
        delay(50);
    }
}

void loop() {
}
