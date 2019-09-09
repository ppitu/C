#include <stdio.h>

#include "plansza.h"

void wyswietlPlansze()
{
	for(int i = 0; i < 20; i++)
	{
		for(int j = 0; j < 20; j++)
		{
			printf("| ");
		}
		printf("\n");
	}		
}
