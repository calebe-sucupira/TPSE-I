#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define INTC_SIR_IRQ    						0x40
#define INTC_CONTROL                            0x48
#define INTC_MIR_CLEAR2                         0xC8
#define INTC_MIR_CLEAR3                         0xE8
unsigned int interruptMask();
void ISR_Handler();
void gpioIntSetup(unsigned int interrupt);
void timerIntSetup(unsigned int interrupt);
#endif