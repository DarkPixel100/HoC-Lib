#include "HoCarrinho.h"

Carrinho::Carrinho(uint8_t p1, uint8_t p2, uint8_t p3, uint8_t p4) {
  pin1 = p1;
  pin2 = p2;
  pin3 = p3;
  pin4 = p4;
}

void Carrinho::setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void Carrinho::mEsqFrente() {
  digitalWrite(pin1, HIGH);
  digitalWrite(pin2, LOW);
}

void Carrinho::mEsqPara() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
}

void Carrinho::mEsqTras() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, HIGH);
}

void Carrinho::mDirFrente() {
  digitalWrite(pin3, HIGH);
  digitalWrite(pin4, LOW);
}

void Carrinho::mDirPara() {
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, LOW);
}

void Carrinho::mDirTras() {
  digitalWrite(pin3, LOW);
  digitalWrite(pin4, HIGH);
}