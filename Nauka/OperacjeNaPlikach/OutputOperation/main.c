#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE *fp;
	char data;

	printf("Open file\n");
	fp = fopen("test.txt", "r");
	if(fp == NULL)
	{
		printf("Could not open file\n");
		exit(1);
	}

	while((data = getc(fp)) != EOF)
		printf("%c", data);
	
	fclose(fp);

	return 0;
}
