#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n, k;

	scanf("%d", &n);
	scanf("%d", &k);

	int *tab = (int*)malloc(n * sizeof(int));
	int *tabhelp = (int*)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &tab[i]);
	}
	
	int w = k;

	for(int i = 0; i < n; i++)
	{
		if(w < n)
		{
			tabhelp[i] = tab[w];
		}
		else
			break;

		w++;
	}	
	
		
	for(int i = 0; i < k; i++)
	{
		tabhelp[i + k - 1] = tab[i];
	}

	for(int i = 0; i < n; i++)
		printf("%d ", tabhelp[i]);
	
	//printf("\n");

	free(tabhelp);
	free(tab);

	return 0;
}
