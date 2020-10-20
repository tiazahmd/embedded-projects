#include "main.h"

void GPIO_Init(void);

int main(void)
{
	HAL_Init();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOE_CLK_ENABLE();
	GPIO_Init();

	static uint8_t data[100];
	uint8_t count = 0;

	uint8_t sw1 = 0, sw2 = 0, led = 0;

	while (1) {
		if (HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_7)) {
			sw1 = 1;
		} else if (HAL_GPIO_ReadPin(GPIOE,  GPIO_PIN_9)) {
			sw2 = 1;
		} else {
			sw1 = 0;
			sw2 = 0;
		}

		if (sw1 || sw2) {
			led = 1;
			if (sw1 == 1) {
				data[count] = 7;
				data[count + 1] = 1;
				data[count + 2] = 1;
				count = count + 3;
			} else if (sw2 == 1) {
				data[count] = 9;
				data[count + 1] = 1;
				data[count + 2] = 1;
				count = count + 3;
			}
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
			HAL_Delay(50);
			HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_1);
			if (sw1 == 1) {
				data[count] = 7;
				data[count + 1] = 1;
				data[count + 2] = 0;
				count = count + 3;
			} else if (sw2 == 1) {
				data[count] = 9;
				data[count + 1] = 1;
				data[count + 2] = 0;
				count = count + 3;
			}
			HAL_Delay(50);
		}

}

void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_C, GPIO_E;

	GPIO_C.Pin = GPIO_PIN_1;
	GPIO_C.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_C.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(GPIOC, &GPIO_C);

	GPIO_E.Pin = GPIO_PIN_7 | GPIO_PIN_9;
	GPIO_E.Mode = GPIO_MODE_INPUT;
	GPIO_E.Speed = GPIO_SPEED_FAST;
	GPIO_E.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOE, &GPIO_E);
}










// End of file
