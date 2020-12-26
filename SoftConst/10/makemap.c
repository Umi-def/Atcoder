#include <stdio.h>
#include <stdlib.h>
#include "2darray.h"
#include "makemap.h"
#define rep(i, n) for (int i = 0; i < (n); ++i)

//周囲の壁のみを作成,壁の位置を示すマップデータを作成したい
_2DArray *make_simple_map(int width, int height)
{
    _2DArray *field; //2DArray構造体fieldを宣言
    field = make_2DArray(width, height);
    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            int m = 0;
            if (w == 0)
            {
                m = 8;

                if (h == 0)
                {
                    m = 9;
                }
                if (h == height - 1)
                {
                    m = 12;
                }
            }
            else if (w == width - 1)
            {
                if (h == 0)
                {
                    m = 3;
                }
                else if (h == height - 1)
                {
                    m = 6;
                }
                else
                {
                    m = 2;
                }
            }
            else if (h == 0)
            {
                m = 1;
            }
            else if (h == height - 1)
            {
                m = 4;
            }

            set_2DArray(field, w, h, m); //make_2DArrayで作成した２次元配列を実現する構造体
        }
    }
    return (field);
}

_2DArray *make_oneway_map(int width, int height, int start_x, int start_y)
{

    _2DArray *field; //2DArray構造体fieldを宣言
    //field = make_simple_map; //周りの枠線は先に書いておく
    field = make_2DArray(width, height);
    
    int rl = rand() % 2 + 1; //右１,左２ 移動方向をスタート位置で回転させたい
    int b = 0;               //進む向き
    int px = 0, py = 0;      //今の位置
    int go = width - 1;      // gx8 = width - 2; //どんだけ進みたいか（前の渦より１小さい）,始めは外枠より１個手前まで
    //int gy = height - 2;     // gy4 = height - 2;
    //int num = 0;             //巻き数をカウントする(4で割った数が巻き数)
    int flag = 1; //bの値が縦横セットで進む距離を１減らすための縦横セットの数
    if (start_x == 0 && start_y == 0)
    { //左上スタートなので今の位置は(0,0)
        px = 0;
        py = 0;
        b = rl * 2; //右なら２左なら４
        bit_or_2DArray(field, px, py, 9);
    }
    else if (start_x == width - 1 && start_y == 0)
    { //右上スタート今の位置(w-1,0)
        px = width - 1;
        py = 0;
        b = rl * 4; //右なら４左なら８
        bit_or_2DArray(field, px, py, 3);
    }
    else if (start_x == width - 1 && start_y == height - 1)
    { //右下スタート今の位置(w-1,h-1)
        px = width - 1;
        py = height - 1;
        b = (rl * 8) % 15; //右なら８左なら１
        bit_or_2DArray(field, px, py, 6);
    }
    else if (start_x == 0 && start_y == height - 1)
    { //左下スタート今の位置(0,h-1)
        px = 0;
        py = height - 1;
        b = rl * 1; //右なら１左なら２
        bit_or_2DArray(field, px, py, 12);
    }
    while (go > 0)
    {

        if (b == 2)
        {
            if (flag % 2 == 0) //縦横セットで1マス進む量を減らす
            {
                go--;
            }

            rep(i, go)
            {
                int x = px + i;
                if (rl == 1)
                {
                    //右巻きで右に進んでいるときは下線を書く
                    bit_or_2DArray(field, x, py, 5);
                }
                else
                {
                    //左巻きで右に進んでいるときは上線を書く

                    bit_or_2DArray(field, x, py, 5);
                }
            }

            flag++;
            //曲がり角の時何も書かなくていいので１マス進める
            px += go;
            if (rl == 1)
            {
                py++;
            }
            else
            {
                py--;
            }

            //num++;
            if (rl == 1)
            {
                b = (b * 2) % 15;
                bit_or_2DArray(field, px, py - 1, 3);
            }
            else
            {
                b = b / 2;
                if (b == 0)
                {
                    b = 8;
                }
                if (go != 0)
                {
                    bit_or_2DArray(field, px, py + 1, 6);
                }
            }
        }
        if (b == 4&&go!=0)
        {
            if (flag % 2 == 0) //縦横セットで1マス進む量を減らす
            {
                go--;
            }
            rep(i, go)
            {
                int y = py + i;
                if (rl == 1)
                {
                    //右巻きで下に進んでいるときは横線を書く
                    bit_or_2DArray(field, px, y, 10);
                }
                else
                {
                    //左巻きで下に進んでいるときは右線を書く
                    bit_or_2DArray(field, px, y, 10);
                }
            }

            flag++;

            //曲がり角の時何も書かなくていいので１マス進める

            py += go;
            if (rl == 1)
            {
                px--;
            }
            else
            {
                px++;
            }
            if (rl == 1)
            {
                b = (b * 2) % 15;
                bit_or_2DArray(field, px + 1, py, 6);
            }
            else
            {
                b = b / 2;
                if (b == 0)
                {
                    b = 8;
                }
                bit_or_2DArray(field, px - 1, py, 12);
            }
        }
        if (b == 8)
        {
            if (flag % 2 == 0) //縦横セットで1マス進む量を減らす
            {
                go--;
            }
            rep(i, go) //go回繰り返したい
            {
                int x = px - i;
                if (rl == 1)
                {
                    //右巻きで左に進んでいるときは上線を書く
                    bit_or_2DArray(field, x, py, 5);
                }
                else
                {
                    //左巻きで左に進んでいるときはした線を描く
                    bit_or_2DArray(field, x, py, 5);
                }
            }

            flag++;
            //曲がり角の時何も書かなくていいので１マス進める
            px -= go;
            if (rl == 1)
            {
                py--;
            }
            else
            {
                py++;
            }

            //num++;
            if (rl == 1)
            {
                b = (b * 2) % 15;
                bit_or_2DArray(field, px, py + 1, 12);
            }
            else
            {
                b = b / 2;
                if (b == 0)
                {
                    b = 8;
                }
                bit_or_2DArray(field, px, py - 1, 9);
            }
        }
        if (b == 1)
        {
            if (flag % 2 == 0) //縦横セットで1マス進む量を減らす
            {
                go--;
            }
            rep(i, go) //go回繰り返したい
            {
                int y = py - i;
                if (rl == 1)
                {
                    //右巻きで上に進んでいるときは右線を書く
                    bit_or_2DArray(field, px, y, 10);
                }
                else
                {
                    //左巻きで上に進んでいるときは左線を書く
                    bit_or_2DArray(field, px, y, 10);
                }
            }
            flag++;
            //曲がり角の時何も書かなくていいので１マス進める
            py -= go;
            if (rl == 1)
            {
                px++;
            }
            else
            {
                px--;
            }
            if (rl == 1)
            {
                b = (b * 2) % 15;
                bit_or_2DArray(field, px - 1, py, 9);
            }
            else
            {
                b = b / 2;
                if (b == 0)
                {
                    b = 8;
                }
                bit_or_2DArray(field, px + 1, py, 3);
            }
        }
    }
    return (field);
}
_2DArray *make_maze_map(int width, int height)
{
    return (NULL);
}
