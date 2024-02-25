#include "drv_max6675.h"
#include "bsp_spi.h"

#define CS_SET HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_SET);
#define CS_RESET HAL_GPIO_WritePin(CS_GPIO_Port, CS_Pin, GPIO_PIN_RESET);
#define CLK_SET HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_SET);
#define CLK_RESET HAL_GPIO_WritePin(CLK_GPIO_Port, CLK_Pin, GPIO_PIN_RESET);
#define READ_MISO HAL_GPIO_ReadPin(MISO_GPIO_Port, MISO_Pin)

uint8_t offline;
float temp;

void Max6675GetTemp(void) {
	uint16_t dat;
	BspSpiReceiveSoft((uint8_t*)&dat, 2);
	dat <<= 1;
	offline = dat & 0x08;
	temp = ((dat>>4)&0x0fff)*0.25;
}
