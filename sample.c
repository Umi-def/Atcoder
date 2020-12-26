#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data
{ //構造体の宣言
    char name[32];
    int num;
    double gas;
    struct Data *nextdata;
} MyDataType, *lpMyDataType;

void add_data(lpMyDataType *, const char *, int, double); //プロトタイプ宣言

int main()
{
    lpMyDataType start_data = NULL, lpdata;

    add_data(&start_data, "car0", 1234, 25.5); //データの追加
    add_data(&start_data, "car1", 4567, 52.2);
    add_data(&start_data, "car2", 7890, 20.5);

    for (lpdata = start_data; lpdata; lpdata = lpdata->nextdata)
    {                                                                 //lpdataがnullじゃない限り繰り返す
        printf("%s %d %f\n", lpdata->name, lpdata->num, lpdata->gas); //データ表示
    }

    return 0;
}

void add_data(lpMyDataType *lpstart_data, const char *str, int num, double gas)
{
    lpMyDataType add_data, lpdata;

    if ((add_data = malloc(sizeof(MyDataType))) == NULL)
    {
        perror("メモリの確保に失敗しました");
        exit(-1);
    }
    strcpy(add_data->name, str);
    add_data->num = num;
    add_data->gas = gas;
    add_data->nextdata = NULL;

    if (*lpstart_data)
    {
        for (lpdata = *lpstart_data; lpdata->nextdata; lpdata = lpdata->nextdata)
            ;
        lpdata->nextdata = add_data; //*lpstart_dataがNULLじゃなかったらlpdata->nextdataをadd_dataにする
    }
    else
    {
        *lpstart_data = add_data; //*lpstart_dataがNULLだったら最初のデータをadd_dataにする
    }

    return;
}