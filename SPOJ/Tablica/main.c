#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	
	int i = 1;

	char *tab;

	tab = malloc(i * sizeof(char));

	do
	{
		tab = realloc(tab, i * sizeof(char));
		c = getchar();
		if(c == ' ')
			continue;
		if(c == '\n')
			continue;
		tab[i - 1] = c;
		i++;

	} while( c != '\n');
	
	i--;

	for(int j = 0; j < i; j++)
	{
		printf("%c", tab[i - 1 - j]);
	}

	printf("\n");

	free(tab);

	return 0;
}
