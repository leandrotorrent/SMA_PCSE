#include "sapi.h"
#include "oled.h"
#include <stdlib.h>
//#include "fuentes.h"

void oledInitTask(void *pvParameters){

	SSD1306_Begin(SSD1306_SWITCHCAPVCC , SSD1306_I2C_ADDRESS);
	SSD1306_ClearDisplay();
	SSD1306_DrawText(36, 5, "CESE", 2);
	SSD1306_DrawText(40, 25, "Co9", 2);
	SSD1306_DrawText(10, 45, "Protocolos", 2);
	SSD1306_Display();
	vTaskDelay(3000);
	SSD1306_ClearDisplay();
	SSD1306_DrawText(37, 20, "Sistema de", 1);
	SSD1306_DrawText(39, 30, "Monitoreo", 1);
	SSD1306_DrawText(39, 40, "Ambiental", 1);
	SSD1306_Display();
	//SSD1306_StartScrollRight(0x00, 0x0F);
	vTaskDelay(3000);
	//SSD1306_StopScroll();
	SSD1306_ClearDisplay();
	SSD1306_DrawText(0,10, "Autores:\r\n\n* Miguel del Valle\r\n\n* Leandro Torrent", 1);
	SSD1306_Display();
	vTaskDelay(2000);
	SSD1306_ClearDisplay();
	SSD1306_DrawText(0,10, "Temp: \r\n\ Humedad: \r\nPresion:\r\n\ Humo:\r\n\ " , 1);
	SSD1306_Display();

}


