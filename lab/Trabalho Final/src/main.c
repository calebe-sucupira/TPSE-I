#include "../inc/gpio.h"
#include "../inc/uart.h"
#include "../inc/gpio.h"
#include "../inc/timer.h"
#include "../inc/interrupt.h"
#include "../inc/setup.h"

int main(void){
	WDTimerDisable();
    DMTimerSetUp();
    uartInitModule(UART0, 115200, STOP1, PARITY_NONE, FLOW_OFF);
    gpioSetup();
    displayConfig();
    ledConfig();

    int TIME = 0;
    unsigned int pointsP1 = 0;
    unsigned int pointsP2 = 0;
    unsigned int points = 0;
    unsigned int modo = 0;
    unsigned int game = 0;

    while (1){
        if(game == 0){
            display7Seg(80);
            Delay(400);
            display7Seg(1);
            Delay(400);
        }
        if(game == 1){
            display7Seg(80);
            Delay(400);
            display7Seg(2);
            Delay(400);
        }
        if(getFlag_gpio3A()) {
            start();
            display7Seg(0);
            points = 0;
            modo++;
            game++;
            if(game < 3){
                if(modo == 1) { 
                  points = modo1(points, TIME);
                }
                else if(modo == 2) {
                  points =  modo2(points, TIME);
                }
                else if(modo == 3) {
                   points = modo3(points, TIME);
                    
                }
                else if(modo == 4) {
                   points = modo4(points, TIME);
                    modo = 0;
                }
            }
            if(game == 1) {
                pointsP1 = points;
            }
            else{
                pointsP2 = points;
                winner(pointsP1, pointsP2);
                pointsP1 = 0;
                pointsP2 = 0;
                game = 0;
            }
            setFlag_gpio3A(false);
        }
        
    }
    
	return(0);
} 


