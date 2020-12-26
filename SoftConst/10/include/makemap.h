#ifndef MAKEMAP_H
#define MAKEMAP_H

#include <2darray.h>

/*
 壁の位置を示すマップデータを作成するモジュール

 壁の位置を示すマップデータは
 グリッドごとに
 上に壁があるとき１，右に壁があるとき２，下に壁があるとき４，左に壁があるとき８
 のＯＲを取った値が入っている
*/

/*
 make_simple_map
  周囲の壁しかない単純なマップデータを作成する

  width: 作成するマップデータの幅
  height: 作成するマップデータの高さ

  戻り値: 作成した_2DArray型のマップデータへのポインタ
*/
_2DArray *make_simple_map(int width, int height);

/*
 make_oneway_map
  スタート地点から常に一方向に進むルートしかない，
  一方通行なマップデータを作成する

  width: 作成するマップデータの幅
  height: 作成するマップデータの高さ
  start_x: キャラクタのスタート地点のx座標
  start_y: キャラクタのスタート地点のy座標

  注: ただし，スタート地点は４つの角のどこかに限定する

  戻り値: 作成した_2DArray型のマップデータへのポインタ
*/
_2DArray *make_oneway_map(int width, int height, int start_x, int start_y);

/*
 make_maze_map
  迷路になったマップデータを作成する

  width: 作成するマップデータの幅
  height: 作成するマップデータの高さ

  戻り値: 作成した_2DArray型のマップデータへのポインタ
*/
_2DArray *make_maze_map(int width, int height);

#endif
