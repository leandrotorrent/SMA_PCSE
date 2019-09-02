#include "sma.h"
#include "oled.h"


void vReceiverTask( void *pvParameters )
{
	/* Declare the variable that will hold the values received from the queue. */
	//vTaskDelay(pdMS_TO_TICKS( 6000UL ));
	SSD1306_Begin(SSD1306_SWITCHCAPVCC , SSD1306_I2C_ADDRESS);
	SSD1306_ClearDisplay();

	SSD1306_DrawText(36, 0, "CESE", 2);
	SSD1306_DrawText(40, 20, "Co9", 2);
	SSD1306_DrawText(0, 40, "Protocolos de ", 1);
	SSD1306_DrawText(0, 50, "Comunicacion en SE", 1);
	SSD1306_Display();
	vTaskDelay(3500);
	SSD1306_ClearDisplay();
	SSD1306_DrawText(37, 20, "Sistema de", 1);
	SSD1306_DrawText(39, 30, "Monitoreo", 1);
	SSD1306_DrawText(39, 40, "Ambiental", 1);
	SSD1306_Display();
	SSD1306_StartScrollRight(0x00, 0x0F);
	vTaskDelay(8500);
	SSD1306_StopScroll();
	SSD1306_ClearDisplay();


	real32_t lReceivedValueAM2301, lReceivedValueMQ2;
	BaseType_t xStatusMQ2, xStatusAM2301;
	const TickType_t xTicksToWait = pdMS_TO_TICKS( 1000UL );
	char uartBuff[10];

	/* This task is also defined within an infinite loop. */
	for( ;; ) {
		/* As this task unblocks immediately that data is written to the queue this
      call should always find the queue empty. */
		if( uxQueueMessagesWaiting( xQueueMQ2 ) != 0 ) {
			vPrintString( "Queue should have been empty!\r\n" );
		}
		if( uxQueueMessagesWaiting( xQueueAM2301 ) != 0 ) {
			vPrintString( "Queue should have been empty!\r\n" );
		}

		/* The first parameter is the queue from which data is to be received.  The
      queue is created before the scheduler is started, and therefore before this
      task runs for the first time.

      The second parameter is the buffer into which the received data will be
      placed.  In this case the buffer is simply the address of a variable that
      has the required size to hold the received data.

      the last parameter is the block time � the maximum amount of time that the
      task should remain in the Blocked state to wait for data to be available should
      the queue already be empty. */
		xStatusMQ2 = xQueueReceive( xQueueMQ2, &lReceivedValueMQ2, xTicksToWait );
		xStatusAM2301 = xQueueReceive( xQueueAM2301, &lReceivedValueAM2301, xTicksToWait );

		if( xStatusAM2301 == pdPASS ) {
			/* Data was successfully received from the queue, print out the received
         value. */
			//vPrintStringAndNumber( "Received = ", lReceivedValue );

			uartWriteString( UART_USB, "Temperatura: " );
			floatToString( lReceivedValueAM2301, uartBuff, 1 );
			uartWriteString( UART_USB, uartBuff);
			uartWriteString( UART_USB, " grados C\r\n" );

			SSD1306_DrawText(0,10, "Temp: " , 1);
			SSD1306_DrawText(30,10, uartBuff , 1);
			SSD1306_DrawText(55,10, " C " , 1);
			SSD1306_Display();

			/*uartWriteString( UART_USB, "Hum: " );
			floatToString( lReceivedValueAM2301[1], uartBuff, 4 );
			uartWriteString( UART_USB, uartBuff);
			uartWriteString( UART_USB, " % C\r\n" );

			SSD1306_DrawText(0,20, "Hum: " , 1);
			SSD1306_DrawText(25,20, uartBuff , 1);
			SSD1306_DrawText(55,20, " % " , 1);
			SSD1306_Display();*/


		} else {
			/* We did not receive anything from the queue even after waiting for 100ms.
         This must be an error as the sending tasks are free running and will be
         continuously writing to the queue. */
			vPrintString( "No se pudo recibir de AM2301.\r\n" );
		}
		if( xStatusMQ2 == pdPASS ) {
			/* Data was successfully received from the queue, print out the received
               value. */
			//vPrintStringAndNumber( "Received = ", lReceivedValue );

			uartWriteString( UART_USB, "Humo: " );
			floatToString( lReceivedValueMQ2, uartBuff, 4 );
			uartWriteString( UART_USB, uartBuff);
			uartWriteString( UART_USB, " % \r\n" );

			SSD1306_DrawText(0,30, "Humo: " , 1);
			SSD1306_DrawText(30,30, uartBuff , 1);
			SSD1306_DrawText(60,30, " % " , 1);
			SSD1306_Display();


		} else {
			/* We did not receive anything from the queue even after waiting for 100ms.
               This must be an error as the sending tasks are free running and will be
               continuously writing to the queue. */
			vPrintString( "No se pudo recibir de MQ2.\r\n" );
		}
	}
}

