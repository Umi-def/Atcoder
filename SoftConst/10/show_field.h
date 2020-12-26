#ifndef SHOW_FIELD_H
#define SHOW_FIELD_H

#include <2darray.h>

#define GRID_EMPTY 0
#define GRID_DOT 1
#define GRID_MYCHAR 2

/*
 show_field
  Dotman（仮）においてフィールドの状態を表示する

  map: 壁の位置を示すマップデータへのポインタ
       グリッドごとに
       上に壁があるとき１，右に壁があるとき２，下に壁があるとき４，左に壁があるとき８
       のＯＲを取った値が入っている
  grids: グリッドの状態を示すデータへのポインタ
         グリッドごとに
         グリッドに何もないとき GRID_EMPTY
         グリッドにドットがあるとき GRID_DOT
         グリッドに自キャラがいるとき GRID_MYCHAR
         という値が入っている

  戻り値: なし
*/
void show_field(_2DArray *map, _2DArray *grids);

#endif
