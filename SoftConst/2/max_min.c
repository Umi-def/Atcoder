#include "max_min.h"
#include "array.h"
#include "sort.h"

int Max(const int *data, const size_t size)
{
  int max, *tmp;

  tmp = ArrayCopy(data, size);
  Sort(tmp, size, -1);
  max = tmp[0];
  free(tmp);

  return max;
}

int Min(const int *data, const size_t size)
{
  int min, *tmp;

  tmp = ArrayCopy(data, size);
  Sort(tmp, size, 1);
  min = tmp[0];
  free(tmp);

  return min;
}
