#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxNameLength 100

typedef struct
{
	char phone[MaxNameLength];
	char name[MaxNameLength];
	char address[MaxNameLength];
	char email[MaxNameLength];
} Contact;

FILE *fp;

void clear();
int countLines();

int search(char name[])
{
	int size = countLines();
	char ch;
	char str[MaxNameLength];
	int n = 0;
	int x = 0;

	Contact *list;

	list = malloc(size * sizeof(Contact));

	fp = fopen("data.txt", "r");

	for(int i = 0; i < size; i++)
	{
		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';
		strcpy(list[i].name, str);
		n = 0;

		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';
		strcpy(list[i].phone, str);
		n = 0;

		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		strcpy(list[i].address, str);

		n = 0;
	
		while((ch = fgetc(fp)) != '\n')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		strcpy(list[i].email, str);
		n = 0;
	}

	fclose(fp);

	for(int i = 0; i < size; i++)
	{
		if(strcmp(list[i].name, name) == 0)
			x++;
		
	}

	free(list);

	if(x == 0)
		return -1;
	else 
		return x;
}

void copy(Contact a, Contact b)
{
	strcpy(a.name, b.name);
	strcpy(a.phone, b.phone);
	strcpy(a.address, b.address);
	strcpy(a.email, b.email);
}

int partiton(Contact tab[], int p, int r)
{
	char str[MaxNameLength];
	strcpy(str, tab[r].name);
	Contact w;

	int i = (p - 1);
	
	for(int j = p; j <= r - 1; j++)
	{
		if(strcmp(tab[j].name, str) <= 0)
		{
			i++;
			copy(w, tab[i]);
			copy(tab[i], tab[j]);
			copy(tab[j], w);
		}
	}
	copy(tab[i+1], tab[r]);
	return (i + 1);

}

void quickSort(Contact tab[], int p, int r)
{
	int q;
	if(p < r)
	{
		q = partiton(tab, p, r);

		quickSort(tab, p , q - 1);
		quickSort(tab, q + 1, r);
	}
}

void sort()
{
	Contact *list;
	int size = countLines();
	char ch, str[MaxNameLength];
	int n = 0;

	list = malloc(size * sizeof(Contact));

	fp = fopen("data.txt", "r");

	for(int i = 0; i < size; i++)
	{
		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';
		strcpy(list[i].name, str);
		n = 0;

		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';
		strcpy(list[i].phone, str);
		n = 0;

		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		strcpy(list[i].address, str);

		n = 0;
	
		while((ch = fgetc(fp)) != '\n')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		strcpy(list[i].email, str);
		n = 0;
	}

	fclose(fp);

	quickSort(list, 0, size - 1);

	for(int i = 0; i < size; i++)
	{
		printf("%s %s %s %s\n", list[i].name, list[i].phone, list[i].address, list[i].email);
	}

	free(list);
}

void getString(char *str, int size)
{
	int i = 0;
	int n = 0;
	char ch;

	while((ch = getchar()) != '\n')
	{
		str[i] = ch;
		i++;
	}

	str[i] = '\0';
}

void clear()
{
	while(getchar() != '\n');
}

int countLines()
{
	int lines = 0;
	char ch;

	fp = fopen("data.txt", "r");
	if(fp == NULL)
	{
		puts("Problem opening the file");
		exit(1);
	}

	while((ch = fgetc(fp)) != EOF)
	{
		if(ch == '\n')
			lines++;
	}
	
	return lines;
	fclose(fp);
}

void newContact()
{
	Contact list;
	fp = fopen("data.txt", "a");
	if(fp == NULL)
	{
		printf("Problem z otwarciem pliku\n");
		exit(1);
	}

	printf("Name: ");
	getString(list.name, MaxNameLength);

	fprintf(fp, "%s\t", list.name);
	
	printf("Phone: ");
	getString(list.phone, MaxNameLength);
	
	fprintf(fp, "%s\t", list.phone);

	printf("Address: ");
	getString(list.address, MaxNameLength);
	
	fprintf(fp, "%s\t", list.address);

	printf("Email: ");
	getString(list.email, MaxNameLength);
	
	fprintf(fp, "%s\n", list.email);

	
	fclose(fp);
}

void listOfContact()
{
	int lines = countLines();	
	char ch;

	fp = fopen("data.txt", "r");
	if(fp == NULL)
	{
		puts("Problem z otwarciem pliku");
		exit(1);
	}
	
	int n = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
	}


	fclose(fp);
}

void edit()
{
	Contact *list;
	char name[MaxNameLength];
	printf("Podaj imie: ");
	scanf("%s", name);

	
	list = malloc(size * sizeof(Contact));

	fp = fopen("data.txt", "r");

	for(int i = 0; i < size; i++)
	{
		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';
		strcpy(list[i].name, str);
		n = 0;

		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';
		strcpy(list[i].phone, str);
		n = 0;

		while((ch = fgetc(fp)) != '\t')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		strcpy(list[i].address, str);

		n = 0;
	
		while((ch = fgetc(fp)) != '\n')
		{
			str[n] = ch;
			n++;
		}

		str[n] = '\0';

		strcpy(list[i].email, str);
		n = 0;
	}

	fclose(fp);
	free(list);
}

int main()
{
	newContact();
	listOfContact();
}

