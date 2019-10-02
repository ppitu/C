#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void transact(data *tab, int i)
{
	int cho = 0;
	int ops;
	int deposit;

	while(cho == 0)
	{
		system("clear");
		puts("1. Add measures");
		puts("2. Withdraw measures");
		puts("3. EXIT");

		scanf("%i", &ops);

		switch(ops)
		{
			case 1:
				system("clear");
				puts("Enter how much you want to deposit: ");
				scanf("%i", &deposit);
				tab[i].means += deposit;
				puts("Means have been added");
				puts("Press enter to continue...");
				getchar();
				getchar();
				break;
			case 2:
				system("clear");
				puts("Enter how much you want to withdraw");
				scanf("%i", &deposit);
				if(deposit > tab[i].means)
					puts("You don't have enough means");
				else
				{
					tab[i].means -= deposit;
					puts("Means have been withdraw");
				}
				puts("Press enter to continue...");
				getchar();
				getchar();
				break;
			case 3:
				cho++;	
				break;
			default:
				puts("Wrong options selected!");
				break;
		}
	}	
}
