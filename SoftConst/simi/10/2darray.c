#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "2darray.h"

_2DArray *make_2DArray(int width, int height)
{
	_2DArray *data;

	data = (_2DArray *)malloc(sizeof(_2DArray)); //構造体_2DArray自身を確保する
	if (data == NULL)
	{
		perror("メモリの確保に失敗しました。\n");
		exit(-1);
	}

	data->width = width;
	data->height = height;

	data->array = (char *)malloc(width * height * sizeof(char)); //構造体_2DArrayのメンバーarrayに必要な大きさの配列を確保する

	for (int i = 0; i < (width * height); i++) //0埋め
	{
		data->array[i] = 0;
	}
	if (data->array == NULL)
	{
		perror("メモリの確保に失敗しました。\n");
		exit(-1);
	}
	return data;
}

void delete_2DArray(_2DArray *data)
{
	free(data->array); //構造体_2DArrayのメンバーarrayを解放してから
	free(data);		   //構造体_2DArray自身を解放する
}

int set_2DArray(_2DArray *data, int x, int y, char value)
{

	if ((x >= 0) && (x <= data->width) && (y >= 0) && (y <= data->height)) //(x, y)が範囲内なら
	{
		data->array[x + (data->width) * y] = value; //arrayの[x + (data->width) * y]番目にvalueを代入
		return 1;
	}
	else
	{
		return 0; //範囲内じゃないならreturn 0(エラー)
	}
}

int bit_or_2DArray(_2DArray *data, int x, int y, char value)
{

	if ((x >= 0) && (x <= data->width) && (y >= 0) && (y <= data->height)) //(x, y)が範囲内なら
	{
		data->array[x + (data->width) * y] = (data->array[x + (data->width * y)]) | value; //(x, y)座標の値とvalueをbitOR演算する
		return 1;
	}
	else
	{
		return 0; //範囲内じゃないならreturn 0(エラー)
	}
}

char get_2DArray(_2DArray *data, int x, int y)
{
	return data->array[x + (data->width * y)]; //座標(x, y)の値を返す
}
