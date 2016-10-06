/*
******************************************************************************
File:     main.c
Info:     Generated by Atollic TrueSTUDIO(R) 6.0.0   2016-09-29

The MIT License (MIT)
Copyright (c) 2009-2016 Atollic AB

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************
*/

/* Includes */
#include <stddef.h>
#include "stm32l1xx.h"
#include <math.h>
/* Private typedef */
/* Private define  */
/* Private macro */
/* Private variables */
/* Private function prototypes */
/**
**===========================================================================
**
**  Abstract: main program
**
**===========================================================================
*/


int main(void)
{
  int BUTTON;

  /**
  *  IMPORTANT NOTE!
  *  See the <system_*.c> file and how/if the SystemInit() function updates 
  *  SCB->VTOR register. Sometimes the symbol VECT_TAB_SRAM needs to be defined 
  *  when building the project if code has been located to RAM and interrupts 
  *  are used. Otherwise the interrupt table located in flash will be used.
  *  E.g.  SCB->VTOR = 0x20000000;  
  */

  /**
  *  At this stage the microcontroller clock setting is already configured,
  *  this is done through SystemInit() function which is called from startup
  *  file (startup_stm32l1xx_hd.s) before to branch to application main.
  *  To reconfigure the default setting of SystemInit() function, refer to
  *  system_stm32l1xx.c file
  */

  /* TODO - Add your application code here */

/////////   Uloha 1   /////////////////////////////////////////////
/*
  RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIOA->MODER |= (0b01) << (5*2);
  GPIOA->OTYPER &= ~((uint16_t)(1<<5));
  GPIOA->PUPDR |= (0b01) << (5*2);
  GPIOA->OSPEEDR |= (0b11) << (5*2);


  GPIOA->ODR |= 0b0000000000100000; //LEDka svieti
  GPIOA->ODR &= ~(0b0000000000100000); //LEDka nesvieti
  GPIOA->BSRRL |= ((uint16_t)(1<<5)); //LEDka svieti
  GPIOA->BSRRH |= ((uint16_t)(1<<5)); //LEDka nesvieti

  GPIOA->ODR ^= (1<<5); //prepinam - mala by byt vypnuta
  GPIOA->ODR ^= (1<<5); //prepinam - mala by svietit
  GPIOA->ODR ^= (1<<5); // prepinam - vypnuta
  GPIOA->ODR ^= (1<<5); // prepinam - svieti*/

/////////   Uloha 2   /////////////////////////////////////////////
  	/*RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
    GPIOC->MODER |= (0b00) << (13*2);
    GPIOC->OTYPER &= ~((uint16_t)(1<<13));
    GPIOC->PUPDR |= (0b00) << (13*2);

    while(1){
    	i++;
  	 if ((GPIOC->IDR & (0b0010000000000000)) == 0)
  	   BUTTON = 1;
  	 else if ((GPIOC->IDR & (0b0010000000000000)) == (pow(2,13)))
  	   BUTTON = 0;

    }
/////////////////////////////////////////////////////////////////*/
  /// Uloha 1 s pouzitim kniznice /////////
  /*RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
  GPIO_InitTypeDef struktura;
  struktura.GPIO_Mode = GPIO_Mode_OUT;
  struktura.GPIO_OType = GPIO_OType_PP;
  struktura.GPIO_PuPd = GPIO_PuPd_UP;
  struktura.GPIO_Pin = GPIO_Pin_5;
  struktura.GPIO_Speed = GPIO_Speed_40MHz;
  GPIO_Init(GPIOA, &struktura);
  while (1){
	  GPIO_ToggleBits(GPIOA, GPIO_Pin_5);
  }*/
  /////////////////////////////////////////////////////////////////*/
  /// Uloha 2 s pouzitim kniznice /////////
  /*RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
  GPIO_InitTypeDef struktura;
  struktura.GPIO_Mode = GPIO_Mode_IN;
  struktura.GPIO_PuPd = GPIO_PuPd_NOPULL;
  struktura.GPIO_OType = GPIO_OType_PP;
  struktura.GPIO_Pin = GPIO_Pin_13;
  while(1){
	  if ((GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)) == 0){
		  BUTTON = 1;
	  }
	  else if ((GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13)) == 1 ){
		  BUTTON = 0;
	  }
  }*/
//////////////////////////////////////////////////////////////////////
 ///////////////    Uloha 3, prva cast  ////////////////////////////////////
    RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
    GPIOA->MODER |= (0b01) << (5*2);
    GPIOA->OTYPER &= ~((uint16_t)(1<<5));
    GPIOA->PUPDR |= (0b01) << (5*2);
    GPIOA->OSPEEDR |= (0b11) << (5*2);

	int i;
	int j;

    while(1){
    	i = 1;
    	j = 1;
    	GPIOA->ODR ^= (1<<5); //LEDka svieti
    	for ( i=1; i<= 500; i++){
    		for ( j=1; j<= 500; j++){
    			}
    		}
    	GPIOA->ODR ^= (1<<5); //LEDka nesvieti
    	i = 1;
    	j = 1;
    	for ( i=1; i<= 500; i++){
    		for ( j=1; j<= 500; j++){
    			}
    		}
    }
 ///////////////////////////////////////////
  return 0;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/*
 * Minimal __assert_func used by the assert() macro
 * */
void __assert_func(const char *file, int line, const char *func, const char *failedexpr)
{
  while(1)
  {}
}



/*
 * Minimal __assert() uses __assert__func()
 * */
void __assert(const char *file, int line, const char *failedexpr)
{
   __assert_func (file, line, NULL, failedexpr);
}

