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
    case 98:
        gpioIsrHandlerA(GPIO1, 16);
        break;
    case 99:
        gpioIsrHandlerB(GPIO1,28);
        break;
    case 95:
        timerIrqHandler();
        break;
    }

	/* acknowledge IRQ */
	HWREG(SOC_AINTC_REGS+INTC_CONTROL ) = 0x1;
}


void gpioIntSetup(unsigned int interrupt){
    HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR3) |= (1<<(interrupt%32));
}

void timerIntSetup(unsigned int interrupt){
    HWREG(SOC_AINTC_REGS+INTC_MIR_CLEAR2) |= (1<<(interrupt%32));
}