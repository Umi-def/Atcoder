#include "ppm_data.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    lpPPMData data, data_r;

    // コマンドライン引数は２つ必要なのでチェック
    // １つ目の引数の画像ファイルをロード
    // ２つ目の引数の画像ファイルに回転後の画像をセーブ
    if (argc < 3)
    {
        fprintf(stderr, "引数が足りません．\n");
        return 1;
    }

    // 画像をロード
    if ((data = LoadPPM(argv[1])) == NULL)
    {
        return 1;
    }

    // 画像を回転
    if ((data_r = HFlipPPMData(data)) == NULL)
    {
        //水平方向に反転した画像のPPMData構造体を作成
        return 1;
    }

    // 画像をセーブ
    if (SavePPM(argv[2], data_r) < 0)
    {
        return 1;
    }

    // 使用した構造体を解放
    if (ReleasePPMData(data) < 0)
    {
        return 1;
    }
    if (ReleasePPMData(data_r) < 0)
    {
        return 1;
    }

    return 0;
}
