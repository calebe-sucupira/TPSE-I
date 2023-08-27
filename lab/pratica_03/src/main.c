#include "../inc/uart.h"
#include "../inc/timer.h"
#include "../inc/gpio.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
//#define TIME 100
/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
void ledON(gpioMod  ,ucPinNumber );
void ledOFF(gpioMod ,ucPinNumber );
double stringToDouble(const char *str);

int main(void){    

	/*-----------------------------------------------------------------------------
     *  Watchdog Timer Diseble    
	*-----------------------------------------------------------------------------*/
    WDTimerDisable();
    
    /*-----------------------------------------------------------------------------
     *  Initialize TIME modules   
	 *-----------------------------------------------------------------------------*/
    DMTimerSetUp();

    /*-----------------------------------------------------------------------------
	 *  initialize UART modules
	 *-----------------------------------------------------------------------------*/
	uartInitModule(UART0, 115200, STOP1, PARITY_NONE, FLOW_OFF);

    char frequency[5];
    double TIME;
    unsigned int count=0;
    unsigned int ledmodeButton2=0;
    ucPinNumber port=21;    
	pinDirection dirOut=OUTPUT;
    pinDirection dirIn=INPUT;

    /*-----------------------------------------------------------------------------     
	 *  initialize GPIO modules
     *-----------------------------------------------------------------------------*/    
	gpioInitModule(GPIO1);
    gpioInitModule(GPIO2);

    /*-----------------------------------------------------------------------------
     *  configure multplex in the pin of mudule     
	 *-----------------------------------------------------------------------------*/
    for(count=port; count<25; count++){        
		gpioPinMuxSetup(GPIO1, count);    
	}
    gpioPinMuxSetup(GPIO2, 11);
    gpioPinMuxSetup(GPIO2, 13);

    /*-----------------------------------------------------------------------------
     *  set pin direction      
	 *-----------------------------------------------------------------------------*/
    for(count=port; count<25; count++){        
		gpioSetDirection(GPIO1, count, dirOut);      
	}

    gpioSetDirection(GPIO2, 11, dirOut);
    gpioSetDirection(GPIO2, 13, dirOut);
    gpioSetDirection(GPIO1, 12, dirIn);     
    gpioSetDirection(GPIO1, 14, dirIn);      
	
    /*-----------------------------------------------------------------------------     
	 *  set pin in LOW level
     *-----------------------------------------------------------------------------*/       
	for(count=port; count<25; count++){
        ledOFF(GPIO1, count);     
    }        
    ledOFF(GPIO2, 11);
    ledOFF(GPIO2, 13);

    uartPutString(UART0, "Write the frequency: \r\n", 24);
    uartGetString(UART0, frequency, 4);
    uartPutString(UART0, frequency, 4);
    uartPutString(UART0, "\r\n", 2);
    double doubleFrequency = stringToDouble(frequency);
    TIME = (1/(2*doubleFrequency)) * 1000;
	
    
    while (1) { 
        
		if(HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & 1<<12){

            while (1)
            {
                ledON(GPIO2, 11);
                Delay(TIME);
                ledOFF(GPIO2, 11);
                Delay(TIME);
            }
		}


        if(HWREG(SOC_GPIO_1_REGS+GPIO_DATAIN) & 1<<14){
            ledmodeButton2++;
            if(ledmodeButton2 == 1){
                for(count = port;count < 25; count++){                
				    ledON(GPIO1, count);
                    Delay(TIME);                
				    ledOFF(GPIO1, count);
                    Delay(TIME);            
			    }
                ledON(GPIO2, 11);
                Delay(TIME);
                ledOFF(GPIO2, 11);    
                Delay(TIME);            
				ledON(GPIO2, 13);
                Delay(TIME);
                ledOFF(GPIO2, 13);    
                Delay(TIME); 
            }
            if(ledmodeButton2 == 2){
                for(count = port;count < 25; count++){                
				    ledON(GPIO1, count);
                    Delay(TIME);                            
			    }
                ledON(GPIO2, 11);
                Delay(TIME);
                ledON(GPIO2, 13);
                Delay(TIME);
                for(count = port;count < 25; count++){ 
                    ledOFF(GPIO1, count);
                    Delay(TIME);
                }
                ledOFF(GPIO2, 11);    
                Delay(TIME);
                ledOFF(GPIO2, 13);    
                Delay(TIME); 
            }
            if(ledmodeButton2 == 3){
                ledON(GPIO2, 13);
                Delay(TIME);
                ledON(GPIO2, 11);
                Delay(TIME);
                for(count = 24;count >= port; count--){                
				    ledON(GPIO1, count);
                    Delay(TIME);                            
			    }

                ledOFF(GPIO2, 13);    
                Delay(TIME);
                ledOFF(GPIO2, 11);    
                Delay(TIME);
                for(count = 24;count >= port; count--){ 
                    ledOFF(GPIO1, count);
                    Delay(TIME);
                }
                ledmodeButton2 = 0;
            }
        }
        
	}  

    return(0);
} /* ----------  end of function main  ---------- */

void ledON(gpioMod mod, ucPinNumber pin){    
	gpioSetPinValue(mod, pin, HIGH);    
}/* -----  end of function ledON  ----- */

void ledOFF(gpioMod mod,  ucPinNumber pin ){    
	gpioSetPinValue(mod, pin, LOW);
}/* -----  end of function ledOFF  ----- */

double stringToDouble(const char *str) {
    double result = 0.0;
    int decimalDigits = 0;
    int isDecimal = 0;

    while (*str != '\0' && *str >= '0' && *str <= '9') {
        result = result * 10.0 + (*str - '0');
        if (isDecimal) {
            decimalDigits++;
        }
        str++;
        if (*str == '.' && !isDecimal) {
            isDecimal = 1;
            str++;
        }
    }

    while (decimalDigits > 0) {
        result /= 10.0;
        decimalDigits--;
    }

    return result;
}