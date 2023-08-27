#ifndef __SETUP_H
#define __SETUP_H


// pinagem de cada segmentos
//GPIO2_7
#define SEG_A                               7 
//GPIO2_9     
#define SEG_B                               9
//GPIO2_11
#define SEG_C                               11
//GPIO2_13
#define SEG_D                               13
//GPIO2_15
#define SEG_E                               15
//GPIO2_16
#define SEG_F                               16
//GPIO2_17
#define SEG_G                               17


//pinagem dos leds
//gpio1_1
#define LED_1                               1
//gpio1_2
#define LED_2                               2
//gpio1_3
#define LED_3                               3
//gpio1_4
#define LED_4                               4
//gpio1_5
#define LED_5                               5
//gpio1_6
#define LED_6                               6

void display7Seg(unsigned int number);
void displayConfig();
void ledConfig();
void gpioSetup();
void start();
int modo1(unsigned int points, int TIME);
int modo2(unsigned int points, int TIME);
int modo3(unsigned int points, int TIME);
int modo4(unsigned int points, int TIME);
void winner(unsigned int P1, unsigned int P2);
void setFalse();
#endif