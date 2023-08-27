#include "../inc/interrupt.h"
#include "../inc/hw_types.h"
#include "../inc/soc_AM335x.h"
#include "../inc/gpio.h"
#include "../inc/timer.h"


unsigned int interruptMask(){
    unsigned int irq_number = HWREG(SOC_AINTC_REGS+INTC_SIR_IRQ) & 0x7f;
    return (irq_number%32);
}

void ISR_Handler(){
	/* Verify active IRQ number */
	unsigned int irq_number = HWREG(SOC_AINTC_REGS+INTC_SIR_IRQ) & 0x7f;
	switch (irq_number) {
    case 32:
        gpioIsrHandlerA(GPIO2,3);
        break;
    case 33:
        gpioIsrHandlerB(GPIO2,4);
        break;
    case 62:
        gpioIsrHandlerA(GPIO3, 19);
        break;
    case 98:
        gpioIsrHandlerA(GPIO1, 16);
        break;
    case 99:
        gpioIsrHandlerB(GPIO1,28);
        break;
    }

	/* acknowledge IRQ */
	HWREG(SOC_AINTC_REGS+INTC_CONTROL ) = 0x1;
}


void gpioIntSetup(unsigned int interrupt){
    unsigned int mir = interrupt/32;
    unsigned int bit = interrupt%32;
    switch (mir)
    {
    case 0:
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR0) |= (1<<bit);
        break;
    case 1:
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR1) |= (1<<bit);
        break;
    case 2:
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<bit);
        break;
    case 3:
        HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<bit);
        break;
    default:
        break;
    }
}

