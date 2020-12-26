#ifndef SHOW_FIELD_H
#define SHOW_FIELD_H

#include <stdio.h>
#include "show_field.h"
#include "2darray.h"

#define GRID_EMPTY 0　 // グリッドに何もないとき
#define GRID_DOT 1     //グリッドにドットがあるとき
#define GRID_MYCHAR 2  //グリッドに自キャラがいるとき

void show_field(_2DArray *map, _2DArray *grids)
{
    int w, h;
    w = map->width;
    h = map->height;

    _2DArray *field; //2DArray構造体fieldを宣言
    field = make_2DArray(w * 2 + 1, h * 2 + 1);
    //壁とグリッド両方の情報を入れられるように２倍＋１した構造体を用意

    char wall, grid;
    char str[] = " oo+o|++o+-+++++.@";

    for (int i = 0; i < w; i++)
    {
        for (int j = 0; j < h; j++)
        {

            wall = get_2DArray(map, i, j); //壁の情報を取得

            if (wall & 1) //上に壁があるときは2,10,8
            {
                bit_or_2DArray(field, i * 2, j * 2, 2);      // -
                bit_or_2DArray(field, i * 2 + 1, j * 2, 10); //--
                bit_or_2DArray(field, i * 2 + 2, j * 2, 8);  //-
            }
            if (wall & 2) //右に壁があるときは4,5,1
            {
                bit_or_2DArray(field, i * 2 + 2, j * 2, 4);
                bit_or_2DArray(field, i * 2 + 2, j * 2 + 1, 5);
                bit_or_2DArray(field, i * 2 + 2, j * 2 + 2, 1);
            }
            if (wall & 4) //下に壁があるときは2,10,8
            {
                bit_or_2DArray(field, i * 2, j * 2 + 2, 2);      // -
                bit_or_2DArray(field, i * 2 + 1, j * 2 + 2, 10); //--
                bit_or_2DArray(field, i * 2 + 2, j * 2 + 2, 8);  //-
            }
            if (wall & 8) //左に壁があるときは4,5,1
            {
                bit_or_2DArray(field, i * 2, j * 2, 4);     //  ╷
                bit_or_2DArray(field, i * 2, j * 2 + 1, 5); // 	¦
                bit_or_2DArray(field, i * 2, j * 2 + 2, 1); //  ╵
            }

            grid = get_2DArray(grids, i, j); //グリッドの情報をもらう

            if (grid == 1) //ドットがあるとき
            {
                bit_or_2DArray(field, i * 2 + 1, j * 2 + 1, 16);
            }
            else if (grid == 2) //自キャラがいる時
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
            printf("%c", str[get_2DArray(field, x, y)]);//表示する
        }
        printf("\n");
    }
}

#endif