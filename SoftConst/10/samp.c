#include <stdio.h>
#include <stdlib.h>
#include "2darray.h"

_2DArray *make_simple_map(int width, int height)
{
    _2DArray *field; //2DArray構造体fieldを宣言
    field = make_2DArray(width, height);
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int value = 0;
            if (x == 0)
                value = 8;
            if (x == width - 1)
                value = 2;
            if (y == 0)
                value = 1;
            if (y == height - 1)
                value = 4;

            if (x == 0 && y == 0)
                value = 9;
            if (x == width - 1 && y == 0)
                value = 3;
            if (x == 0 && y == height - 1)
                value = 12;
            if (x == width - 1 && y == height - 1)
                value = 6;
            set_2DArray(field, x, y, value);
        }
    }
    return (field);
}

_2DArray *make_oneway_map(int width, int height, int start_x, int start_y)
{
    _2DArray *field; //2DArray構造体fieldを宣言
    field = make_2DArray(width, height);
    int maki = rand() % 2 + 1;                           //1のとき時計回り、2のとき反時計回り
    int dir = 0;                                         //移動方向
    int wl = 0, wr = width - 1, hu = 0, hd = height - 1; //左右上下の処理範囲
    int xt = 0, yt = 0;                                  //座標一時保存用変数

    if (start_x == 0 && start_y == 0)
    {
        xt = 0;
        yt = 0;
        dir = 2;
        dir *= maki;
    }
    if (start_x == width - 1 && start_y == 0)
    {
        xt = width - 1;
        yt = 0;
        dir = 4;
        dir *= maki;
    }
    if (start_x == width - 1 && start_y == height - 1)
    {
        xt = width - 1;
        yt = height - 1;
        dir = 8;
        dir *= maki;
        dir %= 15;
    }
    if (start_x == 0 && start_y == height - 1)
    {
        xt = 0;
        yt = height - 1;
        dir = 1;
        dir *= maki;
    }

    while (wr - wl > 0 || hd - hu > 0)
    {
        if (dir == 2)
        {
            for (int x = wl; x < wr; x++)
            {
                set_2DArray(field, x, yt, 5);
            }
            xt = wr;
            if (maki == 1)
            {
                set_2DArray(field, wr, yt, 3);
                hu++;
                dir = 4;
            }

            if (maki == 2)
            {
                set_2DArray(field, wr, yt, 6);
                hd--;
                dir = 1;
            }
        }
        if (dir == 8)
        {
            for (int x = wr; x > wl; x--)
            {
                set_2DArray(field, x, yt, 5);
            }
            xt = wl;
            if (maki == 1)
            {
                set_2DArray(field, wl, yt, 12);
                hd--;
                dir = 1;
            }

            if (maki == 2)
            {
                set_2DArray(field, wl, yt, 9);
                hu++;
                dir = 4;
            }
        }
        if (dir == 1)
        {
            for (int y = hd; y > hu; y--)
            {
                set_2DArray(field, xt, y, 10);
            }
            yt = hu;
            if (maki == 1)
            {
                set_2DArray(field, xt, hu, 9);
                wl++;
                dir = 2;
            }

            if (maki == 2)
            {
                set_2DArray(field, xt, hu, 3);
                wr--;
                dir = 8;
            }
        }
        if (dir == 4)
        {
            for (int y = hu; y < hd; y++)
            {
                set_2DArray(field, xt, y, 10);
            }
            yt = hd;
            if (maki == 1)
            {
                set_2DArray(field, xt, hd, 6);
                wr--;
                dir = 8;
            }

            if (maki == 2)
            {
                set_2DArray(field, xt, hd, 12);
                wl++;
                dir = 2;
            }
        }
    }

    if (start_x == 0 && start_y == 0)
    {
        if (maki == 1)
        {
            set_2DArray(field, 0, 0, 13);
        }
        if (maki == 2)
        {
            set_2DArray(field, 0, 0, 11);
        }
    }
    if (start_x == width - 1 && start_y == 0)
    {
        if (maki == 1)
        {
            set_2DArray(field, width - 1, 0, 11);
        }
        if (maki == 2)
        {
            set_2DArray(field, width - 1, 0, 7);
        }
    }
    if (start_x == width - 1 && start_y == height - 1)
    {
        if (maki == 1)
        {
            set_2DArray(field, width - 1, height - 1, 7);
        }
        if (maki == 2)
        {
            set_2DArray(field, width - 1, height - 1, 14);
        }
    }
    if (start_x == 0 && start_y == height - 1)
    {
        if (maki == 1)
        {
            set_2DArray(field, 0, height - 1, 14);
        }
        if (maki == 2)
        {
            set_2DArray(field, 0, height - 1, 13);
        }
    }

    return (field);
}

_2DArray *make_maze_map(int width, int height)
{
    _2DArray *field; //2DArray構造体fieldを宣言
    field = make_2DArray(width, height);
    //まずはsimplemapと同じように外枠形成
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int value = 0;
            if (x == 0)
                value = 8;
            if (x == width - 1)
                value = 2;
            if (y == 0)
                value = 1;
            if (y == height - 1)
                value = 4;

            if (x == 0 && y == 0)
                value = 9;
            if (x == width - 1 && y == 0)
                value = 3;
            if (x == 0 && y == height - 1)
                value = 12;
            if (x == width - 1 && y == height - 1)
                value = 6;
            set_2DArray(field, x, y, value);
        }
    }

    for (int y = 0; y < height - 1; y++)
    {
        for (int x = 0; x < width - 1; x++)
        {
            int value = 0;
            int tdir = 0;
            if (y == 0)
            {
                tdir = rand() % 4 + 1; //tdir : taosu dir 1~4
            }
            else
            {
                tdir = rand() % 3 + 2; //2~4
            }

            if (tdir == 4 && get_2DArray(field, x, y) & 4 && get_2DArray(field, x, y + 1) & 1) //重ならないように
            {
                tdir = rand() % 2 + 2; //2~3
            }

            switch (tdir)
            {
            case 1:
                bit_or_2DArray(field, x, y, 2);
                bit_or_2DArray(field, x + 1, y, 8);
                break;
            case 2:
                bit_or_2DArray(field, x + 1, y, 4);
                bit_or_2DArray(field, x + 1, y + 1, 1);
                break;
            case 3:
                bit_or_2DArray(field, x, y + 1, 2);
                bit_or_2DArray(field, x + 1, y + 1, 8);
                break;
            case 4:
                bit_or_2DArray(field, x, y, 4);
                bit_or_2DArray(field, x, y + 1, 1);
                break;
            default:
                break;
            }
        }
    }
    return (field);
}