#include <stdio.h>

#include <2darray.h>

#define WIDTH 5
#define HEIGHT 5

int main()
{
	int x, y;
	_2DArray *data;

	// make_2DArray()のテスト
	data = make_2DArray(WIDTH, HEIGHT);

	// get_2DArray()のテスト
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			printf("%02d, ", get_2DArray(data, x, y));
		}
		printf("\n");
	}
	printf("\n");

	// set_2DArray()のテスト
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			set_2DArray(data, x, y, x + y * WIDTH);
		}
	}

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			printf("%02d, ", get_2DArray(data, x, y));
		}
		printf("\n");
	}
	printf("\n");
	if(!set_2DArray(data, -WIDTH, -HEIGHT, 99)) {
		printf("ERROR: set_2DArray()\n\n"); 
	}

	// bit_or_2DArray()のテスト
	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			bit_or_2DArray(data, x, y, 2);
		}
	}

	for (y = 0; y < HEIGHT; y++)
	{
		for (x = 0; x < WIDTH; x++)
		{
			printf("%02d, ", get_2DArray(data, x, y));
		}
		printf("\n");
	}
	printf("\n");
	if(!bit_or_2DArray(data, -WIDTH, -HEIGHT, 99)) {
		printf("ERROR: bit_or_2DArray()\n\n"); 
	}

	// delete_2DArray()のテスト
	delete_2DArray(data);

	return 0;
}
