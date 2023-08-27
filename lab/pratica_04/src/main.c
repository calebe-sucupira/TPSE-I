#include "../inc/gpio.h"
#include "../inc/uart.h"
#include "../inc/gpio.h"
#include "../inc/timer.h"
#include "../inc/interrupt.h"

int TimeDelay(char op);
void butConfig();
void ledConfig();

int main(void){
	unsigned int count = 0;
    char typeTimer;
    int TIME = 1000;
    char DELAY;

	WDTimerDisable();
	uartInitModule(UART0, 115200, STOP1, PARITY_NONE, FLOW_OFF);

    
    butConfig();
    ledConfig();


    uartPutString(UART0,"Escolha o tipo do Delay: \r\n",27);
    uartPutString(UART0,"0 - Polling: \r\n",15);
    uartPutString(UART0,"1 - Interrupt: \r\n",17);
	typeTimer = uartGetC(UART0);
    uartPutC(UART0, typeTimer);

    DMTimerSetUp();
    timerIntSetup(95);

    while (1){
        if(getFlag_gpio1A()){
            uartPutString(UART0,"Escolha o tempo: \r\n",19);
            uartPutString(UART0,"0 - 50ms: \r\n",13);
            uartPutString(UART0,"1 - 100ms: \r\n",13);
            uartPutString(UART0,"2 - 500ms: \r\n",13);
            uartPutString(UART0,"3 - 1000ms: \r\n",14);
            DELAY = uartGetC(UART0);
            uartPutC(UART0, DELAY);
            TIME = TimeDelay(DELAY);
            setFlag_gpio1A(false);
        }
        if(getFlag_gpio1B()){
            count++;
            if(count == 1) {
                ledON(GPIO2,1);
				Delay(TIME,typeTimer);
				ledOFF(GPIO2,1);
				Delay(TIME,typeTimer);
                ledON(GPIO2,3);
				Delay(TIME,typeTimer);
				ledOFF(GPIO2,3);
				Delay(TIME,typeTimer);
                ledON(GPIO2,4);
				Delay(TIME,typeTimer);
				ledOFF(GPIO2,4);
				Delay(TIME,typeTimer);
                setFlag_gpio1B(false);
            }
            if(count == 2) {
                ledON(GPIO2,1);
				Delay(TIME,typeTimer);
                ledON(GPIO2,3);
				Delay(TIME,typeTimer);
                ledON(GPIO2,4);
				Delay(TIME,typeTimer);
                ledOFF(GPIO2,1);
				Delay(TIME,typeTimer);
                ledOFF(GPIO2,3);
				Delay(TIME,typeTimer);
				ledOFF(GPIO2,4);
                Delay(TIME,typeTimer);
                setFlag_gpio1B(false);
            }
            if(count == 3) {
                ledON(GPIO2,4);
				Delay(TIME,typeTimer);
                ledON(GPIO2,3);
				Delay(TIME,typeTimer);
                ledON(GPIO2,1);
				Delay(TIME,typeTimer);
                ledOFF(GPIO2,4);
                Delay(TIME,typeTimer);
                ledOFF(GPIO2,3);
				Delay(TIME,typeTimer);
                ledOFF(GPIO2,1);
				Delay(TIME,typeTimer);
                setFlag_gpio1B(false);
                count = 0;
            }
        }
    }
	return(0);
} 

void butConfig(){

    gpioInitModule(GPIO1);
 
    gpioIntSetup(98);
    gpioIntSetup(99);

    
    gpioPinMuxSetup(GPIO1,16);
    setFlag_gpio1A(false);
    settingIntGpioA(GPIO1,16);

    gpioPinMuxSetup(GPIO1,28);
    gpioSetDirection(GPIO1,28,INPUT);
    setFlag_gpio1B(false);
    settingIntGpioB(GPIO1,28);
    
}
void ledConfig(){
    gpioInitModule(GPIO2);
    gpioPinMuxSetup(GPIO2,1);
    gpioPinMuxSetup(GPIO2,3);
    gpioPinMuxSetup(GPIO2,4);

    gpioSetDirection(GPIO2,1,OUTPUT);
    gpioSetDirection(GPIO2,3,OUTPUT);
    gpioSetDirection(GPIO2,4,OUTPUT);
}

int TimeDelay(char op){
    switch (op){
    case '0':
        return 50;
        break;
    case '1':
        return 100;
        break;
    case '2':
        return 500;
        break;
    case '3':
        return 1000;
        break;
    }
}
