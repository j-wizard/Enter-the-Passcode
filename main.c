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


long int temp;
int main(void)
{

	//Registers needed:
	//	RCC Clock Enable register
	uint32_t* pPortA_Clock_Enable = (uint32_t*)0x40023830;

	//	Port D OutputData Register
	uint32_t* pPortA_OutputData = (uint32_t*) 0x40020014;

	// 	Port D InPutData Register
	uint32_t* pPortA_InputData = (uint32_t*) 0x40020010;

	//	Port D Mode Register
	uint32_t* pPortA_Mode = (uint32_t*) 0x40020000;

	//	Pull-Down Register
	uint32_t* pPortA_PullDown = (uint32_t*) 0x4002000C;

	//Enable clock
	*pPortA_Clock_Enable |= 0x01;

	//Set Column pins to be input (PA0, PA1, PA6, PA7)
	*pPortA_Mode &= ~(0xF << 0); //PA0, PA1
	*pPortA_Mode &= ~(0xF << 12); //PA6, PA7


	//Set Row pins to be output (PA8, PA9, PA10, PA11)
	*pPortA_Mode |= (0x55 << 16);

	//Set PA5 (Onboard LED) to be output for testing
	*pPortA_Mode |= (0x1 << 10);
	//Clear bit 5
	*pPortA_OutputData &= ~(1 << 5);

	//Set pulldown register for Column Pins
	*pPortA_PullDown |= 0xA;
	*pPortA_PullDown |= (0xA << 12);

	//Set Row data output to LOW (Output data register)
	*pPortA_OutputData &= (0x0 << 8);



	while(1){
		//Set Row data output to LOW (Output data register)
		*pPortA_OutputData &= (0x0 << 8);
		//Set R1 to high
		*pPortA_OutputData |= (1 << 8);

		if(*pPortA_InputData & (1 << 0)){ //C1
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 1)){ //C2
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 6)){ //C3
			*pPortA_OutputData |= (1 << 5); //Turn LED on
			}
		else if(*pPortA_InputData & (1 << 7)){ //C4
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}

		//Set Row data output to LOW (Output data register)
		*pPortA_OutputData &= (0x0 << 8);
		//Set R2 to high
		*pPortA_OutputData |= (1 << 9);

		if(*pPortA_InputData & (1 << 0)){ //C1
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 1)){ //C2
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 6)){ //C3
			*pPortA_OutputData |= (1 << 5); //Turn LED on
			}
		else if(*pPortA_InputData & (1 << 7)){ //C4
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}

		//Set Row data output to LOW (Output data register)
		*pPortA_OutputData &= (0x0 << 8);
		//Set R3 to high
		*pPortA_OutputData |= (1 << 10);

		if(*pPortA_InputData & (1 << 0)){ //C1
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 1)){ //C2
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 6)){ //C3
			*pPortA_OutputData |= (1 << 5); //Turn LED on
			}
		else if(*pPortA_InputData & (1 << 7)){ //C4
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}

		//Set Row data output to LOW (Output data register)
		*pPortA_OutputData &= (0x0 << 8);
		//Set R4 to high
		*pPortA_OutputData |= (1 << 11);

		if(*pPortA_InputData & (1 << 0)){ //C1
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 1)){ //C2
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}
		else if(*pPortA_InputData & (1 << 6)){ //C3
			*pPortA_OutputData |= (1 << 5); //Turn LED on
			}
		else if(*pPortA_InputData & (1 << 7)){ //C4
			*pPortA_OutputData |= (1 << 5); //Turn LED on
		}



	}

}
