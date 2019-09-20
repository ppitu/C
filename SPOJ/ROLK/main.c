#include <stdio.h>
#include <stdlib.h>

int main()
{
	int iletestow;
	int ileprzesuniecie;
	int *tab;

	scanf("%i", &iletestow);
	scanf("%i", &ileprzesuniecie);

	tab = (int *) malloc(iletestow* sizeof(int));

	for(size_t i = 0; i < iletestow; i++)
		scanf("%i", &tab[i]);
	for(size_t i = ileprzesuniecie; i < iletestow; i++)
		printf("%i ", tab[i]);
	for(size_t i = 0; i < ileprzesuniecie; i++)
		printf("%i ", tab[i]); 

	printf("\n");

	free(tab);

	return 0;
}
