#include <stdio.h>

int main()
{
	char c, znak; 
	int liczba, liczba1; 
	char x, y, z;
	int j = 0;
	int wynik;
	
	while(j == 0)
	{
		scanf("%c", &znak);
		scanf("%c", &x);
		if(znak == EOF)
		{
			j++;
			continue;
		}
		
		scanf("%i", &liczba);
		scanf("%c", &y);
		scanf("%i", &liczba1);
		scanf("%c", &z);

		//printf("%c %c %c\n", znak, liczba, liczba1);

		switch(znak)
		{
			case '+':
				wynik = liczba + liczba1;
				break;
			case '-':
				wynik = liczba - liczba1;
				break;
			case '*':
				wynik = liczba * liczba1;
				break;
			case '/':
				wynik = liczba / liczba1;
				break;
			case '%':
				wynik = liczba % liczba1;
				break;
		}
		printf("%i\n", wynik);
	}

	return 0;
}
