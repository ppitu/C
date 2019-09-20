#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int iletestow;
	int ileelementow;
	
	int tab[100];

	scanf("%i", &iletestow);
	
	for(size_t i = 0; i < iletestow; i++)
	{
		scanf("%i", &ileelementow);
		for(size_t j = 0; j < ileelementow; j++)
			scanf("%i", &tab[j]);

		for(size_t j = 1; j < ileelementow; j++)
			printf("%i ", tab[j]);
			
		printf("%i\n", tab[0]);
	}	

	return 0;
}
