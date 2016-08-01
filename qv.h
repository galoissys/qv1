/*********************************************************/
/*  qv.h                                                 */
/*                                                       */
/*  強化学習プログラム                                   */
/*  Q学習                                                */
/*                                                       */
/*********************************************************/
#ifndef _QV_H_
#define _QV_H_

#include <stdio.h>
#include <stdlib.h>
#include "rnd.h"

// selecta()関数で使用
#define EPSILON 0.3      /* 行動選択のランダム性を決定   */

// updataq()関数で使用
#define ALPHA 0.1        /* 学習係数     */
#define GAMMA 0.9        /* 割引率     */

/*  Q-Value データ構造               */
#define NODENO 15        /* Q値のノード数    */

typedef struct{
	int qvalue[NODENO];  /* Q値     */
} Qvalue;

/*  Q学習 関数                       */
int selecta(int olds, Qvalue *qv);   // 行動を選択する
int updateq(int state, Qvalue *qv);  // Q値を更新する

void initqvalue(Qvalue *qv);        // Q値を初期化する
void printqvalue(Qvalue *qv);        // Q値を出力する


#endif

