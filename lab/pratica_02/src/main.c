		/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/02/2017 20:05:55
 *       Revision:  none
 *       Compiler:  arm-none-eabi-gcc
 *
 *         Author:  Francisco Helder (FHC), helderhdw@gmail.com
 *   Organization:  UFC-Quixadá
 *
 * =====================================================================================
 */

#include	"hw_types.h"
#include	"soc_AM335x.h"

/*****************************************************************************
**                INTERNAL MACRO DEFINITIONS
*****************************************************************************/
#define TIME													1000000
#define TOGGLE          										(0x01u)

#define CM_PER_GPIO1											0xAC
#define CM_PER_GPIO2											0xB0

#define CM_PER_GPIO_CLKCTRL_MODULEMODE_ENABLE   				(0x2u)
#define CM_PER_GPIO_CLKCTRL_OPTFCLKEN_GPIO_GDBCLK   			(0x00040000u)

#define CM_conf_gpmc_ben1      	 								0x0878
#define CM_conf_gpmc_a5         								0x0854
#define CM_conf_gpmc_a6         								0x0818
#define CM_conf_gpmc_a7         								0x081C
#define CM_conf_gpmc_a8         								0x0820
#define CM_conf_gpmc_ad12         								0x0830

#define CM_conf_lcd_data5										0x8B4
#define CM_conf_lcd_data9										0x8C4

#define GPIO_OE                 								0x134
#define GPIO_CLEARDATAOUT       								0x190
#define GPIO_SETDATAOUT         								0x194

#define WDT_WSPR												0x1c
#define	DLY_IT_ENA												(0x0<<1)
#define OVF_IT_ENA												(0x0u)

unsigned int flagBlink;
int count = 1;

/*****************************************************************************
**                INTERNAL FUNCTION PROTOTYPES
*****************************************************************************/
static void delay();
static void ledInit();
static void ledToggle();
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
int _main(void){
	flagBlink=0;	//init flag
  	
	/* Configure the green LED control pin. */
  	ledInit();
  
  	while (1){
    	/* Change the state of the green LED. */
    	ledToggle();
		delay();
	}

	return(0);
} /* ----------  end of function main  ---------- */


/*FUNCTION*-------------------------------------------------------
*
* Function Name : Delay
* Comments      :
*END*-----------------------------------------------------------*/
static void delay(){
	volatile unsigned int ra;
	for(ra = 0; ra < TIME; ra ++);
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledInit
 *  Description:  
 * =====================================================================================
 */
void ledInit( ){
	
	unsigned int val_temp; 	
	/*-----------------------------------------------------------------------------
	 *  configure clock GPIO in clock module 1
	 *-----------------------------------------------------------------------------*/
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO1) |= CM_PER_GPIO_CLKCTRL_OPTFCLKEN_GPIO_GDBCLK | CM_PER_GPIO_CLKCTRL_MODULEMODE_ENABLE;
	
 	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a5) |= 7;
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<21);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;

	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a6) |= 7;
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<22);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;

	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a7) |= 7;
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<23);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;

	HWREG(SOC_CONTROL_REGS+CM_conf_gpmc_a8) |= 7;
	val_temp = HWREG(SOC_GPIO_1_REGS+GPIO_OE);
	val_temp &= ~(1<<24);
	HWREG(SOC_GPIO_1_REGS+GPIO_OE) = val_temp;

	/*-----------------------------------------------------------------------------
	 *  configure clock GPIO in clock module 2
	 *-----------------------------------------------------------------------------*/
	HWREG(SOC_CM_PER_REGS+CM_PER_GPIO2) |= CM_PER_GPIO_CLKCTRL_OPTFCLKEN_GPIO_GDBCLK | CM_PER_GPIO_CLKCTRL_MODULEMODE_ENABLE;

	HWREG(SOC_CONTROL_REGS+CM_conf_lcd_data5) |= 7;
	val_temp = HWREG(SOC_GPIO_2_REGS+GPIO_OE);
	val_temp &= ~(1<<11);
	HWREG(SOC_GPIO_2_REGS+GPIO_OE) = val_temp;

	HWREG(SOC_CONTROL_REGS+CM_conf_lcd_data9) |= 7;
	val_temp = HWREG(SOC_GPIO_2_REGS+GPIO_OE);
	val_temp &= ~(1<<15);
	HWREG(SOC_GPIO_2_REGS+GPIO_OE) = val_temp;

}/* -----  end of function ledInit  ----- */



/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  ledToggle
 *  Description:  
 * =====================================================================================
 */
void ledToggle(){
		
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<21;
		delay();
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<21;
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<22;
		delay();
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<22;
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<23;
		delay();
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<23;
		HWREG(SOC_GPIO_1_REGS+GPIO_SETDATAOUT) = 1<<24;
		delay();
		HWREG(SOC_GPIO_1_REGS+GPIO_CLEARDATAOUT) = 1<<24;

		HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<11;
		delay();
		HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<11;
		HWREG(SOC_GPIO_2_REGS+GPIO_SETDATAOUT) = 1<<15;
		delay();
		HWREG(SOC_GPIO_2_REGS+GPIO_CLEARDATAOUT) = 1<<15;
		
}/* -----  end of function ledToggle  ----- */









