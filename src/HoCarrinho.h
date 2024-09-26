#include <Arduino.h>
#include "BluetoothSerial.h"


// #include <cstdint>
#ifndef HoCarrinho_h
#define HoCarrinho_h

class Carrinho {
  public:
   uint8_t pin1;
   uint8_t pin2;
   uint8_t pin3;
   uint8_t pin4;

  Carrinho(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4);
    void setup();
    void motor_Esq(int i);
    void motor_Dir(int i);
    
   /*
    void mEsqFrente();
    void mEsqPara();
    void mEsqTras();
    void mDirFrente();
    void mDirPara();
    void mDirTras();
  */
  private:
   unsigned int read(uint8_t und = 0);
};

#endif
