#include <stdio.h>
#include <stdbool.h>

#include "header.h"

void viewList(data *tab)
{
	puts("Name\tSurename\tDate of birth\tAddress\tPhone\tMeans");
	
	for(size_t i = 0; i < TAB_SIZE; ++i)
	{
		if(tab[i].in)
		{
			printf("%s\t%s\t%s\t%s %i\t%i\t%i\n", tab[i].name, tab[i].surename, tab[i].dateofbirth, tab[i].address, tab[i].housenumber,tab[i].phone, tab[i].means);
		}
	}
}
