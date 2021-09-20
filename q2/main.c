//***Program to create 3 Tasks T1,T2,T3
// where Trigger callback from T3 after 10000ms using Timer ***//

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "timers.h"

void mytask1(void *data)
{
	int p=0;
	while(1)
	{
		printf("%[d] Task1 created\n",p);
		p++;
		printf("Task1 ends\n");
		vTaskDelay(1000/portTICK_PERIOD_MS);
	}
}

void mytask2(void *data)
{
	int q=0;
	while(1)
	{
		printf("%[d] Task2 created\n",q);
		q++;
		printf("Task2 ends\n");
		vTaskDelay(2000/portTICK_PERIOD_MS);
	}
}		
	
static TimerHandle_t one_shot_timer = NULL;
	
void mytask3(void *data)
{
	int r=0;
	while(1)
	{
		printf("%[d] Task3 created\n",r);
		r++;
		printf("Task3 ends\n");
		vTaskDelay(5000/portTICK_PERIOD_MS);
	}
}	

void app_main(void)
{
{
	xQueue = xQueueCreate(3, sizeof(int));

	xTaskCreate(mytask1,"mytask1",1024,NULL,1,NULL);
	xTaskCreate(mytask2,"mytask2",1024,NULL,2,NULL);
	xTaskCreate(mytask3,"mytask3",1024,NULL,3,NULL);
}

void myTimerCallback(TimerHandle_t xTimer)
one_shot-timer = xTimerCreate("one_shot-timer", 10000, pdFalse, (void*)0), myTimerCallback);

	if (one_shot_timer == NULL)
		{
		printf("Timer not found\n");
		}
	else
		{
		vTaskDelay (10000 / port_TICK_PERIOD_MS);
		xTimerStart(one_shot_timer, portMAX_DELAY);
		}
		
}
