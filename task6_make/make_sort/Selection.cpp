#include <stdio.h>
#include "main.h"

void Selection(int data[], int lenD)
{
  int j = 0;
  int tmp = 0;
  for(int i=0; i<lenD; i++){
    j = i;
    for(int k = i; k<lenD; k++){
      if(data[j]>data[k]){
        j = k;
      }
    }
    tmp = data[i];
    data[i] = data[j];
    data[j] = tmp;
  }
  printf("Selection end: \n");
  for(int i=0; i<lenD; i++){
    printf("%d ", data[i]);
  }
  printf("\n");
}
