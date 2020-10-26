#include "lights.h"

void systemInit(void);

int main(void)
{
	HAL_Init();
	systemInit();

	while (1) {
		uint8_t pin_value_1 = HAL_GPIO_ReadPin(GPIOE, NORTH_SENSOR);
		uint8_t pin_value_2 = HAL_GPIO_ReadPin(GPIOE, EAST_SENSOR);
		if (!(HAL_GPIO_ReadPin(GPIOE, NORTH_SENSOR))) {
			system_block.north_sensor = SET;
			system_block.east_sensor = RESET;
			goN();
		} else if (!(HAL_GPIO_ReadPin(GPIOE, EAST_SENSOR))) {
			system_block.north_sensor = RESET;
			system_block.east_sensor = SET;
			goE();
		}
		pin_value_1 = HAL_GPIO_ReadPin(GPIOE, NORTH_SENSOR);
		pin_value_2 = HAL_GPIO_ReadPin(GPIOE, EAST_SENSOR);
	}
}

void systemInit(void)
{
	__HAL_RCC_GPIOE_CLK_ENABLE();		// GPIOE == Lights & Sensors

	GPIO_InitTypeDef SensorGPIO, LightsGPIO;

	SensorGPIO.Pin = NORTH_SENSOR | EAST_SENSOR;
	SensorGPIO.Mode = GPIO_MODE_INPUT;
	SensorGPIO.Pull = GPIO_PULLDOWN;
	SensorGPIO.Speed = GPIO_SPEED_FAST;

	LightsGPIO.Pin = NORTH_RED_LIGHT | NORTH_GREEN_LIGHT | NORTH_YELLOW_LIGHT |
					 EAST_RED_LIGHT | EAST_GREEN_LIGHT | EAST_YELLOW_LIGHT;
	LightsGPIO.Mode = GPIO_MODE_OUTPUT_PP;
	LightsGPIO.Speed = GPIO_SPEED_FAST;

	HAL_GPIO_Init(GPIOE, &SensorGPIO);
	HAL_GPIO_Init(GPIOE, &LightsGPIO);

	system_block.north_sensor = RESET;
	system_block.east_sensor = RESET;
	system_block.north_red_light = RESET;
	system_block.north_yellow_light = RESET;
	system_block.north_green_light = RESET;
	system_block.east_red_light = RESET;
	system_block.east_yellow_light = RESET;
	system_block.east_green_light = RESET;

	HAL_GPIO_WritePin(GPIOE, NORTH_SENSOR, SET);
	HAL_GPIO_WritePin(GPIOE, EAST_SENSOR, RESET);
	system_block.north_sensor = SET;
	system_block.east_sensor = RESET;
	goN();
}
