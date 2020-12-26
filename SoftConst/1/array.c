#include "array.h"

int *ArrayCopy(const int *data, const size_t size)
{
  int i, *tmp;

  tmp = malloc(sizeof(int) * size);

  for(i = 0; i < size; i++)
    tmp[i] = data[i];

  return tmp;
}

void ArrayOutput(const int *data, const size_t size)
{
  int i;

  for(i = 0; i < size; i++) {
    printf("%d", data[i]);
    if(i != size - 1) printf(", ");
  }
  printf("\n");
}
 
