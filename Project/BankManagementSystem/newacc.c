#include <stdio.h>
#include <stdlib.h>

#include "header.h"

void newAcc(data *tab)
{
	int size = 0;

	//Szukanie wolnego miejsa w istniejacej tablicy
	for(size_t i = 0; i < TAB_SIZE; i++)
	{
		if(!tab[i].in)
			break;		
		size++;
	}

	/*if(size == TAB_SIZE)
	{
		size++;
		TAB_SIZE++;
		tab = (data*)realloc(tab, TAB_SIZE*sizeof(data));
	}*/

	tab[size].in = true;

	system("clear");
	puts("CREATE NEW ACCOUNT");
	printf("Name: ");
	scanf("%s", tab[size].name);
	printf("Surename: ");
	scanf("%s", tab[size].surename);
	printf("Date of Birth: ");
	scanf("%s", tab[size].dateofbirth);
	printf("Citizen Ship Number: ");
	scanf("%s", tab[size].citizenshipnumber);
	printf("City: ");
	scanf("%s", tab[size].address);
	printf("House number: ");
	scanf("%i", &tab[size].housenumber);
	printf("Phone: ");
	scanf("%i", &tab[size].phone);
	printf("Password: ");
	scanf("%s", tab[size].password);
	printf("Means: ");
	scanf("%i", &tab[size].means);
}

