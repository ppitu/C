#include "header.h"

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
