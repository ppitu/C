#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>

extern int TAB_SIZE;

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
};

typedef struct Data data;

int compareString(char *, char*);
void menu();
void newAcc(data*);
void edit(data*, int);
void transact(data*i, int);
void viewList(data*);
void erase(data*);
int login(data*);
void accountDetails(data*, int);

#endif //HEADER_H
