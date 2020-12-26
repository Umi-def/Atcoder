#include <stdio.h>

typedef struct //構造体の初期化
{
    char name[32];
    int num;
    double gas;

} Car, *next; //型の付け替え

Car data[] = {
    {"car0", 1234, 25.5},
    {"car1", 4567, 52.2},
    {"car2", 7890, 20.5},
};

//構造体の配列を引数の持つ自作関数のプロトタイプ宣言
void printlist(Car data[]);

int main(void) //関数の呼び出し
{

    printlist(data);

    return 0;
};

void printlist(Car *first)
{
    for (int i = 0; i < 3; i++)
    {
        printf("車のナンバーは%d：ガス量は%fです。\n",
               (first + i)->num, (first + i)->gas);
        /*アロー演算子を使わない場合p[i].nameにすることで構造体のメンバにアクセスすることができる*/
    }
    return;
};
/*アロー演算子を使わないコード
void sort(Samurai *p)
{                               //構造体の配列を引数に持つ自作関数
    for (int i = 0; i < 5; i++) //身長の低い順に並ぶよう比較していく
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (p[i].height > p[j].height) //ポインタp+iのメンバheightのアドレスにアロー演算子を使ってアクセスし値を比較
            {//ポインタだけではメンバ変数の値を見ることができないのでアロー演算子を使ってポインタ構造体を参照する
                Samurai keep = *(p + i); //小さい順に並べるいつものソート
                *(p + i) = *(p + j);
                *(p + j) = keep;
            }
        }
    }
    return;
}

void output(Samurai *p)
{
    for (int i = 0; i < 5; i++)
    {
        printf("氏名：%s\n年齢：%d\n身長：%d\n体重：%d\n\n",
               p[i].name, p[i].age,
               p[i].height, p[i].weight);

    }
    return;
};*/
