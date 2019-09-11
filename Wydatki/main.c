#include <stdio.h>

#include "menu.h"

void wypiszMiesiac();
void wprowadzDane();
void modyfikujDane();

int dom[] = {0, 0, 0, 0, 0, 0};
int samochod[] = {0, 0, 0, 0, 0, 0};
int nauka[] = {0, 0, 0, 0, 0, 0};
int rozrywka[] = {0, 0, 0, 0, 0, 0};
int jedzenie[] = {0, 0, 0, 0, 0, 0};
int ubrania[] = {0, 0, 0, 0, 0, 0};
int inne[] = {0, 0, 0, 0, 0, 0};

int main()
{
	//wyswietlMenu();	
	wprowadzDane();
	modyfikujDane();
	wypiszMiesiac();
	return 0;
}

void wypiszMiesiac()
{
	printf("Styczen 2019\n");
	printf("\tDom\tSamochod\tNauka\t\tRozrywka\t\tJedzenie\t\tUbrania\t\tInne\n");
	printf("1\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n", dom[0], samochod[0], nauka[0], rozrywka[0], jedzenie[0], ubrania[0], inne[0]);
	printf("2\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n", dom[1], samochod[1], nauka[1], rozrywka[1], jedzenie[1], ubrania[1], inne[1]);
	printf("3\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n", dom[2], samochod[2], nauka[2], rozrywka[2], jedzenie[2], ubrania[2], inne[2]);
	printf("4\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n", dom[3], samochod[3], nauka[3], rozrywka[3], jedzenie[3], ubrania[3], inne[3]);
	printf("5\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n", dom[4], samochod[4], nauka[4], rozrywka[4], jedzenie[4], ubrania[4], inne[4]);
	printf("6\t%d\t%d\t\t%d\t%d\t\t%d\t\t%d\t\t%d\n", dom[5], samochod[5], nauka[5], rozrywka[5], jedzenie[5], ubrania[5], inne[5]);
}

void wprowadzDane()
{
	int c;
	int i = 0;
	int kategoria;
	int kwota;

	while(i == 0)
	{
		wypiszMiesiac();
		printf("[1] Wprowadz dane\n");
		printf("[10] Zakoncz\n");

		scanf("%d", &c);		
		if(c == 10)
		{
			i++;
			continue;
		}

		printf("Wybierz kategorie:\n");
		printf("1Dom 2Samochod 3Nauka 4Rozrywka 5Jedzenie 6Ubrania 7Inne\n");

		scanf("%d", &kategoria);

		int z = 0;

		printf("Podaj kwote: ");
		scanf("%d", &kwota);
		switch(kategoria)
		{
			case 1:
				while(dom[z] != 0)
				{
					z++;
					continue;
				}
				dom[z] = kwota;
				break;	
			case 2:
				while(samochod[z] != 0)
				{
					z++;
					continue;
				}
				samochod[z] = kwota;
				break;	
			case 3:
				while(nauka[z] != 0)
				{
					z++;
					continue;
				}
				nauka[z] = kwota;
				break;
			case 4:
				while(rozrywka[z] != 0)
				{
					z++;
					continue;
				}
				rozrywka[z] = kwota;
				break;	
			case 5:
				while(jedzenie[z] != 0)
				{
					z++;
					continue;
				}
				jedzenie[z] = kwota;
				break;	
			case 6:
				while(ubrania[z] != 0)
				{
					z++;
					continue;
				}
				ubrania[z] = kwota;
				break;	
			case 7:
				while(inne[z] != 0)
				{
					z++;
					continue;
				}
				inne[z] = kwota;
				break;
			default:
				printf("Wybrana zla opcje\n");		
		}

	}

}

void modyfikujDane()
{
	int kategoria, wiersz, kwota;
	wypiszMiesiac();
	printf("Wybierz kategorie:\n");
	printf("1Dom 2Samochod 3Nauka 4Rozrywka 5Jedzenie 6Ubrania 7Inne\n");

	scanf("%d", &kategoria);

	printf("Wybierz wiesz: ");
	scanf("%d", &wiersz);

	wiersz--; //indek w tablicy jest od zera ja wybieram od 1

	printf("Podaj nowa kwote: ");
	scanf("%d", &kwota);

	switch(kategoria)
	{
		case 1:
			dom[wiersz] = kwota;
			break;	
		case 2:
			samochod[wiersz] = kwota;
			break;	
		case 3:
			nauka[wiersz] = kwota;
			break;
		case 4:
			rozrywka[wiersz] = kwota;
			break;	
		case 5:
			jedzenie[wiersz] = kwota;
			break;	
		case 6:
			ubrania[wiersz] = kwota;
			break;	
		case 7:
			inne[wiersz] = kwota;
			break;
		default:
			printf("Wybrana zla opcje\n");		
	}

}
