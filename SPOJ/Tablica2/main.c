#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *tab;

	int n;

	while(getchar() != EOF)
	{
		scanf("%d", &n);

		tab = (int*) malloc(n * sizeof(int));

	}

	free(tab);
}
