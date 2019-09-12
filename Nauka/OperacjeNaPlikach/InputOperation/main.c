#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	FILE *fp;
	char data;

	printf("Opening the file\n");
	fp = fopen("test.c", "w");
	if(fp == NULL)
	{
		printf("Could not open file\n");
		exit(1);
	}
	printf("Enter some text:\n");
	
	while((data = getchar()) != EOF)
	{
		putc(data, fp);
	}

	printf("Closing the file\n");
	fclose(fp);

	return 0;
}
