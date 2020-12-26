#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "2darray.h"

_2DArray *make_2DArray(int width, int height)
{
    //_2DArrayの型の構造体dataを作成
    _2DArray *data;
    //構造体_2DArray自身のメモリを確保する
    data = (_2DArray *)malloc(sizeof(_2DArray));
    if (data == NULL)
    {
        perror("メモリの確保に失敗しました\n");
        exit(-1);
    }
    data->width = width;   //構造体のwidthに仮引数のwidthを入れる
    data->height = height; //構造体のheightに仮引数のheightを入れる
    data->array = (char *)malloc(width * height * sizeof(char));
    //要素数のchar型文のメモリを確保する
    for (int i = 0; i < width * height;i++)
    {
        data->array[i] = 0;
    }
        if (data->array == NULL)
        {
            perror("メモリの確保に失敗しました\n");
            exit(-1);
        }
    return data;
}
void delete_2DArray(_2DArray *data)
{
    free(data->array); //構造体_2DArrayのメンバーarrayを開放する
    free(data);        //構造体_2DArray自身を開放する
}
int set_2DArray(_2DArray *data, int x, int y, char value)
{
    
    if ((x >= 0) && (x <= data->width) && (y >= 0) && (y <= data->height)) 
    {
        data->array[x + (data->width) * y] = value; 
        return 1;
        //(x, y)が範囲内ならarrayの[x + (data->width) * y]番目にvalueを格納する
    }
    else
    {
        return 0; //範囲内じゃないならreturn 0(エラー)
    }
}
int bit_or_2DArray(_2DArray*data,int x,int y ,char value)
{
    if ((x >= 0) && (x <= data->width) && (y >= 0) && (y <= data->height))
    {
        data->array[x + (data->width) * y] = (data->array[x + (data->width * y)] | value);
        return 1;
        //(x, y)が範囲内なら(x, y)座標の値とvalueをbitOR演算する これを呼び出すだけでOR演算ができるようになる
    }
    else
    {
        return 0; //範囲内じゃないならreturn 0(エラー)
    }
}
char get_2DArray(_2DArray *data, int x, int y)
{
    return data->array[x + (data->width * y)];
    //座標(x, y)の値を返す
}