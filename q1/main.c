//***Program to create 3 Tasks T1,T2,T3 and two additional tasks T4 and T5
// where T4 ssends data to T5 using message Queue ***//

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "queue.h"

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

xQueueHandle_t xQueue; //for message queue

void task4sender(void *data)
{
	int s=0;
	while(1)
	{
		printf("%[d] Task4 created\n", s);
		printf("Send integer data %[d]\n", s);
		if (! xQueueSend(xQueue, &s, 1000))
		{
		printf("Failed to send\n");
		}
		s++;
		printf("Task4 ends\n");
		vTaskDelay(6000/portTICK_PERIOD_MS);
	}
}	

void task5receiver(void *data)
{
	int data=0;
	while(1)
	{
		if(xQueueReceive(xQueue, &data, 1000))
		{
		printf("Received %[d]\n", data);
		}
		else
		{
		printf("Failed to receive Data\n");
		}
	}
}	
		
void app_main(void)
{
	xQueue = xQueueCreate(3, sizeof(int));

	xTaskCreate(mytask1,"mytask1",1024,NULL,1,NULL);
	xTaskCreate(mytask2,"mytask2",1024,NULL,2,NULL);
	xTaskCreate(mytask3,"mytask3",1024,NULL,3,NULL);
	xTaskCreate(task4sender,"task4sender",1024,NULL,3,NULL);
	xTaskCreate(task4receiver,"task4receiver",1024,NULL,3,NULL);
}
