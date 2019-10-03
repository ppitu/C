#include <stdio.h>
#include <stdlib.h>


int leap(int year)
{
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int numberOfDay(int month, int year)
{
	int tab[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int tab1[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	if(leap(year))
		return tab1[month];
	else 
		return tab[month];
}

int dayOfWeek(int m, int y)
{
	int d = 1;
	int Y,C,M,N,D;

	M = 1 + (9 + m) % 12;
	Y = y - (M > 10);
	C = Y / 100;
	D = Y % 100;

	N =((13 * M - 1) / 5 + D + D / 4 + C / 4 + 5 * C + d) % 7;

	return (7 + N) % 7;
}

void printCalendar(int month, int year)
{
	puts("Sun\tMon\tTue\tWed\tThu\tFri\tSat");

	int x = dayOfWeek(month, year);

	int numberofday = numberOfDay((month - 1), year);

	for(size_t i = 0; i < x; i++)
		printf("\t");

	for(int i = 1; i <= numberofday; i++)
	{
		printf("%i\t", i);
			
		x++;

		if((x % 7) == 0)
			printf("\n");
	}
	printf("\n");

}

int main()
{
	system("clear");
	int month, year;
	printf("Enter the month: ");
	scanf("%i", &month);
	printf("Enter the year: ");
	scanf("%i", &year);

	printCalendar(month, year);
}
