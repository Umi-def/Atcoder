#ifndef PPM_DATA_H
#define PPM_DATA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 PPMData, *lpPPMData:
         PPM画像フォーマット風の画像データ構造体

 *image: 画像データを左上ピクセルから，右下ピクセルに向けてx方向
         優先で並べた一次元配列の先頭アドレスを指すポインタ．
         1ピクセルにRGBのデータが，それぞれ1バイトあるので
         1ピクセル辺り3バイトになる．
 width:  画像データの幅（ピクセル）．
 height: 画像データの高さ（ピクセル）．
 size:   画像データの一次元配列の要素数．
         width * height * 3と同じ．
*/
typedef struct {
  unsigned char *image;
  int width;
  int height;
  size_t size;
} PPMData, *lpPPMData;

/*
 NewPPMData:
         PPMData構造体を作成（メモリを確保）

 width:  作成する画像データの幅（ピクセル）．
 height: 作成する画像データの高さ（ピクセル）．

 戻り値: 作成されたPPMData構造体のアドレス．
         失敗したときはNULL．
*/
lpPPMData NewPPMData(const int width, const int height);

/*
 ReleasePPMData:
         PPMData構造体の解放（メモリを解放）

 data:   解放するPPMData構造体のアドレス．

 戻り値: 成功したときは0．
         失敗したときは-1．
*/
int ReleasePPMData(lpPPMData data);

/*
 CopyPPMData:
         PPMData構造体のコピー（コピー先のメモリを確保）

 data:   コピー元のPPMData構造体のアドレス．

 戻り値: 新たに作成され，コピー元のデータがコピーされた
         PPMData構造体のアドレス．
         失敗したときはNULL．
*/
lpPPMData CopyPPMData(const lpPPMData data);

/*
 LoadPPM:
         PPM画像ファイルの読み込み（読み込み先のメモリを確保）

 filename:
         読み込むPPM画像ファイルのファイル名．

 戻り値: 新たに作成され，画像ファイルのデータが読み込まれた
         PPMData構造体のアドレス．
         失敗したときはNULL．
*/
lpPPMData LoadPPM(const char *filename);

/*
 SavePPM:
         PPM画像ファイルの書き込み

 filename:
         書き込むPPM画像ファイルのファイル名．
 data:   書き込む元データのPPMData構造体のアドレス．

 戻り値: 成功したときは0．
         失敗したときは-1．
*/
int SavePPM(const char *filename, const lpPPMData data);

/*
 RotatePPMData:
         時計回りに90度回転した画像のPPMData構造体を作成（メモリを確保）

 data:   元画像データのPPMData構造体のアドレス．

 戻り値: 新たに作成され，時計回りに90度回転した画像の
         PPMData構造体のアドレス．
         失敗したときはNULL．
*/
lpPPMData RotatePPMData(const lpPPMData data);

/*
 HFlipPPMData:
         水平方向に反転した画像のPPMData構造体を作成（メモリを確保）

 data:   元画像データのPPMData構造体のアドレス．

 戻り値: 新たに作成され，水平方向に反転した画像の
         PPMData構造体のアドレス．
         失敗したときはNULL．
*/
lpPPMData HFlipPPMData(const lpPPMData data);

#endif
