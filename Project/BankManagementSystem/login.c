#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "header.h"

int login(data * tab)
{
	char nick[200];
	char password[200];

	int cho = 0;
	system("clear");
	printf("Enter your name: ");
	scanf("%s", nick);

	printf("Enter your password: ");
	scanf("%s", password);

	int i;

	for(i = 0; i < TAB_SIZE; i++)
	{
		if(compareString(nick, tab[i].name) == 0)
		{
			if(compareString(password, tab[i].password) == 0)
			{
				cho++;
				break;
			}
		}
	}

	if(cho == 1)
		return i;
	else 
		return -1;
}
