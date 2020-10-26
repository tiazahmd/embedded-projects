/*
 * lights.h
 *
 *  Created on: Oct 23, 2020
 *      Author: imtiaz
 */

#ifndef INC_LIGHTS_H_
#define INC_LIGHTS_H_

#include "main.h"

#define NORTH_RED_LIGHT				GPIO_PIN_0
#define NORTH_YELLOW_LIGHT			GPIO_PIN_1
#define NORTH_GREEN_LIGHT			GPIO_PIN_2
#define EAST_RED_LIGHT				GPIO_PIN_3
#define EAST_YELLOW_LIGHT			GPIO_PIN_4
#define EAST_GREEN_LIGHT			GPIO_PIN_5
#define NORTH_SENSOR				GPIO_PIN_7
#define EAST_SENSOR					GPIO_PIN_8
#define NORTH						0
#define EAST						1

typedef struct {
	uint8_t north_sensor;
	uint8_t east_sensor;
	uint8_t north_red_light;
	uint8_t north_yellow_light;
	uint8_t north_green_light;
	uint8_t east_red_light;
	uint8_t east_yellow_light;
	uint8_t east_green_light;
} TrafficFSM;

TrafficFSM system_block;

void goN(void);
void waitN(void);
void goE(void);
void waitE(void);
void redToGreen(uint8_t northoreast);
void greenToRed(uint8_t northoreast);

#endif /* INC_LIGHTS_H_ */
