#ifndef _2DARRAY_H
#define _2DARRAY_H

/*
 _2DArray
  ２次元配列を実現する構造体

  array: 配列のデータそのものを格納する領域
         今回は１次元配列を使用する
  width: 配列の幅
  height: 配列の高さ
*/
typedef struct {
  char *array;
  int width;
  int height;
} _2DArray;

/*
 make_2DArray
  ２次元配列を実現する構造体_2DArrayをメモリ上に確保し作成する
  構造体内の配列arrayは0で初期化する

  width: 作成する２次元配列の幅
  height: 作成する２次元配列の高さ

  戻り値: 作成した_2DArrayへのポインタ
*/
_2DArray *make_2DArray(int width, int height);

/*
 delete_2DArray
  make_2DArrayで作成した２次元配列を実現する構造体_2DArrayを
  メモリ上から削除する

  data: make_2DArrayで作成した２次元配列を実現する構造体

  戻り値: なし
*/
void delete_2DArray(_2DArray *data);

/*
 set_2DArray
  make_2DArrayで作成した２次元配列を実現する構造体_2DArrayの
  (x, y)座標に値valueを格納する

  x: 値を格納するx座標
  y: 値を格納するy座標
  value: 配列に格納する値

  戻り値: 与えられたxとyが，２次元配列の幅と高さの
          範囲内なら１を，範囲外なら０を返す
*/
int set_2DArray(_2DArray *data, int x, int y, char value);

/*
 bit_or_2DArray
  make_2DArrayで作成した２次元配列を実現する構造体_2DArrayの
  (x, y)座標の値に，値valueをビットOR演算した結果を
  (x, y)座標に格納する．

  x: 値を演算・格納するx座標
  y: 値を演算・格納するy座標
  value: 配列にビットOR演算する値

  戻り値: 与えられたxとyが，２次元配列の幅と高さの
          範囲内なら１を，範囲外なら０を返す
*/
int bit_or_2DArray(_2DArray *data, int x, int y, char value);

/*
 get_2DArray
  make_2DArrayで作成した２次元配列を実現する構造体_2DArrayの
  (x, y)座標の値を取得する．

  x: 値を取得するx座標
  y: 値を取得するy座標

  戻り値: ２次元配列の(x, y)座標の値を返す
*/
char get_2DArray(_2DArray *data, int x, int y);

#endif
