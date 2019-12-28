#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char **argv)
{
	if(argc < 3)
	{
		printf("Uzycie: %s plik_zrodlowy plik_docelowy\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	char *zrodlowy = argv[1];
	char *docelowy = argv[2];

	int fd1 = open(zrodlowy, O_RDONLY);

	if(fd1 < 0) //nie udalo sie otworzyc
	{
		printf("nie mozna otworzyc pliku zrodlowego %s: %s\n", zrodlowy, strerror(errno));
		exit(EXIT_FAILURE);
	}

	int fd2 = open(docelowy, O_WRONLY | O_CREAT, S_IRWXU | S_IRWXG | S_IRWXO );
	if(fd2 < 0) //nie udalo sie otworzyc
	{
		printf("nie mozna otworzyc pliku docelowego %s: %s\n", docelowy, strerror(errno));
		exit(EXIT_FAILURE);
	}

	printf("Kopiuje z %s do %s.\n", zrodlowy, docelowy);

	char buf[BUF_SIZE] = { 0 }; //zmienna na przeczytane dane

	int readd = 0;
	int writte = 0;

	while((readd = read(fd1, buf, BUF_SIZE)) != 0)
	{
		printf(".");
		writte = write(fd2, buf, BUF_SIZE);

		if(writte < 0)
		{
			printf("write() blad: %s\n", strerror(errno));
			exit(EXIT_FAILURE);
		}
	}

	printf("\n");

	if(readd < 0)
	{
		printf("read() blad: %s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}

	close(fd1);
	close(fd2);
}
