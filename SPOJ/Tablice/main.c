#include <stdio.h>

int main(void)
{
	int liczbaTestow;
	int liczbaLiczb;
	int liczba;
	int tab[100];
	int tabpom[100];

	scanf("%d", &liczbaTestow);

	for(int i = 0; i < liczbaTestow; i++)
	{
		int k = 0;

		scanf("%d", &liczbaLiczb);

		for(int j = 0; j < liczbaLiczb; j++)
		{
			scanf("%d", &liczba);
			tab[j] = liczba;		
		}

		for(int j = liczbaLiczb; j > 0; j--)
		{
			tabpom[k] = tab[j - 1];
			k++;
		}	
	
		for(int j = 0; j < liczbaLiczb; j++)
		{
			printf("%d ", tabpom[j]);
		}
		printf("\n");
	}

	//printf("%d\n", liczbaTestow);
	return 0;
}
