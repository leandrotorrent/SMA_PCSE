/*=============================================================================
 * Copyright (c) 2019, SMA Project
 * Leandro Torrent <leandrotorrent92@gmail.com>
 * Miguel del Valle <m.e.delvallecamino@ieee.org>
 * All rights reserved.
 * License: bsd-3-clause (see LICENSE.txt)
 * Date: 2019/07/27
 * Version: 1.0
 *===========================================================================*/
/* Date: 2019-09-02 */

/*=====[Inclusions of function dependencies]=================================*/
#include "sma.h"
#include "mq2.h" // tested on GY-BME/P280
#include "sapi.h"		// <= sAPI header

void mq2Task(void *pvParameters) {
	real32_t lValueToSend;
	BaseType_t xStatusMQ2, xStatusSd;
	real32_t humo = 0;


	/* As per most tasks, this task is implemented within an infinite loop. */
	for (;;) {


		lValueToSend = MQ2MQGetGasPercentage(MQ2MQRead()/10, 2)/10000;



		xStatusMQ2 = xQueueSendToBack(xQueueMQ2, &lValueToSend, 0);
		xStatusSd = xQueueSendToBack(xQueueSd, &lValueToSend, 0);

		if (xStatusMQ2 != pdPASS) {
			/* We could not write to the queue because it was full � this must
			 be an error as the queue should never contain more than one item! */
			vPrintString("Could not send to the queue MQ2.\r\n");
		}
		if (xStatusSd != pdPASS) {
			/* We could not write to the queue because it was full � this must
			 be an error as the queue should never contain more than one item! */
			vPrintString("Could not send to the queue SD.\r\n");
		}
		vTaskDelay( ((int32_t )pvParameters) / portTICK_RATE_MS );
	}
}
