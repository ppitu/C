#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void accountDetails(data* tab, int i)
{
	system ("clear");
	puts("Yout account details");
	printf("Name:\t\t\t %s\n", tab[i].name);
	printf("Surename:\t\t %s\n", tab[i].surename);
	printf("Date of birth:\t\t %s\n", tab[i].dateofbirth);
	printf("Password:\t\t %s\n", tab[i].password);
	printf("Address:\t\t %s %i\n", tab[i].address, tab[i].housenumber);
	printf("Citizenship number:\t %s\n", tab[i].citizenshipnumber);
	printf("Phone:\t\t\t %i\n", tab[i].phone);
	printf("Means:\t\t\t %i\n", tab[i].means);
	puts("Press enter to continue...");
	getchar();
	getchar();
}
