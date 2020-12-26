#include "mychar.h"

char move_mychar(char a)
{
    static char b = 0;

    switch (a)
    {

    case 9:   //左上の位置（スタート位置）から右に進むようにする
        b = 2;
        break;

    case 3: //右上の位置に来たら１マス下に下げる
        b = 4;
        break;

    case 2:
        if (b == 4)//１マス下に進んだら左に進むようにする
        {
            b = 8;
        }
        else if (b == 2)//右の壁に戻ってきたら下に１マス下に進む
        {
            b = 4;
        }
        break;

    case 8:
        if (b == 8)//左の壁についたら１マス下に下げる
        {
            b = 4;
        }
        else if (b == 4)//１マス下に下げたら右向きに進むようにする
        {
            b = 2;
        }
        break;

    case 12: //左下についたら右に進むようにする
        b = 2;
        break;

    case 6: // 右下についたら左に進むようにする
        b = 8;
        break;

    default:
        break;
    }

    return b;
}
