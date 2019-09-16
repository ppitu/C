#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define ROZMIAR_PLANSZY 10

int pozycja_x = 0, pozycja_y = 0;
int koniec = 0;

void ustaw_mine(int, int);
void odkryje_plansze(int, int);

struct pole
{
	int wartosc;
	bool odkrycie;
};

struct pole plansza[ROZMIAR_PLANSZY][ROZMIAR_PLANSZY];

bool generuj_plansze()
{
	for(int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for(int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			plansza[i][j].wartosc = 0;
			plansza[i][j].odkrycie = false;
		}
	}

	return true;
}

void losuj_pozycje_miny()
{
	time_t tt;
	int poz_x;
	int poz_y;
	int ilosc = 10;

	srand((unsigned)time(&tt)); //za zarodek wstawiamy pobrany czas w sekundach

	while(ilosc > 0)
	{
		poz_x = rand()%10;
		poz_y = rand()%10;

		if(plansza[poz_x][poz_y].wartosc != 9)
		{
			ustaw_mine(poz_x,poz_y);
			ilosc--;
		}
	}
}

void ustaw_mine(int poz_x, int poz_y)
{
	if(plansza[poz_x][poz_y].wartosc != 9)
	{
		plansza[poz_x][poz_y].wartosc = 9;

		for(int i = -1; i < 2; i++)
			for(int j = -1; j < 2; j++)
			{
				if((poz_x + i) < 0 || (poz_y+j) < 0) 
					continue;
				if((poz_x + i) > 9 || (poz_y+j) > 9)
					continue;

				if(plansza[poz_x + i][poz_y + j].wartosc == 9)
					continue;

				plansza[poz_x + i][poz_y + j].wartosc += 1;
			}
	}
}

void pokaz_plansze()
{
	system("clear");
	
	printf("0123456789\n");

	for(int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for(int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			if(plansza[i][j].odkrycie == true)
			{
				if(plansza[i][j].wartosc == 0)
				{
					printf(" ");
				}
				else
				{
					printf("%i", plansza[i][j].wartosc);
				}
			}
			if(plansza[i][j].odkrycie == false)
				printf("#");

		}
		printf("\n");
	}
}

void sterowanie()
{
	printf("Podaj x: ");
	scanf("%i", &pozycja_x);
	printf("Podaj y: ");
	scanf("%i", &pozycja_y);

	if(plansza[pozycja_x][pozycja_y].wartosc == 9) //trafiles na mine
		koniec = 2;

	odkryje_plansze(pozycja_x, pozycja_y);
	pokaz_plansze();
}

void odkryje_plansze(int x, int y)
{
	if(x < 0 || x > 9)
		return;
	if(y < 0 || y > 9)
		return;
	if(plansza[x][y].odkrycie == true)
		return;
	if(plansza[x][y].wartosc != 9 && plansza[x][y].odkrycie == false)
		plansza[x][y].odkrycie = true;

	if(plansza[x][y].wartosc != 0)
		return;

	//wywolujemy funkcje dla kazdego sasiada
	odkryje_plansze(x - 1, y -1);
	odkryje_plansze(x - 1, y);
	odkryje_plansze(x - 1, y +1);
	odkryje_plansze(x + 1, y -1);
	odkryje_plansze(x + 1, y);
	odkryje_plansze(x + 1, y +1);
	odkryje_plansze(x, y -1);
	odkryje_plansze(x, y);
	odkryje_plansze(x, y +1);
}

bool czy_wygrane()
{
	int miny = 0;

	for(int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for(int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			if(plansza[j][i].odkrycie == false)
				miny++;
		}
	}

	if(miny == 10)
		return true;
	return false;
}

int main()
{
	generuj_plansze();
	losuj_pozycje_miny();

	//sleep(200);

	while(koniec == 0)
	{
		//sleep(60);
		sterowanie();
		if(czy_wygrane() == true)
			koniec = 1;
	}

	if(koniec == 1)
		printf("\nKoniec gry, Wygrales!!!\n");
	if(koniec == 2)
		printf("\nKoniec gry, Przegrales\n");

	return 0;
}
