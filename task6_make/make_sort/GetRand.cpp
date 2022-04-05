#include <stdlib.h>
#include "main.h"

int GetRand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}