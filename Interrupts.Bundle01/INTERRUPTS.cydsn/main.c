#include "t_GPIO.h"
#include "t_udtypes.h"

void GPIO_ISR(void);

int main(void)
{
    GPIO_WRITE_PIN(GPIO_PRT0_DR,7,1); 
    GPIO_SET_MODE(GPIO_PRT0_PC,7,GPIO_DM_RES_UP); //P0[7] into Resistive Pull Up Mode
    GPIO_SET_MODE(GPIO_PRT0_PC,6,GPIO_DM_STRONG); //P0[6] into Strong Mode
    //To enable the Global Interrupts
    __asm("CPSIE I");  //To clear PRIMASK (Enable Interrupts)
    
	//TO Disable IRQ0 interrupt
	//Required because Interrupt cannot be configured
    (*(t_reg32*)0xE000E180)=0x00000001; 
    
    (*(t_reg32*)(0x20000040u))=(t_reg32) (&GPIO_ISR);
    
    //To configure P0[7]'s rising edge as the source of interrupt
    (*(t_reg32*)(0x4004000C))=((*(t_reg32*)(0x4004000C))&(~((t_uint32)0x03u <<(0x07u*0x02u))))|((t_uint32)(0x01<<(0x07u*0x02u)));
    
    //To assign priority to IRQ0. Priority=3
    (*(t_reg32*)0xE000E400)= ((*(t_reg32*)0xE000E400) & ((t_uint32)(~(0xC0)))) |((t_uint32)(0x03u<<6));
    
    //To enable interrupt request IRQ0
    (*(t_reg32*) (0xE000E100))=0x01u;
	
    for(;;)
    {
       
    }
}

/*
 *	Function Name - GPIO_ISR
 *	Function 	  - Interrupt Service Routine for the Port 0
 * 	Detail		  - Whenever we press and release the button this function is called
*/
void GPIO_ISR(void)
{
    t_uint32 i;
    unsigned char mask_status= (unsigned char)((*((t_reg32*)(0x40040010u))&(1UL<<0x07u))>>0x07u);
    if(mask_status==0x01u)
    {
		//Clear the interrupt
        *((t_reg32*)(0x40040010u))=(mask_status<<0x07u);
		
		//Read the 6th pin - i.e. LED RED
        i=GPIO_READ_PIN(GPIO_PRT0_PS,6);
		
		//Write invert of LED RED
        GPIO_WRITE_PIN(GPIO_PRT0_DR,6,~i);
    }
}