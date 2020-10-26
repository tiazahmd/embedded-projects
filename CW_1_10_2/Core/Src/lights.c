/*
 * lights.c
 *
 *  Created on: Oct 23, 2020
 *      Author: imtiaz
 */

#include "lights.h"

void goN(void)
{
	if (system_block.north_green_light == RESET) {
		system_block.north_red_light = RESET;
		system_block.north_yellow_light = RESET;
		system_block.north_green_light = SET;
		waitE();
		redToGreen(NORTH);
	}
}


void waitN(void)
{
	system_block.north_red_light = SET;
	system_block.north_yellow_light = RESET;
	system_block.north_green_light = RESET;
	greenToRed(NORTH);
}


void goE(void)
{
	if (system_block.east_green_light == RESET) {
		system_block.east_red_light = RESET;
		system_block.east_yellow_light = RESET;
		system_block.east_green_light = SET;
		waitN();
		redToGreen(EAST);
	}
}


void waitE(void)
{
	system_block.east_red_light = SET;
	system_block.east_yellow_light = RESET;
	system_block.east_green_light = RESET;
	greenToRed(EAST);
}

void redToGreen(uint8_t northoreast)
{
	if (northoreast == NORTH) {
		HAL_GPIO_WritePin(GPIOE, NORTH_RED_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, NORTH_YELLOW_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, NORTH_GREEN_LIGHT, SET);
		HAL_Delay(1000);
	} else {
		HAL_GPIO_WritePin(GPIOE, EAST_RED_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, EAST_YELLOW_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, EAST_GREEN_LIGHT, SET);
		HAL_Delay(1000);
	}
}

void greenToRed(uint8_t northoreast)
{
	if (northoreast == NORTH) {
		HAL_GPIO_WritePin(GPIOE, NORTH_RED_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, NORTH_GREEN_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, NORTH_YELLOW_LIGHT, SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOE, NORTH_YELLOW_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, NORTH_RED_LIGHT, SET);
	} else {
		HAL_GPIO_WritePin(GPIOE, EAST_RED_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, EAST_GREEN_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, EAST_YELLOW_LIGHT, SET);
		HAL_Delay(1000);
		HAL_GPIO_WritePin(GPIOE, EAST_YELLOW_LIGHT, RESET);
		HAL_GPIO_WritePin(GPIOE, EAST_RED_LIGHT, SET);
	}
}







// End of file
