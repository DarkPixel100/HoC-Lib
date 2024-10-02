#
# COMO O CARRINHO FUNCIONA

O carrinho funciona da seguinte forma: 
- O motor esquerdo é controlado pelo pino pin1 e pin2.
- O motor direito é controlado pelo pino pin3 e pin4.
    
A direção dos motores é definida pela variável i.

i = 1 significa que o motor é para frente.

    pin[impar] HIGH
    pin[par] LOW

i = 0 significa que o motor é parado.

    pin[impar] LOW
    pin[par] LOW

i = -1 significa que o motor é para trás.

    pin[impar] LOW
    pin[par] HIGH

Dessa forma, a criança deverá configurar os possiveis movimentos que o carrinho pode fazer, na seguinte estrutura:

    meuCarrinho.motor_Esq(i);
    meuCarrinho.motor_Dir(i);

#
# COMO COLOCAR A BIBLIOTECA NO ARDUINO

1- Compactar a pasta biblioteca_HoCarrinhos para um arquivo zip

2- No arduino IDE 

    2.1- Clicar em sketch 
    2.2- Clicar em Include library
    2.3- Clicar em Add .ZIP library
    2.4- Selecionar a biblioteca zipada

![alt text](image-1.png)

3- Pronto!
#