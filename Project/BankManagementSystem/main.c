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
	int choose;

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
					int x = 0;

					while(x == 0)
					{
						system("clear");
						puts("WELCOME TO YOUR ACCOUNT!!!");
						printf("1. Transact\t\t\t\tYour means:\t %i\n", tab[pom].means);
						puts("2. Edit");
						puts("3. Account details");
						puts("4. Log out");

						scanf("%i", &choose);

						switch(choose)
						{
							case 1:
								system("clear");				
								transact(tab, pom);
								break;
							case 2:
								system("clear");
								edit(tab, pom);
								break;
							case 3:
								system("clear");
								accountDetails(tab, pom);
								break;
							case 4:
								x++;
								break;
							default:
								puts("Wybrano zla opcje!!!");
								break;
						}
					}
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
