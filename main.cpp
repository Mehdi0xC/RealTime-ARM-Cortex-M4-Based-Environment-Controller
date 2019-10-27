//ARM CORTEX M4 (TM4C123) TEMPLATE , BY MXII1994

#include "tm4c123gh6pm.h"
#include "clock.c"
#include "timer.c"
#include "objects.cpp"
#include "ports.c"
#include "ADC.c"
#include "uart.c"
#include <string>
#include "cmsis_os.h"
#include <stdlib.h>

//FUNCTIONS PROTOTYPING
extern "C" void DisableInterrupts(void); // Disable interrupts
extern "C" void EnableInterrupts(void);  // Enable interrupts
extern "C" void WaitForInterrupt(void);  // Enable interrupts
extern "C" int Init_Thread(void);
void t0(void const* argument);
void t1(void const* argument);
void shiftInsert(float* q , int a , float* f);
float output(float* q);
osThreadId TID0 , TID1  ;
osThreadDef(t0 , osPriorityNormal , 1 , 0);
osThreadDef(t1 , osPriorityNormal , 1 , 0);
void send();
char toChar(int);

//VARIABLE DEFINITIONS
Environment env0;
int data = 0;
float factors[10] = {0,0,0,0,0,0,0,0,0,0};
float previousData[10] = {0,0,0,0,0,0,0,0,0,0};
float sumOfFactors = 0;
int main(void){
	
for(int i = 0 ; i < 10 ; i++)
	{
		factors[i] = 2^(-i);
		sumOfFactors += 2^(-i);
	}	
		PortF_Init();
		UART_Init();
	  ADC_Init();	
	  EnableInterrupts();
	  clock();
		SysTick_Init();
		osKernelInitialize ();
		Init_Thread();
		osKernelStart();
		TID0 = osThreadCreate(osThread(t0),NULL);
		TID1 = osThreadCreate(osThread(t1),NULL);
	while(1)
	{
		
  }
}

void t0(void const* argument)
{
	while(1)
	{				
	send();
	wait(5);
	}
}

void t1(void const* arsgument)
{
  while(1)
  {
		ADC_In(&env0.data0, &env0.data1, &env0.data2);
		shiftInsert(previousData ,  env0.data0 , factors );
		data = (int)output(previousData);	
		data = env0.data0;
  }
}


void send()
{	
	UART_OutChar(toChar(int(data/1000)));
	UART_OutChar(toChar(int((data % 1000)/100)));
	UART_OutChar(toChar(int((data % 100)/10)));
	UART_OutChar(toChar(int(data % 10)));
	UART_OutChar('\n');
	GPIO_PORTF_DATA_R |= 0x1F;
}


char toChar(int a)
{
	if (a==0)
		return '0';
	else if (a==1)
		return '1';
	else if (a==2)
		return '2';
	else if (a==3)
		return '3';
	else if (a==4)
		return '4';
	else if (a==5)
		return '5';
	else if (a==6)
		return '6';
	else if (a==7)
		return '7';
	else if (a==8)
		return '8';
	else if (a==9)
		return '9';
	else
		return 'x';
}

void shiftInsert(float* q , int a , float* f)
{	
	for(int i = 9 ; i > 0 ; i--)
		{
			q[i] = q[i-1]*f[i];					
		}				
		q[0] = (float)a;
}

float output(float* q)
{
	float a = 0;
	for(int i = 0 ; i < 10 ; i++)
	{
			a += q[i];
	}		
	a = a / sumOfFactors;	
	return a;	
}
