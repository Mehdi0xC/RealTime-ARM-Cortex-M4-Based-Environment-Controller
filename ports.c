#include "tm4c123gh6pm.h"

void PortA_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000001;
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTA_CR_R = 0xFF;           // 1) allow changes if 1
  GPIO_PORTA_AMSEL_R = 0x00;        // 2) enable analog input if 1
  GPIO_PORTA_PCTL_R = 0x00000000;   // 3) ultarnative functions enabled if 1
  GPIO_PORTA_DIR_R = 0xF0;          // 4) output if 1 , input if 0
  GPIO_PORTA_AFSEL_R = 0x00;        // 5) enable alternative functions if 1
  GPIO_PORTA_PUR_R = 0x00;          // 6) enable pull-up if 1
  GPIO_PORTA_DEN_R = 0x00;          // 7) enable digital I/O if 1
}

void PortB_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000002;
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTB_CR_R = 0xFF;           // 1) allow changes if 1
  GPIO_PORTB_AMSEL_R = 0x00;        // 2) enable analog input if 1
  GPIO_PORTB_PCTL_R = 0x00000000;   // 3) ultarnative functions enabled if 1
  GPIO_PORTB_DIR_R = 0x00;          // 4) output if 1 , input if 0
  GPIO_PORTB_AFSEL_R = 0x00;        // 5) enable alternative functions if 1
  GPIO_PORTB_PUR_R = 0x0F;          // 6) enable pull-up if 1
  GPIO_PORTB_DEN_R = 0x0F;          // 7) enable digital I/O if 1
	GPIO_PORTB_IS_R = 0x00;     //  edge-sensitive
  GPIO_PORTB_IBE_R = 0x00;    //     PF4 is not both edges
  GPIO_PORTB_IEV_R = 0x00;    //     PF4 falling edge event
  GPIO_PORTB_ICR_R = 0x0F;      // (e) clear flag4
  GPIO_PORTB_IM_R |= 0x0F;      // (f) arm interrupt on PF4
	NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  NVIC_EN0_R = 0x00000002;      // (h) enable interrupt 30 in NVIC      
}

void PortC_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000004;
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTC_CR_R = 0x20;           // 1) allow changes if 1
  GPIO_PORTC_AMSEL_R = 0x00;        // 2) enable analog input if 1
  GPIO_PORTC_PCTL_R = 0x00000000;   // 3) ultarnative functions enabled if 1
  GPIO_PORTC_DIR_R = 0x20;          // 4) output if 1 , input if 0
  GPIO_PORTC_AFSEL_R = 0x00;        // 5) enable alternative functions if 1
  GPIO_PORTC_PUR_R = 0x00;          // 6) enable pull-up if 1
  GPIO_PORTC_DEN_R = 0x20;          // 7) enable digital I/O if 1
}

void PortD_Init(void)
{
		volatile unsigned long delay;
		SYSCTL_RCGC2_R |= 0x00000008;
		delay = SYSCTL_RCGC2_R;
		GPIO_PORTD_CR_R = 0xFF;           // 1) allow changes if 1
		GPIO_PORTD_AMSEL_R = 0x00;        // 2) enable analog input if 1
		GPIO_PORTD_PCTL_R = 0x00000000;   // 3) ultarnative functions enabled if 1
		GPIO_PORTD_DIR_R = 0xCF;          // 4) output if 1 , input if 0
		GPIO_PORTD_AFSEL_R = 0x00;        // 5) enable alternative functions if 1
		GPIO_PORTD_PUR_R = 0x00;          // 6) enable pull-up if 1
		GPIO_PORTD_DEN_R = 0xCF;          // 7) enable digital I/O if 1
}

void PortE_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000010;
  delay = SYSCTL_RCGC2_R;
  GPIO_PORTE_CR_R = 0xFF;           // 1) allow changes if 1
  GPIO_PORTE_AMSEL_R = 0x00;        // 2) enable analog input if 1
  GPIO_PORTE_PCTL_R = 0x00000000;   // 3) ultarnative functions enabled if 1
  GPIO_PORTE_DIR_R = 0x03;          // 4) output if 1 , input if 0
  GPIO_PORTE_AFSEL_R = 0x00;        // 5) enable alternative functions if 1
  GPIO_PORTE_PUR_R = 0x0C;          // 6) enable pull-up if 1
  GPIO_PORTE_DEN_R = 0x0F;          // 7) enable digital I/O if 1
}

void PortF_Init(void)
{
  volatile unsigned long delay;
  SYSCTL_RCGC2_R |= 0x00000020; // (a) activate clock for port F
  GPIO_PORTF_DIR_R |= 0x1F;    // (c) make PF4 in (built-in button)
  GPIO_PORTF_AFSEL_R &= ~0x1F;  //     disable alt funct on PF4
  GPIO_PORTF_DEN_R |= 0x1F;     //     enable digital I/O on PF4
  GPIO_PORTF_PCTL_R &= ~0x000FFFFF; //  configure PF4 as GPIO
  GPIO_PORTF_AMSEL_R &= ~0x1F;  //    disable analog functionality on PF4
  //GPIO_PORTF_PUR_R |= 0x0;     //     enable weak pull-up on PF4
  //GPIO_PORTF_IS_R &= ~0x10;     // (d) PF4 is edge-sensitive
  //GPIO_PORTF_IBE_R &= ~0x10;    //     PF4 is not both edges
  //GPIO_PORTF_IEV_R &= ~0x10;    //     PF4 falling edge event
  //GPIO_PORTF_ICR_R = 0x10;      // (e) clear flag4
  //GPIO_PORTF_IM_R |= 0x10;      // (f) arm interrupt on PF4
  //NVIC_PRI7_R = (NVIC_PRI7_R&0xFF00FFFF)|0x00A00000; // (g) priority 5
  //NVIC_EN0_R = 0x40000000;      // (h) enable interrupt 30 in NVIC
}


