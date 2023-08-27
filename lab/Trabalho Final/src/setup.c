#include "../inc/gpio.h"
#include "../inc/setup.h"
#include "../inc/uart.h"
#include "../inc/timer.h"
#include "../inc/interrupt.h"


//função para mostrar na tela 
void display7Seg(unsigned int number){
    switch (number){
    case 0:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledOFF(GPIO2,SEG_G);
        break;
    case 1:
        ledOFF(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledOFF(GPIO2,SEG_F);
        ledOFF(GPIO2,SEG_G);
        break;
    case 2:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledOFF(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledOFF(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 3:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledOFF(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 4:
        ledOFF(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 5:
        ledON(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 6:
        ledON(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 7:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledOFF(GPIO2,SEG_F);
        ledOFF(GPIO2,SEG_G);
        break;
    case 8:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 9:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 10:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 11:
        ledOFF(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 12:
        ledON(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledOFF(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledOFF(GPIO2,SEG_G);
        break;
    case 13:
        ledOFF(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledON(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledOFF(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 14:
        ledON(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledOFF(GPIO2,SEG_C);
        ledON(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 15:
        ledON(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledOFF(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 45:
        ledOFF(GPIO2,SEG_A);
        ledOFF(GPIO2,SEG_B);
        ledOFF(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledOFF(GPIO2,SEG_E);
        ledOFF(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
        break;
    case 80:
        ledON(GPIO2,SEG_A);
        ledON(GPIO2,SEG_B);
        ledOFF(GPIO2,SEG_C);
        ledOFF(GPIO2,SEG_D);
        ledON(GPIO2,SEG_E);
        ledON(GPIO2,SEG_F);
        ledON(GPIO2,SEG_G);
    }
}

//configuração dos pinos para o diplay de 7 segmentos
void displayConfig(){
    gpioPinMuxSetup(GPIO2,SEG_A);
    gpioPinMuxSetup(GPIO2,SEG_B);
    gpioPinMuxSetup(GPIO2,SEG_C);
    gpioPinMuxSetup(GPIO2,SEG_D);
    gpioPinMuxSetup(GPIO2,SEG_E);
    gpioPinMuxSetup(GPIO2,SEG_F);
    gpioPinMuxSetup(GPIO2,SEG_G);

    gpioSetDirection(GPIO2,SEG_A,OUTPUT);
    gpioSetDirection(GPIO2,SEG_B,OUTPUT);
    gpioSetDirection(GPIO2,SEG_C,OUTPUT);
    gpioSetDirection(GPIO2,SEG_D,OUTPUT);
    gpioSetDirection(GPIO2,SEG_E,OUTPUT);
    gpioSetDirection(GPIO2,SEG_F,OUTPUT);
    gpioSetDirection(GPIO2,SEG_G,OUTPUT);
}

//confiração dos botões
void gpioSetup() {
    gpioInitModule(GPIO1);
    gpioIntSetup(98);
    gpioIntSetup(99);

    gpioPinMuxSetup(GPIO1,16);
    gpioSetDirection(GPIO1,16,INPUT);
    setFlag_gpio1A(false);
    settingIntGpioA(GPIO1,16);

    gpioPinMuxSetup(GPIO1,28);
    gpioSetDirection(GPIO1,28,INPUT);
    setFlag_gpio1B(false);
    settingIntGpioB(GPIO1,28);

    gpioInitModule(GPIO2);
    gpioIntSetup(32);
    gpioIntSetup(33);

    gpioPinMuxSetup(GPIO2,3);
    gpioSetDirection(GPIO2,3,INPUT);
    setFlag_gpio2A(false);
    settingIntGpioA(GPIO2,3);

    gpioPinMuxSetup(GPIO2,4);
    gpioSetDirection(GPIO2,4,INPUT);
    setFlag_gpio2B(false);
    settingIntGpioB(GPIO2,4);

    gpioInitModule(GPIO3);
    gpioIntSetup(62);

    gpioPinMuxSetup(GPIO3,19);
    gpioSetDirection(GPIO3,19,INPUT);
    setFlag_gpio3A(false);
    settingIntGpioA(GPIO3,19);

}

//configarção dos leds
void ledConfig(){
    for(int i = 1; i <= 6; i++){
        gpioPinMuxSetup(GPIO1,i);
    }
    for(int i = 1; i <= 7; i++){
        gpioSetDirection(GPIO1,i,OUTPUT);
    }

    for(int i = 1; i <= 6; i++){
        ledOFF(GPIO1,i);
    }

}

//seta em false todas as flags dos botões 
void setFalse() {
    setFlag_gpio1A(false);
    setFlag_gpio1B(false);
    setFlag_gpio2A(false);
    setFlag_gpio2B(false);
}

//contagem regressiva para inicio do jogo
void start() {
    display7Seg(5);
    Delay(1000);
    display7Seg(4);
    Delay(1000);
    display7Seg(3);
    Delay(1000);
    display7Seg(2);
    Delay(1000);
    display7Seg(1);
    ledON(GPIO1, LED_5);
    Delay(1000);
    ledOFF(GPIO1, LED_5);
}

//sequencias dos leds
int modo1(unsigned int points, int TIME) {
    display7Seg(points);
    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(1600);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(350);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(350);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(1600);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(800);

    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(1000);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1000);

    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(1000);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(700);

    ledON(GPIO1, LED_2);
    TIME = getTimerBut2(1000);
    ledOFF(GPIO1, LED_2);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(800);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 700) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 3;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(600);

    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(500);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 400) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 4;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }
    
    uartPutString(UART0,"==========END GAME========== \r\n", 31);
    return points;
}
int modo2(unsigned int points, int TIME) {
    display7Seg(points);
    ledON(GPIO1, LED_2);
    TIME = getTimerBut2(1600);
    ledOFF(GPIO1, LED_2);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(700);

    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(1600);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1000);

    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(1000);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(1000);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(600);

    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(1000);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(800);

    ledON(GPIO1, LED_2);
    TIME = getTimerBut2(800);
    ledOFF(GPIO1, LED_2);
    setFalse();
    if(TIME <= 700) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 3;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(500);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 400) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 4;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    uartPutString(UART0,"==========END GAME========== \r\n", 31);
    return points;
}
int modo3(unsigned int points, int TIME) {
    display7Seg(points);
    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(1600);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1000);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(1600);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(600);

    ledON(GPIO1, LED_2);
    TIME = getTimerBut2(1000);
    ledOFF(GPIO1, LED_2);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(1000);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(1000);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(700);

    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(800);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 700) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 3;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(800);

    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(500);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 400) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 4;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }
    
    uartPutString(UART0,"==========END GAME========== \r\n", 31);
    return points;
}
int modo4(unsigned int points, int TIME) {
    display7Seg(points);
    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(1600);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(800);

    ledON(GPIO1, LED_2);
    TIME = getTimerBut2(1600);
    ledOFF(GPIO1, LED_2);
    setFalse();
    if(TIME <= 1500) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 1;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(350);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(1000);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(600);

    ledON(GPIO1, LED_2);
    TIME = getTimerBut2(1000);
    ledOFF(GPIO1, LED_2);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1500);

    ledON(GPIO1, LED_4);
    TIME = getTimerBut4(1000);
    ledOFF(GPIO1, LED_4);
    setFalse();
    if(TIME <= 900) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 2;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(1000);

    ledON(GPIO1, LED_3);
    TIME = getTimerBut3(800);
    ledOFF(GPIO1, LED_3);
    setFalse();
    if(TIME <= 700) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 3;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }

    Delay(700);

    ledON(GPIO1, LED_1);
    TIME = getTimerBut1(500);
    ledOFF(GPIO1, LED_1);
    setFalse();
    if(TIME <= 400) {
        ledON(GPIO1, LED_5);
        Delay(200);
        ledOFF(GPIO1, LED_5);
        points += 4;
        display7Seg(points);
    }
    else {
        ledON(GPIO1, LED_6);
        Delay(200);
        ledOFF(GPIO1, LED_6);
    }
    
    uartPutString(UART0,"==========END GAME========== \r\n", 31);
    return points;
}

//mostra na uart o jogador que venceu e no diplay a pontuação
void winner(unsigned int P1, unsigned int P2){
    if(P1 > P2) {
        uartPutString(UART0,"JOGADOR 1 É O VENCEDOR! \r\n", 27);
        display7Seg(P1);
    }
    else if(P2 > P1) {
        uartPutString(UART0,"JOGADOR 2 É O VENCEDOR! \r\n", 27);
        display7Seg(P2);
    }
    else {
        uartPutString(UART0,"EMPATE! \r\n", 10);
        display7Seg(45);
    }
}