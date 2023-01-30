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

/* ******************************************************************************
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *******************************************************************************/

#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f446re.h"
#include "stm32f446re_gpio_drivers.h"

//Set all rows to HIGH
void SetRows(){
	GPIO_WriteOutPin(GPIOA, GPIO_PIN_NO8, GPIO_PIN_SET);
	GPIO_WriteOutPin(GPIOA, GPIO_PIN_NO9, GPIO_PIN_SET);
	GPIO_WriteOutPin(GPIOA, GPIO_PIN_NO10, GPIO_PIN_SET);
	GPIO_WriteOutPin(GPIOA, GPIO_PIN_NO11, GPIO_PIN_SET);
}

void delay(){
	for(int i=0;i<300000;i++);
}

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

	GPIO_Init(&gpiox);




	while(1){
		//Set Row data output to high (Output data register)
		SetRows();
		GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_RESET);
		//Set R1 to LOW
		GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO8, GPIO_PIN_RESET);

		if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO0) == 0){ //C1
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO1) == 0){ //C2
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO6) == 0){ //C3
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
			}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO7) == 0){ //C4
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}

		//Set Row data output to high (Output data register)
		SetRows();
		//Set R1 to LOW
		GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO9, GPIO_PIN_RESET);
		if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO0) == 0){ //C1
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO1) == 0){ //C2
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO6) == 0){ //C3
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO7) == 0){ //C4
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}

			//Set Row data output to high (Output data register)
		SetRows();
		//Set R1 to LOW
		GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO10, GPIO_PIN_RESET);

		if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO0) == 0){ //C1
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO1) == 0){ //C2
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO6) == 0){ //C3
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO7) == 0){ //C4
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}

		//Set Row data output to high (Output data register)
		SetRows();
		//Set R1 to LOW
		GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO11, GPIO_PIN_RESET);

		if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO0) == 0){ //C1
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO1) == 0){ //C2
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO6) == 0){ //C3
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}
		else if(GPIO_ReadInPin(gpiox.pGPIOx, GPIO_PIN_NO7) == 0){ //C4
			GPIO_WriteOutPin(gpiox.pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
			delay();
		}

	}

	return 0;
}
