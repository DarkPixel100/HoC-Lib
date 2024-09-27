#include "HoCarrinho.h"

// Define e inicializa o carrinho nos pinos pin1, pin2, pin3, pin4
#define pin1 23
#define pin2 22
#define pin3 21
#define pin4 19
Carrinho meuCarrinho(pin1, pin2, pin3, pin4);
//Será que dá pra deixar eles verem o hardware e definirem os pinos? ou complica muito? 
//Se for complicar muito, a gente coloca na biblioteca, mas acho que seria legal

char comando;

void setup() {
  meuCarrinho.setup();
}

void loop() {

  /* O carrinho funciona da seguinte forma: 
    - O motor esquerdo é controlado pelo pino pin1 e pin2.
    - O motor direito é controlado pelo pino pin3 e pin4.
    
    A direção dos motores é definida pela variável i.
    i = 1 significa que o motor é para frente.
    i = 0 significa que o motor é parado.
    i = -1 significa que o motor é para trás.

    Dessa forma, a criança deverá configurar a forma com que o carrinho vai se mover, na seguinte estrutura:
      meuCarrinho.motor_Esq(i);
      meuCarrinho.motor_Dir(i);
   */
  if (SerialBT.available()) {
    comando = SerialBT.read();
  }


  switch (comando) {

    case 'F':{// Frente reto
      meuCarrinho.motor_Esq(1);
      meuCarrinho.motor_Dir(1);
      break;
    }
  
    case 'S':{// Para o carrinho 
      meuCarrinho.motor_Esq(0);
      meuCarrinho.motor_Dir(0);
      break;
    }  

    case 'R':{// Ré reto
      meuCarrinho.motor_Esq(-1);
      meuCarrinho.motor_Dir(-1);  
      break;
    }

    case 'C':{// Frente direita
      meuCarrinho.motor_Esq(0);
      meuCarrinho.motor_Dir(1);
      break;
    }
  
    case 'Q':{// Frente esquerda
      meuCarrinho.motor_Esq(1);
      meuCarrinho.motor_Dir(0);
      break;
    }

    case 'E':{// Ré direita
      meuCarrinho.motor_Esq(0);
      meuCarrinho.motor_Dir(-1);
 
      break;
    }

    case 'Z':{// Ré esquerda
      meuCarrinho.motor_Esq(-1);
      meuCarrinho.motor_Dir(0);
      break;
    }

    default:
      break;
  } 
}