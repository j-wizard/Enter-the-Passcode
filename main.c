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


#include <stdio.h>
#include "lcd.h"
#include "stm32f446re.h"
#include "stm32f446re_gpio_drivers.h"

//Row 1 Characters
char row_1_keys[4] = {'1','2','3','A'};

//Row 2 Characters
char row_2_keys[4] = {'4','5','6','B'};

//Row 3 Characters
char row_3_keys[4] = {'7','8','9','C'};

//Row 4 Characters
char row_4_keys[4] = {'*','0','#','D'};

char passcode[4] = {'1','2','3','4'};

//Stores user input
char user_entry[4];

//Keep track of how many characters user has pressed
int count = 0;

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

void CheckRow(GPIO_REG_t *pGPIOx, int RowPin, char row_keys[]){
	GPIO_WriteOutPin(pGPIOx, RowPin, GPIO_PIN_RESET);

	if(GPIO_ReadInPin(pGPIOx, GPIO_PIN_NO0) == 0){ //C1
		GPIO_WriteOutPin(pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
		delay();
		user_entry[count] = row_keys[0];
		lcd_print_char(user_entry[count]);
		count++;

	}
	else if(GPIO_ReadInPin(pGPIOx, GPIO_PIN_NO1) == 0){ //C2
		GPIO_WriteOutPin(pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
		delay();
		user_entry[count] = row_keys[1];
		lcd_print_char(user_entry[count]);
		count++;
	}
	else if(GPIO_ReadInPin(pGPIOx, GPIO_PIN_NO6) == 0){ //C3
		GPIO_WriteOutPin(pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
		delay();
		user_entry[count] = row_keys[2];
		lcd_print_char(user_entry[count]);
		count++;
	}
	else if(GPIO_ReadInPin(pGPIOx, GPIO_PIN_NO7) == 0){ //C4
		GPIO_WriteOutPin(pGPIOx, GPIO_PIN_NO5, GPIO_PIN_SET); //Turn LED on
		delay();
		user_entry[count] = row_keys[3];
		lcd_print_char(user_entry[count]);
		count++;
	}
	SetRows();
}

uint8_t Check_user_entry(char user_attempt[], char pass[]){
	for(int i=0;i<4;i++){
		if(user_attempt[i] != pass[i]){
			lcd_display_clear();
			lcd_set_cursor(1, 1);
			lcd_print_string("LOGIN FAILED");

			mdelay(3000);

			lcd_display_clear();
			lcd_set_cursor(1, 1);
			lcd_print_string("Enter Passcode:");
			lcd_set_cursor(2, 1);
			count = 0;
			return 0;
		}
	}

	lcd_display_clear();
	lcd_set_cursor(1, 1);
	lcd_print_string("LOGIN SUCCESSFUL");

	mdelay(3000);

	lcd_display_clear();
	lcd_set_cursor(1, 1);
	lcd_print_string("Enter Passcode:");
	lcd_set_cursor(2, 1);
	count = 0;
	return 1;

}


int main(void)
{
	lcd_init();

	lcd_print_string("Enter Passcode:");
	lcd_set_cursor(2, 1);

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
		CheckRow(gpiox.pGPIOx, GPIO_PIN_NO8,row_1_keys);

		//Set R2 to LOW
		CheckRow(gpiox.pGPIOx, GPIO_PIN_NO9,row_2_keys);

		//Set R3 to LOW
		CheckRow(gpiox.pGPIOx, GPIO_PIN_NO10,row_3_keys);

		//Set R4 to LOW
		CheckRow(gpiox.pGPIOx, GPIO_PIN_NO11,row_4_keys);

		if(count > 3){
			Check_user_entry(user_entry, passcode);
		}

	}

	return 0;
}
