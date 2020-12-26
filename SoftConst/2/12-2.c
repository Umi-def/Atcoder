#include <stdio.h>

#include "max_min.h"
#include "array.h"
#include "sort.h"

int main()
{
  int i;
  size_t size;
  int data[] = { 59, 1, 55, 85, 85, 90, 5, 76, 35, 74 };

  size = sizeof(data)/sizeof(data[0]);

  printf("そのまま .. ");
  ArrayOutput(data, size);

  printf("最大 .. %d\n", Max(data, size));
  printf("最小 .. %d\n", Min(data, size));

  Sort(data, size, 1);
  printf("ソート（昇順） .. ");
  ArrayOutput(data, size);

  Sort(data, size, -1);
  printf("ソート（降順） .. ");
  ArrayOutput(data, size);

  return 0;
}
