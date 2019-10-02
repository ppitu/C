#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void edit(data *tab, int i)
{
	int opt;
	int cho = 0;

	while(cho == 0)
	{
		system("clear");
		puts("SELECT OPTIONS");
		puts("1. Change name");
		puts("2. Change password");
		puts("3. Change date of birth");
		puts("4. Change phone number");
		puts("5. Change address");
		puts("6. Chamge Citizenship Nubmer");
		puts("7. EXIT");

		scanf("%i", &opt);

		system("clear");

		switch(opt)
		{
			case 1:
				printf("Add new name: ");
				scanf("%s", tab[i].name);
				system("clear");
				puts("The name has benn changed!");
				puts("Press enter to continue...");
				getchar();
				getchar();	
				break;

			case 2:
				printf("Add new password: ");
				scanf("%s", tab[i].password);
				system("clear");
				puts("The password has benn changed!");
				puts("Press enter to continue...");
				getchar();
				getchar();	
				break;

			case 3:
				printf("Add new date of birth: ");
				scanf("%s", tab[i].dateofbirth);
				system("clear");
				puts("The date of birth has benn changed!");
				puts("Press enter to continue...");
				getchar();
				getchar();	
				break;

			case 4:
				printf("Add new phone number: ");
				scanf("%i", &tab[i].phone);
				system("clear");
				puts("The phone number has benn changed!");
				puts("Press enter to continue...");
				getchar();
				getchar();	
				break;

			case 5:
				printf("Add new address: ");
				scanf("%s", tab[i].address);
				printf("Add new house number: ");
				scanf("%i", &tab[i].housenumber);
				system("clear");
				puts("The address has benn changed!");
				puts("Press enter to continue...");
				getchar();
				getchar();	
				break;
			case 6:
				printf("Add new citizenship number: ");
				scanf("%s", tab[i].citizenshipnumber);
				system("clear");
				puts("The citizenship number has benn changed!");
				puts("Press enter to continue...");
				getchar();
				getchar();	
				break;

			case 7:
				cho++;
				break;
			default:
				puts("Wrong options selected");
				break;
		}
	}
}
