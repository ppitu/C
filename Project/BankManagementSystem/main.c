#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int TAB_SIZE = 2;

struct Data
{
	bool in;
	char name[200];
	char surename[200];
	char dateofbirth[200];
	char address[200];
	char password[200];
	char citizenshipnumber[200];
	int means;
	int phone;
	int housenumber;
} Data_default = {false, " ", " ", " ", " ", " ", " ", 0, 0, 0};

typedef struct Data data;

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
	scanf("%s", tab[size].name);
	printf("Surename: ");
	scanf("%s", tab[size].surename);
	printf("Date of Birth: ");
	scanf("%s", tab[size].dateofbirth);
	printf("Citizen Ship Number: ");
	scanf("%s", tab[size].citizenshipnumber);
	printf("City: ");
	scanf("%s", tab[size].address);
	printf("House number: ");
	scanf("%i", &tab[size].housenumber);
	printf("Phone: ");
	scanf("%i", &tab[size].phone);
	printf("Password: ");
	scanf("%s", tab[size].password);
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

void edit(data *tab)
{
	char nick[200];
	char password[200];
	int cho = 0;
	system("clear");
	printf("Enter your name: ");
	scanf("%s", nick);

	printf("Enter your password: ");
	scanf("%s", password);

	int i;

	for(i = 0; i < TAB_SIZE; i++)
	{
		if(compareString(nick, tab[i].name) == 0)
		{
			if(compareString(password, tab[i].password) == 0)
			{
				cho++;
				break;
			}
		}
	}

	int opt;

	switch(cho)
	{
		case 0:
			system("clear");
			puts("PODANE ZLE DANE!!!");
			break;
		case 1:
			while(cho == 1)
			{
				system("clear");
				puts("SELECT OPTIONS");
				puts("1. Change name");
				puts("2. Change password");
				puts("3. Change date of birth");
				puts("4. Change phone number");
				puts("5. Change address");
				puts("6. Chamge Citizen Ship Nubmer");
				puts("7. EXIT");

				scanf("%i", &opt);
				
				system("clear");

				switch(opt)
				{
					case 1:
						printf("Add new name: ");
						scanf("%s", tab[i].name);
						system("clear");
						puts("The name has benn changed!");
						puts("Press enter to continue...");
						getchar();
						getchar();	
						break;

					case 2:
						printf("Add new password: ");
						scanf("%s", tab[i].password);
						system("clear");
						puts("The password has benn changed!");
						puts("Press enter to continue...");
						getchar();
						getchar();	
						break;
					
					case 3:
						printf("Add new date of birth: ");
						scanf("%s", tab[i].dateofbirth);
						system("clear");
						puts("The date of birth has benn changed!");
						puts("Press enter to continue...");
						getchar();
						getchar();	
						break;
					
					case 4:
						printf("Add new phone number: ");
						scanf("%i", &tab[i].phone);
						system("clear");
						puts("The phone number has benn changed!");
						puts("Press enter to continue...");
						getchar();
						getchar();	
						break;

					case 5:
						printf("Add new address: ");
						scanf("%s", tab[i].address);
						printf("Add new house number: ");
						scanf("%i", &tab[i].housenumber);
						system("clear");
						puts("The address has benn changed!");
						puts("Press enter to continue...");
						getchar();
						getchar();	
						break;
					case 6:
						printf("Add new citizen ship number: ");
						scanf("%s", tab[i].citizenshipnumber);
						system("clear");
						puts("The citizen ship number has benn changed!");
						puts("Press enter to continue...");
						getchar();
						getchar();	
						break;

					case 7:
						cho++;
						break;
					default:
						puts("Wrong options selected");
						break;
				}
			}
			break;
	}
}

void transact(data *tab)
{
	char nick[200];
	char password[200];
	int cho = 0;
	int ops;
	int deposit;
	system("clear");
	printf("Enter your name: ");
	scanf("%s", nick);

	printf("Enter your password: ");
	scanf("%s", password);

	int i;

	for(i = 0; i < TAB_SIZE; i++)
	{
		if(compareString(nick, tab[i].name) == 0)
		{
			if(compareString(password, tab[i].password) == 0)
			{
				cho++;
				break;
			}
		}
	}
	
	switch(cho)
	{
		case 0:
			system("clear");
			puts("Podane zle dane!!!");
			break;
		case 1:
			while(cho == 1)
			{
				system("clear");
				puts("1. Add measures");
				puts("2. Withdraw measures");
				puts("3. EXIT");

				scanf("%i", &ops);

				switch(ops)
				{
					case 1:
						system("clear");
						puts("Enter how much you want to deposit: ");
						scanf("%i", &deposit);
						tab[i].means += deposit;
						puts("Means have been added");
						puts("Press enter to continue...");
						getchar();
						getchar();
						break;
					case 2:
						system("clear");
						puts("Enter how much you want to withdraw");
						scanf("%i", &deposit);
						if(deposit > tab[i].means)
							puts("You don't have enough means");
						else
						{
							tab[i].means -= deposit;
							puts("Means have been withdraw");
						}
						puts("Press enter to continue...");
						getchar();
						getchar();
						break;
					case 3:
						cho++;	
						break;
					default:
						puts("Wrong options selected!");
						break;
				}
			}	
			break;
	}
}

void erase(data *tab)
{
	char nick[200];
	char password[200];
	int ops;
	system("clear");
	printf("Enter your name: ");
	scanf("%s", nick);

	printf("Enter your password: ");
	scanf("%s", password);

	int i;

	for(i = 0; i < TAB_SIZE; i++)
	{
		if(compareString(nick, tab[i].name) == 0)
		{
			if(compareString(password, tab[i].password) == 0)
			{
				break;
			}
		}
	}

	puts("Are you sure you want to delete account?");
	puts("1. YES");
	puts("2. NO");
	scanf("%i", &ops);
	
	switch(ops)
	{
		case 1:
			tab[i].in = false;
			puts("Account has been deleted");
			puts("Press enter to continue...");
			getchar();
			getchar();
			break;
		case 2:
			break;
		default:
			break;
		
	}

}

int main()
{
	data *tab;

	tab = (data*) malloc(TAB_SIZE * sizeof(data *));

	menu();
	newAcc(tab);
	newAcc(tab);
	viewList(tab);
	getchar();
	getchar();
	//edit(tab);
	//transact(tab);
	viewList(tab);
	getchar();
	getchar();
	erase(tab);
	viewList(tab);
	/*for(size_t i = 0; i < TAB_SIZE; i++)
	  {
	  free(tab[i].name);
	  free(tab[i].surename);
	  free(tab[i].dateofbirth);
	  free(tab[i].citizenshipnumber);
	  free(tab[i].address);
	  free(tab[i].password);
	  }*/	

	free(tab);
}	
