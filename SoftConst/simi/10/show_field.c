#include <stdio.h>
#include "show_field.h"
#include "2darray.h"

#define GRID_EMPTY 0
#define GRID_DOT 1
#define GRID_MYCHAR 2

void show_field(_2DArray *map, _2DArray *grids)
{
	int h, w;
	h = map->height;
	w = map->width;

	_2DArray *field; //2DArray構造体fieldを宣言
	field = make_2DArray(w * 2 + 1, h * 2 + 1);

	char kabe, masu;
	char str[] = " oo+o|++o+-+++++.@";

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{

			kabe = get_2DArray(map, i, j); //壁の情報を取得

			if (kabe & 1) //上に壁があるとき
			{
				bit_or_2DArray(field, i * 2, j * 2, 2);		 // -
				bit_or_2DArray(field, i * 2 + 1, j * 2, 10); //--
				bit_or_2DArray(field, i * 2 + 2, j * 2, 8);	 //-
			}
			if (kabe & 2) //右に壁があるとき
			{
				bit_or_2DArray(field, i * 2 + 2, j * 2, 4);
				bit_or_2DArray(field, i * 2 + 2, j * 2 + 1, 5);
				bit_or_2DArray(field, i * 2 + 2, j * 2 + 2, 1);
			}
			if (kabe & 4) //下に壁があるとき
			{
				bit_or_2DArray(field, i * 2, j * 2 + 2, 2);
				bit_or_2DArray(field, i * 2 + 1, j * 2 + 2, 10);
				bit_or_2DArray(field, i * 2 + 2, j * 2 + 2, 8);
			}
			if (kabe & 8) //左に壁があるとき
			{
				bit_or_2DArray(field, i * 2, j * 2, 4);
				bit_or_2DArray(field, i * 2, j * 2 + 1, 5);
				bit_or_2DArray(field, i * 2, j * 2 + 2, 1);
			}

			masu = get_2DArray(grids, i, j); //中身の情報をもらう

			if (masu == GRID_DOT) //ドット
			{
				bit_or_2DArray(field, i * 2 + 1, j * 2 + 1, 16);
			}
			else if (masu == GRID_MYCHAR) //自機
			{
				bit_or_2DArray(field, i * 2 + 1, j * 2 + 1, 17);
			}
		}
	}
	w = field->width;
	h = field->height;

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			printf("%c", str[get_2DArray(field, x, y)]);
		}
		printf("\n");
	}
}
