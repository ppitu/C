#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "procinfo.h"

#define N 3 //ile razy otworzyc procesy

int main(int argc, char **argv)
{
	procinfo(argv[0]);

	for(int i = 0; i < N; i++)
	{
		switch(fork())
		{
			case -1:
				perror("fork error");
				exit(EXIT_FAILURE);

			case 0:
				sleep(1);

				procinfo(argv[0]);	
				break;

			default:
				sleep(2);
		}
	}
}
