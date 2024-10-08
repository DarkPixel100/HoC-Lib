#include "HoCarrinho.h"

#define pin1 17   
#define pin2 /*complete*/   18                  /*isso nao aparecerá para as crianças*/
#define pin3 /*complete*/   19 //NAO TA INDO
#define pin4 /*complete*/   23 
#define LED /*complete*/    4

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
        meuCarrinho.nucleosControle(PARAMETROS); // ta na biblioteca o define//PARAMETROS = SerialBT, comando, xMutex, ligar_LED

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

void piscarLED(bool ligar_LED, int ledPin) {
    if (ligar_LED) { 
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

/*FUNÇÃO QUE AS CRIANÇAS VAO RECEBER*/ 

void movimentar(void * pvParameters) {
    Serial.println(xPortGetCoreID());

    for (;;) {
        meuCarrinho.nucleosControle(PARAMETROS);

        if (comando == 'F') { //FRENTE
            meuCarrinho.motor_Esq(1);
            meuCarrinho.motor_Dir(1);
        } 

        else if (comando == 'S') { //PARA


        } 

        else if (comando == 'B') { //RÉ


        } 

        else if (comando == 'R' || comando == 'E') { //FRETE DIREITA


        } 

        else if (comando == 'Q' || comando == 'L') { //FRENTE ESQUERDA


        } 

        else if (comando == 'C') { //RÉ DIREITA


        } 

        else if (comando == 'Z') {//RÉ ESQUERDA
            meuCarrinho.motor_Esq(-1);
            meuCarrinho.motor_Dir(0);
        }  
        vTaskDelay(100);
    }
}

void piscarLED(bool ligar_LED, int ledPin) {
    if (ligar_LED) { 
    /*****************************************************/
    /*       ESCREVA OQ OS ACESSÓRIOS VAO FAZER          */
    /*                                                   */
    /* Lembre-se de usar:                                */
    /*  - digitalWrite(ledPin, HIGH) para ligar          */
    /*  - digitalWrite(ledPin, LOW) para desligar        */
    /*  - delay(tempo de sua escolha) para dar uma pausa */
    /*****************************************************/
    } else {
        digitalWrite(ledPin, LOW);
        delay(50);
    }
}


    /******************************/  
    /*         ___________        */
    /*        //  ||\ \   \       */
    /*    ___//___||_\ \___\      */
    /*   |  _            -_  |    */
    /*   '-(_)--(_)--(_)--(_)-'   */
    /*       VRUMMMMMMMMMMM       */
    /******************************/


