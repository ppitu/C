#include <stdio.h>

int main()
{
	float a, b, c;
	float wynik;

	scanf("%e", &a);
	scanf("%e", &b);
	scanf("%e", &c);

	if(a == 0 && b != c)
		printf("BR\n");
	else if(a == 0 && b == c)
		printf("NWR\n");
	else 
	{
		wynik = (-b + c)/a;
		printf("%.2f\n", wynik);
	}	

	return 0;
}
