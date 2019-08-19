#include <stdio.h>

int main()
{
	int n1, n2, k1, k2;

	scanf("%d", &n1);
	scanf("%d", &n2);
	scanf("%d", &k1);
	scanf("%d", &k2);

	int wynik;

	wynik = (n1*k1) + (n2*k2);

	printf("%d", wynik);

	return 0;
}
