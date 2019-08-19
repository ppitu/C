#include <stdio.h>

int main()
{
	int c, k, w, n;

	scanf("%d", &n);

	for(int i = 0; i < n; i++)
	{
		scanf("%d", &c);
		scanf("%d", &k);
		scanf("%d", &w);

		if((c*w) <= k)
			printf("yes\n");
		else
			printf("no\n");
	}

	return 0;
}
