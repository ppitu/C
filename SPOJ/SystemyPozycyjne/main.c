#include <stdio.h>

void zamianaSzes(int );
void zamianaJed(int );

int main()
{
	int n, liczba;

	scanf("%d", &n);

	for( int i = 0; i < n; i++)
	{
		scanf("%d", &liczba);
		zamianaSzes(liczba);
		printf(" ");
		zamianaJed(liczba);
		printf("\n");
	}	

	return 0;	
}

void zamianaSzes(int x)
{
	if(x > 0)
	{
		zamianaSzes(x / 16);
		int liczba = x % 16;
		char znak;
		if( liczba >= 10 )
			znak = 'A' + liczba - 10;
		else
			znak = liczba + '0';
		printf("%c", znak);
	}
}

void zamianaJed(int x)
{
	if(x > 0)
	{
		zamianaJed(x / 11);
		int liczba = x % 11;
		char znak;
		if(liczba >= 10)
			znak = 'A';
		else 
			znak = liczba + '0';
		printf("%c", znak);
	}
}
