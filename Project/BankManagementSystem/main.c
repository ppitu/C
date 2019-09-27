#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int TAB_SIZE = 1;

struct Data
{
	bool in;
	char name[200];
	char surename[200];
	char dateofbirth[10];
	char address[200];
	char password[200];
	char citizenshipnumber[7];
	int phone;
	int housenumber;
};

typedef struct Data data;

void menu()
{
	puts("CUSTOMER ACCOUNT BANKING MANAGMENT SYSTEM");
	puts("WELCOME O THE MAIN MENU");
	puts("1. Create new account");
	puts("2. Update information of existing account");
	puts("3. Chcek the details of existing account");
	puts("4. For transactions");
	puts("5. Removin existing account");
	puts("6. View customer`s list");
	puts("7. Exit");
}

void newAcc(data *tab)
{
	int size = 0;
	//Szukanie wolnego miejsa w istniejacej tablicy
	for(size_t i = 0; i < TAB_SIZE; i++)
	{
		if(!tab[i].in)
			break;		
		size++;
	}

	char name[200];
	char surename[200];
	char dateofbirth[200];
	char citizenshipnumber[200];
	char address[200];
	char password[200];
	int phone;

	tab[size].in = true;

	system("clear");
	puts("CREATE NEW ACCOUNT");
	printf("Name: ");
	scanf("%s", tab[size].name);
	printf("Surename: ");
	scanf("%s", tab[size].surename);
	printf("Date of Birth: ");
	scanf("%s", tab[size].dateofbirth);
	printf("Addres: ");
	scanf("%s", tab[size].address);
	scanf("%i", &tab[size].housenumber);
	
}

void viewList(data *tab)
{
	for(size_t i = 0; i < TAB_SIZE; i++)
	{
		if(tab[i].in)
		{
			printf("%s\t%s\t%s\t%s %i\n", tab[i].name, tab[i].surename, tab[i].dateofbirth, tab[i].address), tab[i].housenumber);
		}
	}
}

int main()
{
	data *tab;

	tab = (data*) malloc(TAB_SIZE * sizeof(data *));

	menu();
	newAcc(tab);
	printf("%s\n", tab[0].name);
	viewList(tab);
	
	free(tab);
}	
