#include "main.h"
#include <stdio.h>

void fibon()
{
	int first=1;
	int second=1;

	printf("%d ", first);
	printf("%d ", second);

	for(int i=0; i<8; i++)
	{
		if(i%2 == 0)
		{
			first=first+second;
			printf("%d ", first);
		}
		else
		{
			second=first+second;
			printf("%d ", second);
		}
	}
	printf("\n");
}

