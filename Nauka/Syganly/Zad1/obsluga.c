#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "procinfo.h"

void print(int a)
{
	printf("Otrzymany sygnal: %d\n", a);
}

int main(int argc, char **argv)
{
	if(argc != 3 || argv[1][1] != '\0')
	{
		printf("Bladny numer sygnalu\n");
		exit(EXIT_FAILURE);
	}

	procinfo(argv[0]);

	int numer_sygnalu = atoi(argv[2]);

	void (*signal_routine)(int) = NULL;

	if(strcmp(argv[1], "i") == 0)
	{
		signal_routine = SIG_IGN;
		printf("Ignorowanie sygnalu ");
	} else if(strcmp(argv[1], "p") == 0 )
	{
		signal_routine = print;
		printf("Wlasna obsluga sygnalu ");
	} else
	{
		signal_routine = SIG_DFL;
		printf("Domyslna obsluga sygnalu ");
	}

	printf("%d\n", numer_sygnalu);

	if(signal(numer_sygnalu, signal_routine) == SIG_ERR)
	{
		perror("Nie mozna obsluzyc sygnalu");
		exit(EXIT_FAILURE);
	}
}
