#include <stdio.h>
#include <stdlib.h>

struct emp
{
	char name[20];
	int age;	
};


int main()
{
	struct emp e;
	FILE *p, *q;

	p = fopen("one.txt", "a");
	
	q = fopen("one.txt", "r");
	
	printf("Enter Name and Age: ");
	scanf("%s %d", e.name, &e.age);
	fprintf(p, "%s %d\n", e.name, e.age);
	fclose(p);

	do
	{
		fscanf(q, "%s %d", e.name, &e.age);
		printf("%s %d\n", e.name, e.age);
	}
	while(!feof(q));

	return 0;
}
