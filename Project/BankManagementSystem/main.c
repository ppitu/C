#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "header.h"

int TAB_SIZE = 200;

int main()
{
	int ops = 0;
	int option;
	int pom = 0;

	data *tab;

	tab = (data*) malloc(TAB_SIZE * sizeof(data));

	for(size_t i = 0; i < TAB_SIZE; i++)
		tab[i].in = false;

	while(ops == 0)
	{
		system("clear");
		puts("Welcome to the banking system");
		puts("Choose one of the options");
		puts("1. Create New Account");
		puts("2. Sign In");
		puts("3. EXIT");

		scanf("%i", &option);
	
		switch(option)
		{
			case 1:
				newAcc(tab);
				break;
			case 2:
				pom = login(tab);
				if(pom == -1)
				{
					puts("Invalid data entered");
					puts("Press enter to continue...");
					getchar();
					getchar();
				}
				else
				{
					edit(tab, pom);
					transact(tab, pom);
				}
				break;
			case 3:
				ops++;
				break;
			default:
				puts("Wrong opstions selected");
				break;
		}
	}


	free(tab);
}	
