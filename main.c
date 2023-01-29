/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Jordan Johnson
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f446re.h"
#include "stm32f446re_gpio_drivers.h"

long int temp;
int main(void)
{

	GPIO_Handle_t gpiox;
	gpiox.pGPIOx = GPIOA; //GPIO port for rows and columns

	//Initialization for Output pins (ROWs)
	gpiox.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	gpiox.GPIO_PinConfig.PinSpeed = GPIO_FAST_SPD;
	gpiox.GPIO_PinConfig.PinOPType = GPIO_OP_TYPE_PP;
	gpiox.GPIO_PinConfig.PinPUPDCtrl = GPIO_NO_PUPD;

	//Initialize row pins (PA8, PA9, PA10,PA11)
	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO8;
	GPIO_Init(&gpiox);

	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO9;
	GPIO_Init(&gpiox);

	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO10;
	GPIO_Init(&gpiox);

	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO11;
	GPIO_Init(&gpiox);

	//Initialization for input pins (COLUMNS)
	gpiox.GPIO_PinConfig.PinMode = GPIO_MODE_INPUT;
	gpiox.GPIO_PinConfig.PinSpeed = GPIO_FAST_SPD;
	gpiox.GPIO_PinConfig.PinOPType = GPIO_OP_TYPE_OD;
	gpiox.GPIO_PinConfig.PinPUPDCtrl = GPIO_PU;

	//Initialize column pins (PA0, PA1, PA6, PA7)
	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO0;
	GPIO_Init(&gpiox);

	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO1;
	GPIO_Init(&gpiox);

	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO6;
	GPIO_Init(&gpiox);

	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO7;
	GPIO_Init(&gpiox);

	//Configure GPIO PA5 (onboard LED) for testing
	gpiox.GPIO_PinConfig.PinMode = GPIO_MODE_OUTPUT;
	gpiox.GPIO_PinConfig.PinSpeed = GPIO_FAST_SPD;
	gpiox.GPIO_PinConfig.PinOPType = GPIO_OP_TYPE_PP;
	gpiox.GPIO_PinConfig.PinPUPDCtrl = GPIO_NO_PUPD;
	gpiox.GPIO_PinConfig.PinNumber = GPIO_PIN_NO5;




//	while(1){
//		//Set Row data output to LOW (Output data register)
//		*pPortA_OutputData &= (0x0 << 8);
//		//Set R1 to high
//		*pPortA_OutputData |= (1 << 8);
//
//		if(*pPortA_InputData & (1 << 0)){ //C1
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 1)){ //C2
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 6)){ //C3
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//			}
//		else if(*pPortA_InputData & (1 << 7)){ //C4
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//
//		//Set Row data output to LOW (Output data register)
//		*pPortA_OutputData &= (0x0 << 8);
//		//Set R2 to high
//		*pPortA_OutputData |= (1 << 9);
//
//		if(*pPortA_InputData & (1 << 0)){ //C1
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 1)){ //C2
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 6)){ //C3
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//			}
//		else if(*pPortA_InputData & (1 << 7)){ //C4
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//
//		//Set Row data output to LOW (Output data register)
//		*pPortA_OutputData &= (0x0 << 8);
//		//Set R3 to high
//		*pPortA_OutputData |= (1 << 10);
//
//		if(*pPortA_InputData & (1 << 0)){ //C1
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 1)){ //C2
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 6)){ //C3
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//			}
//		else if(*pPortA_InputData & (1 << 7)){ //C4
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//
//		//Set Row data output to LOW (Output data register)
//		*pPortA_OutputData &= (0x0 << 8);
//		//Set R4 to high
//		*pPortA_OutputData |= (1 << 11);
//
//		if(*pPortA_InputData & (1 << 0)){ //C1
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 1)){ //C2
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//		else if(*pPortA_InputData & (1 << 6)){ //C3
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//			}
//		else if(*pPortA_InputData & (1 << 7)){ //C4
//			*pPortA_OutputData |= (1 << 5); //Turn LED on
//		}
//
//
//
//	}

}
