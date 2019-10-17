#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	char imie[200];
	char nazwisko[200];
	char dataurodzenia[200];
	char adres[200];
	char nazwa[200];
	char haslo[200];
} Konto;

void clear()
{
	char ch;
	
	while((ch = getchar()) != '\n');
}

//Funkcja pobiera dowolny string i zapisuje go do zmiennej str, zmienna napis przekazuje opsij ktory mozna podac do opisania danych wejsciowych
void getString(char str[])
{
	char ch;
	int n = 0;

	while((ch = getchar()) != '\n')
	{
		str[n] = ch;
		n++;
	}
	
	str[n] = '\0';
}

//Funckja pobiera dane z zapisanego pliku i od uzytkowanika i sprawdza czy dany uzytkownik istnieje oraz czy podal prawidlowe dane
int logowanie()
{
	FILE *fp;
	Konto konto;

	
	system("clear");
}

//Funckja sluzy do zalozenia konta
void rejestracja()
{

	Konto konto;
	
	FILE *fp;	

	system("clear");
	clear();
	printf("Imie: ");
	getString(konto.imie);
	printf("Nazwisko: ");
	getString(konto.nazwisko);
	printf("Data urodzenia: ");
	getString(konto.dataurodzenia);
	printf("Adres: ");
	getString(konto.adres);
	printf("Nazwa uzytkownika: ");
	getString(konto.nazwa);
	printf("Haslo: ");
	getString(konto.haslo);

	fp = fopen("daneuzytkownika.txt", "a");
	
	fprintf(fp, "%s\t", konto.imie);
	fprintf(fp, "%s\t", konto.nazwisko);
	fprintf(fp, "%s\t", konto.dataurodzenia);
	fprintf(fp, "%s\t", konto.adres);
	fprintf(fp, "%s\t", konto.nazwa);
	fprintf(fp, "%s\n", konto.haslo);

	fclose(fp);
} 

int main()
{
	int opcja;
	int exit = 0;

	while(exit == 0)
	{
		puts("Witaj w systemie szpitalnym!!!");
		puts("1. Logowanie");
		puts("2. Zaloz konto");
		puts("3. Sprawdz terminy do lekarza");
		puts("4. Aktualnosci");
		puts("5. EXIT");
		puts("===========================================");
		printf("\n\n\nWybierz jedna z opcji: ");
		scanf("%d", &opcja);
		
		switch(opcja)
		{
			case 1:
			
			case 2:
				rejestracja();
				break;
		
			case 5:
				exit++;
				break;
			default:
				break;
		}
	}
	return 0;
}	
