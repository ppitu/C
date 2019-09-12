#include <stdio.h>
#include <string.h>

int main()
{
	int k;
	int s = 0;
	char c[12];	

	int suma = 0;

	scanf("%i", &k);

	for(int j = 0; j < k; j++)
	{
		scanf("%s", c);

		if(strcmp(c, "for") == 0)
		{
			suma++;
			continue;
		}

		if(strcmp(c, "end") == 0)
		{
			if(suma > s)
				s = suma;

			suma--;
			continue;
		}

	}

	if(s == 0)
		printf("O(1)\n");
	if(s == 1)
		printf("O(n)\n");
	if(s > 1)
		printf("O(n^%i)\n", s);

	return 0;
}
