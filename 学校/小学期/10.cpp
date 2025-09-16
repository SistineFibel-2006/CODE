#include <stdio.h>
#include <stdlib.h>
int main () {
  int * array;
  int length = 5;

  array = (int *)malloc(length * sizeof(int ));

  for(int i = 0; i < 5; i ++)
    scanf("%d", array + i);

  for(int i = 0; i < 5; i ++)
    printf("%d ", array[i]);

  free(array);
  return 0;
}
