#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int TAB_SIZE = 1;

struct Data
{
	bool in;
	char *name;
	char *surename;
	char *dateofbirth;
	char *address;
	char *password;
	char *citizenshipnumber;
	int means;
	int phone;
	int housenumber;
};

typedef struct Data data;

void getString(data *tab, int size, int ops)
{
	

}

//This function is used to compare text
int compareString(char* first, char* second)
{
	while(*first == *second)
	{
		if(*first == '\0' || *second == '\0')
			break;

		first++;
		second++;
	}

	if(*first == '\0' && *second == '\0')
		return 0;
	else 
		return -1;
}

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

	char name[200];
	char surename[200];
	char date[200];
	char citizen[200];
	char city[200];
	char password[200];

	//Szukanie wolnego miejsa w istniejacej tablicy
	for(size_t i = 0; i < TAB_SIZE; i++)
	{
		if(!tab[i].in)
			break;		
		size++;
	}

	tab[size].in = true;

	system("clear");
	puts("CREATE NEW ACCOUNT");
	printf("Name: ");
	scanf("%s", name);
	tab[size].name = (char*)realloc(tab[size].name ,strlen(name) * sizeof(char));
	strcpy(tab[size].name, name);
	printf("Surename: ");
	scanf("%s", surename);
	tab[size].surename = (char*)realloc(tab[size].surename ,strlen(surename) * sizeof(char));
	strcpy(tab[size].surename, surename);
	printf("Date of Birth: ");
	scanf("%s", date);
	tab[size].dateofbirth = (char*)realloc(tab[size].dateofbirth ,strlen(date) * sizeof(char));
	strcpy(tab[size].dateofbirth, date);
	printf("Citizen Ship Number: ");
	scanf("%s", citizen);
	tab[size].citizenshipnumber = (char*)realloc(tab[size].citizenshipnumber ,strlen(citizen) * sizeof(char));
	strcpy(tab[size].citizenshipnumber, citizen);
	printf("City: ");
	scanf("%s", city);
	tab[size].address = (char*)realloc(tab[size].address ,strlen(city) * sizeof(char));
	strcpy(tab[size].address, city);
	printf("House number: ");
	scanf("%i", &tab[size].housenumber);
	printf("Phone: ");
	scanf("%i", &tab[size].phone);
	printf("Password: ");
	scanf("%s", password);
	tab[size].password = (char*)realloc(tab[size].password ,strlen(password) * sizeof(char));
	strcpy(tab[size].password, password);
	printf("Means: ");
	scanf("%i", &tab[size].means);

}

void viewList(data *tab)
{
	for(size_t i = 0; i < TAB_SIZE; i++)
	{
		if(tab[i].in)
		{
			printf("%s\t%s\t%s\t%s %i\t%i\t%i\n", tab[i].name, tab[i].surename, tab[i].dateofbirth, tab[i].address, tab[i].housenumber,tab[i].phone, tab[i].means);
		}
	}
}

void edit()
{
	char nick[200];
	system("clear");
	printf("Enter your nickname :");
	scanf("%s", nick);


}

int main()
{
	data *tab;

	tab = (data*) malloc(TAB_SIZE * sizeof(data *));

	menu();
	newAcc(tab);
	viewList(tab);

	free(tab);
}	
