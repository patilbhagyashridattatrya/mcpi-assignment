/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	//enable gpiod (in AHB1ENR)
	RCC->AHB1ENR |=BV(3);


	//set gpoid pin 14 speed as output(in MODER)
	GPIOD->MODER &= ~BV(31);
	GPIOD->MODER |= BV(30);
	//set gpiod pin 14 speed to low (in OSPEEDR)
	GPIOD->OSPEEDR &= ~(BV(31) | BV(30));
	//set gpiod pin 14 no pull up, no pull down(in PUPDR)
	GPIOD->PUPDR &= ~(BV(31) | BV(30));
	//set gpiod pin 14 type as push-pull(in 0TYPER)
	GPIOD->OTYPER &= ~BV(15);
	while (1)
	{
		//set gpiod pin 14-> red led on
		GPIOD->ODR |= BV(15);
		//delay 1000ms
		DelayMs(1000);
		//clear gpiod pin 14-> red led off
		GPIOD->ODR &= ~BV(15);
		//delay 1000 ms
		DelayMs(1000);
	}

	return 0;
}

