#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void erase(data *tab)
{
	char nick[200];
	char password[200];
	int ops;
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
				break;
			}
		}
	}

	puts("Are you sure you want to delete account?");
	puts("1. YES");
	puts("2. NO");
	scanf("%i", &ops);
	
	switch(ops)
	{
		case 1:
			tab[i].in = false;
			puts("Account has been deleted");
			puts("Press enter to continue...");
			getchar();
			getchar();
			break;
		case 2:
			break;
		default:
			break;
		
	}

}
