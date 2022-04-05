#include <stdio.h>
#include "main.h"

void Bubble(int data[], int lenD)
{
  int tmp = 0;
  for(int i = 0;i<lenD;i++){
    for(int j = (lenD-1);j>=(i+1);j--){
      if(data[j]<data[j-1]){
        tmp = data[j];
        data[j]=data[j-1];
        data[j-1]=tmp;
      }
    }
  }
  printf("Bubble end: \n");
  for(int i=0; i<lenD; i++){
    printf("%d ", data[i]);
  }
  printf("\n");
}