#include <stdio.h>

int zeller(int m, int y){
	int d = 1;
	int Y, C, M, N, D;
	M = 1 + (9 + m) % 12;
	Y = y - ( M > 10);
	C = Y / 100;
	D = Y % 100;
	N = ((13 * M - 1) / 5 + D + D / 4 + C / 4 + 5 * C +d) % 7;
	return (7 + N) % 7;
}

void displayMonth(int month, int year)
{
	int dayInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int startday = zeller(month, year);
	int day = 1;
	
	puts("Sun\tMon\tTue\tWen\tThu\tFri\tSat");
	for(int i = 0; i < dayInMonth[month - 1]; i++)
	{
		if(startday > i)
		{
			printf("\t");
			continue;
		}

		if((i % 7) == 0)
			printf("\n");
		printf("%d\t", day);
		day++;
	}
}

int main()
{
	displayMonth(10, 2019);
}
