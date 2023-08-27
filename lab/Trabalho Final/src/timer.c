
#include "../inc/timer.h"
#include "../inc/uart.h"
#include "../inc/gpio.h"

volatile bool flag_timer;

static unsigned int DMTimerWritePostedStatusGet(unsigned int baseAdd) {
    /* Return the status of TWPS register */
    return (HWREG(baseAdd + DMTIMER_TWPS));
}



#define DMTimerWaitForWrite(reg, baseAdd)   \
            if(HWREG(baseAdd + DMTIMER_TSICR) & DMTIMER_TSICR_POSTED)\
            while((reg & DMTimerWritePostedStatusGet(baseAdd)));



void DMTimerCounterSet(unsigned int baseAdd, unsigned int counter) {
    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCRR, baseAdd);

    /* Set the counter value */
    HWREG(baseAdd + DMTIMER_TCRR) = counter;
}


unsigned int DMTimerCounterGet(unsigned int baseAdd){
    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCRR, baseAdd);

    /* Read the counter value from TCRR */
    return (HWREG(baseAdd + DMTIMER_TCRR));
}


void DMTimerEnable(unsigned int baseAdd){

    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCLR, baseAdd);

    /* Start the timer */
    HWREG(baseAdd + DMTIMER_TCLR) |= DMTIMER_TCLR_ST;
}


void DMTimerDisable(unsigned int baseAdd){

    /* Wait for previous write to complete */
    DMTimerWaitForWrite(DMTIMER_WRITE_POST_TCLR, baseAdd);

    /* Stop the timer */
    HWREG(baseAdd + DMTIMER_TCLR) &= ~DMTIMER_TCLR_ST;
}


void DMTimerSetUp(void){
    /*  Clock enable for DMTIMER7 TRM 8.1.12.1.25 */
	ckmSetCLKModuleRegister(SOC_CM_PER_REGS, CM_PER_TIMER7_CLKCTRL, CM_PER_TIMER7_CLKCTRL_MODULEMODE_ENABLE);

    while((HWREG(SOC_CM_PER_REGS + CM_PER_TIMER7_CLKCTRL) &
    CM_PER_TIMER7_CLKCTRL_MODULEMODE) != CM_PER_TIMER7_CLKCTRL_MODULEMODE_ENABLE){};
}


void Delay(unsigned int mSec){
    while(mSec != 0){
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        mSec--;
    }
        
    
}

void WDTimerDisable(){
    HWREG(SOC_WDT_1_REGS+WDT_WSPR) = 0xAAAA;
	
	while ((HWREG(SOC_WDT_1_REGS+WDT_WWPS) & (1<<0x4u)) != 0) {
	}
	HWREG(SOC_WDT_1_REGS+WDT_WSPR) = 0x5555;
	while ((HWREG(SOC_WDT_1_REGS+WDT_WWPS) & (1<<0x4u)) != 0) {
	}
}

unsigned int getTimerBut1(unsigned int mSec){
    unsigned int temp = mSec;
    while(mSec != 0){
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        mSec--;

        if(getFlag_gpio1A()){
            break;
        }
    }

    return (temp - mSec);
}

unsigned int getTimerBut2(unsigned int mSec){
    unsigned int temp = mSec;
    while(mSec != 0){
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        mSec--;

        if(getFlag_gpio1B()){
            break;
        }
    }

    return (temp - mSec);
}

unsigned int getTimerBut3(unsigned int mSec){
    unsigned int temp = mSec;
    while(mSec != 0){
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        mSec--;

        if(getFlag_gpio2A()){
            break;
        }
    }

    return (temp - mSec);
}

unsigned int getTimerBut4(unsigned int mSec){
    unsigned int temp = mSec;
    while(mSec != 0){
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        mSec--;

        if(getFlag_gpio2B()){
            break;
        }
    }

    return (temp - mSec);
}

