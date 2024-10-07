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

        switch (comando) {
            case 'F': { //FRENTE
                meuCarrinho.motor_Esq(1);
                meuCarrinho.motor_Dir(1);
                break;
            }
            case 'S': {//PARA
                meuCarrinho.motor_Esq(0);
                meuCarrinho.motor_Dir(0);
                break;
            }
            case 'B': {//RÉ
                meuCarrinho.motor_Esq(-1);
                meuCarrinho.motor_Dir(-1);
                break;
            }
            case 'R': case 'E': {//FRETE DIREITA
                meuCarrinho.motor_Esq(0);
                meuCarrinho.motor_Dir(1);
                break;
            }
            case 'Q': case 'L': {//FRENTE ESQUERDA
                meuCarrinho.motor_Esq(1);
                meuCarrinho.motor_Dir(0);
                break;
            }
            case 'C': {//RÉ DIREITA
                meuCarrinho.motor_Esq(0);
                meuCarrinho.motor_Dir(-1);
                break;
            }
            case 'Z': {//RÉ ESQUERDA
                meuCarrinho.motor_Esq(-1);
                meuCarrinho.motor_Dir(0);
                break;
            }
            default:
                break;
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
