#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

#define ROZMIAR_PLANSZY 10

int pozycja_x = 0, pozycja_y = 0; //Globalne zmienne do ustawienie pozycje (dane sa pobierane z klawiatury w fukcji sterowanie())
int koniec = 0;

void ustawMine(int, int);
void odkryjePlansze(int, int);

struct pole
{
	int wartosc;
	bool odkrycie;
};

struct pole plansza[ROZMIAR_PLANSZY][ROZMIAR_PLANSZY];

void generujPlansze() //Uzupelnianie tablicy plansza 
{
	for(int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		for(int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			plansza[i][j].wartosc = 0;
			plansza[i][j].odkrycie = false;
		}
	}
}

void losujPozycjeMiny(int o_poz_x, int o_poz_y) //losowanie min
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

		if(plansza[poz_x][poz_y].wartosc != 9) //sprawdzenie czy na danym polu nie ma juz miny
		{
			ustawMine(poz_x,poz_y); //wywolanie funkcji ustawiajacej miny
			ilosc--;
		}
	}
}

void ustawMine(int poz_x, int poz_y) //funkcja ustawiajaca miny oraz wartosci wokol nich
{
	if(plansza[poz_x][poz_y].wartosc != 9) //sprawdznie czy nie ma miy
	{
		plansza[poz_x][poz_y].wartosc = 9; //ustawienie miny

		//ustawienie wartosc wokol miny
		for(int i = -1; i < 2; i++)
			for(int j = -1; j < 2; j++)
			{
				if((poz_x + i) < 0 || (poz_y+j) < 0) //sprawdzenie czy nie ustawiamy watosci poza plansza
					continue;
				if((poz_x + i) > 9 || (poz_y+j) > 9) //sprawdzenie czy nie ustawiamy wartosci poza plansza
					continue;

				if(plansza[poz_x + i][poz_y + j].wartosc == 9) //sprawdzenie czy to nie mina
					continue;

				plansza[poz_x + i][poz_y + j].wartosc += 1; //dodanie jeden do wartosci
			}
	}
}

void pokazPlansze() //funkcja pokazuje plasze
{
	system("clear"); //czyszczenie terminala
	
	printf(" 0123456789\n"); //wyswietlenie wspolzednych kolumn

	for(int i = 0; i < ROZMIAR_PLANSZY; i++)
	{
		printf("%i", i); //wyswietlenie wspolrzednych wierszy
		for(int j = 0; j < ROZMIAR_PLANSZY; j++)
		{
			if(plansza[i][j].odkrycie == true) //jesli odkrylismy pole
			{
				if(plansza[i][j].wartosc == 0) //jesli wartosc 0 wyswietl spacje
				{
					printf(" ");
				}
				else //inaczej wyswietl numer pola
				{
					printf("%i", plansza[i][j].wartosc); 
				}
			}
			if(plansza[i][j].odkrycie == false) //jesli nie odkryte wyswietl #
			{
				printf("\033[1;31m");
				printf("#");
				printf("\033[0m");
			}

		}
		printf("\n");
	}
}

void sterowanie() //funkcja za pomoca ktorej wprowadzamy wspolrzedne ktore chcemy sprawdzic
{
	printf("Podaj wiersz: ");
	scanf("%i", &pozycja_x);
	printf("Podaj kolumne: ");
	scanf("%i", &pozycja_y);

	if(plansza[pozycja_x][pozycja_y].wartosc == 9) //trafiles na mine
		koniec = 2;

	odkryjePlansze(pozycja_x, pozycja_y); //odkrywanie planszy
	pokazPlansze(); //wywietlanie planszy
}

//funkcja odkrywa plansze, wykonuje sie rekurencyjnie do napotkania nastepujacych warunkow:
// - czy nie wychodzi poza plansze
// - czy pole juz odkryte, aby nie odkrywac dwa razy
// - czy pole nie jest miny, aby nie odkryc miny
//odkrywanie planszy nastepuje rekurencyjnie i odkrywa wszystkie pola do okola tak oby odkryc wszystkie pola z wartoscia 0 oraz ich sasiadow
//gdy pole ma inna wartosc niz 0, odkrywamy je i wychodzimy zeby nie odkryc za duzo
void odkryjePlansze(int x, int y)
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
	odkryjePlansze(x - 1, y -1);
	odkryjePlansze(x - 1, y);
	odkryjePlansze(x - 1, y +1);
	odkryjePlansze(x + 1, y -1);
	odkryjePlansze(x + 1, y);
	odkryjePlansze(x + 1, y +1);
	odkryjePlansze(x, y -1);
	odkryjePlansze(x, y);
	odkryjePlansze(x, y +1);
}

bool czyWygrane() // sprwdzenie czy sie wygralo, liczy liczbe nieodkrytych pol
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
	generujPlansze();
	int x, y;

	printf("Podaj wiersz: ");
	scanf("%i", &x);
	printf("Podaj kolumne: ");
	scanf("%i", &y);
	losujPozycjeMiny(x, y);
	odkryjePlansze(x, y);
	pokazPlansze();	

	while(koniec == 0)
	{
		sterowanie();
		if(czyWygrane() == true)
			koniec = 1;
	}

	if(koniec == 1)
		printf("\nKoniec gry, Wygrales!!!\n");
	if(koniec == 2)
		printf("\nKoniec gry, Przegrales\n");

	return 0;
}
