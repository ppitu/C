#include <stdio.h>
#include <stdlib.h>

int  NUMBERCUSTOMERACCOUNT;

typedef struct 
{
	int number;
	char name[200];
	char phone[200];
	char street[200];
	char city[200];	

} Customer;

FILE *fp;

void writeFile(Customer);

void getString(char str[], char string[])
{
	char ch;
	int i = 0;

	puts(string);
	while((ch = getchar()) != '\n')
	{
		str[i] = ch;
		i++;
	}

	str[i] = '\0';
}

void getStringFromFile(char str[], FILE *fp)
{
	char ch;
	int i = 0;

	while(((ch = fgetc(fp)) != '\n') || (ch != '\t'))
	{
		str[i] = ch;
		i++;
	}

	str[i] = '\0';
}

int countLines(FILE *fp)
{
	char ch;
	int lines = 0;

	if(fp == NULL)
		return 0;
	
	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
			lines++;
	}

	return lines;
}

void input()
{
	Customer cust;

	getString(cust.name, "User name:");
	getString(cust.phone, "User phone: ");
	getString(cust.city, "City: ");
	getString(cust.street, "Street: ");	
	
	writeFile(cust);
}

void writeFile(Customer c)
{
	fp = fopen("data.txt", "a");

	fprintf(fp, "%s\t", c.name);
	fprintf(fp, "%s\t", c.phone);
	fprintf(fp, "%s\t", c.city);
	fprintf(fp, "%s\t", c.street);

	fclose(fp);
}

void search()
{
	Customer *cust;

	fp = fopen("data.txt", "r");

	int lines = countLines(fp);

	cust = malloc(lines *sizeof(Customer));


	for(int i = 0; i < lines; i++)
	{
			
	}
	
	free(cust);

	fclose(fp);
}

void output()
{

}

int main()
{
	//input();

	search();
	return 0;
}
