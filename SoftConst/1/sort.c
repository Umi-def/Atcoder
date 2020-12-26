#include "sort.h"

static void Swap(int *, int*);

void Sort(int *data, const size_t size, const int flag)
{
  int i, j;

  for(i = 0; i < size - 1; i++)
    for(j = i + 1; j < size; j++)
      if(flag > 0) {
        if(data[i] > data[j]) Swap((data + i), (data + j));
      } else if(flag < 0) {
        if(data[i] < data[j]) Swap((data + i), (data + j));
      }
}

static void Swap(int *x, int *y)
{
  int tmp;

  tmp = *x;
  *x = *y;
  *y = tmp;
}
