#include <stdio.h>
#include "main.h"

int main()
{
	const int lenD = 110;
	int fulldata[lenD];
	int data[lenD];
	int num;
	for (int i = 0; i<lenD; i++)
	{
		fulldata[i] = i;
	}
	for (int i = 0; i<lenD; i++)
	{
		num = GetRand(0, lenD-i-1);
		data[i] = fulldata[num];
		for (int j = num; j < lenD-i-1; j++)
		{
			fulldata[j] = fulldata[j+1];
		}
	}
	printf("Massive: \n");
	for(int i=0; i<lenD; i++){
	  printf("%d ", data[i]);
	}
	printf("\n");
	Selection(data, lenD);
	Bubble(data, lenD);
	Insertion(data, lenD);
}
