#include "mychar.h"

char move_mychar(char a)
{
    static char b = 0; //前回の動きを覚えていたい
    static char c = 0; //スタート地点を覚えたい
    static int i = 0;  //i=0なら初回設定する

    if (i == 0)
    {
        c = a;
        i++;
    }

    switch (a)
    {

    case 9:
        if (b == 0 || b == 1)
        {
            b = 2;
        }
        else if (b == 8)
        {
            b = 4;
        }
        break;

    case 3:
        if (b == 0 || b == 1)
        {
            b = 8;
        }
        else if (b == 2)
        {
            b = 4;
        }
        break;

    case 2:
        if (b == 4 || b == 1)
        {
            b = 8;
        }
        else if (b == 2)
        {
            if (c == 9 || c == 3)
            {
                b = 4;
            }
            else if (c == 12 || c == 6)
            {
                b = 1;
            }
        }
        break;

    case 8:
        if (b == 4 || b == 1)
        {
            b = 2;
        }
        else if (b == 8)
        {
            if (c == 9 || c == 3)
            {
                b = 4;
            }
            else if (c == 12 || c == 6)
            {
                b = 1;
            }
        }
        break;

    case 10:
    case 11:
    case 14:
        if (c == 11)
            b = 4;
        if (c == 14)
            b = 1;
        break;

    case 12:
        if (b == 0 || b == 4)
        {
            b = 2;
        }
        else if (b == 8)
        {
            b = 1;
        }
        break;

    case 6:
        if (b == 0 || b == 4)
        {
            b = 8;
        }
        else if (b == 2)
        {
            b = 1;
        }
        break;

    case 5:
    case 7:
    case 13:
        if (c == 13)
            b = 2;
        if (c == 7)
            b = 8;
        break;

    default:
        break;
    }

    return b;
}

char move_mychar_maze(char a)
{
    static char b = 0; //前回の動きを覚えていたい

    switch (a)
    {

    //3面壁:来た方向に戻る
    case 14:
    case 13:
    case 11:
    case 7:
        b = 15 - a;
        break;

    //2面壁:来た方向と別の方向に抜ける
    case 5: //そのまままっすぐ
    case 10:
        break;

    case 9:
        if (b == 1)
        {
            b = 2;
        }
        else
        {
            b = 4;
        }
        break;

    case 3:
        if (b == 2)
        {
            b = 4;
        }
        else
        {
            b = 8;
        }
        break;

    case 12:
        if (b == 8)
        {
            b = 1;
        }
        else
        {
            b = 2;
        }
        break;

    case 6:
        if (b == 4)
        {
            b = 8;
        }
        else
        {
            b = 1;
        }
        break;

    //1面壁:進行方向右側に壁がないならば右折
    case 1:
    case 2:
    case 4:
    case 8:
        if (b * 2 % 15 != a)
        {
            b *= 2;
            b %= 15;
        }

        break;

    //0面壁:とりあえず右折してみる
    default:
        b *= 2;
        b %= 15;

        break;
    }

    return b;
}