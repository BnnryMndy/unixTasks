#include "main.h"
#include <stdio.h>

void fact()
{
	int n=10;
	int res=1;
	for(int i=1; i<=n; i++)
	{
		res=res*i;
	}
	printf("%d\n", res);
}
