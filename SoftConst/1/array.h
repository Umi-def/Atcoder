#ifndef ARRAY_H   //ARRAY_Hが定義されていなければ以下を実行（２重読み込み回避）
#include <stdlib.h> //標準ヘッダファイルの読み込み
#include <stdio.h>
#define ARRAY_H  //ARRAY_Hを定義する
int *ArrayCopy(const int *data, const size_t size);//関数のプロトタイプ宣言
void ArrayOutput(const int *data, const size_t size);
#endif
