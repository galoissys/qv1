/*********************************************************/
/*  qv.c                                                 */
/*                                                       */
/*  強化学習プログラム                                   */
/*  Q学習                                                */
/*                                                       */
/*********************************************************/
#include "qv.h"

/*********************************************************/
/*  Q学習 関数                                           */
/*********************************************************/

/*********************************************************/
/* selecta() : 行動を選択する                            */
/*********************************************************/
int selecta(int olds, Qvalue *qv){
	
	int s;
	
	srand((unsigned)time(NULL));    /* time関数を用いた乱数初期化の定番式 */
	
	/* ε-greedy法による行動選択  */
	if(rand1() < EPSILON){
		/*  ランダムに行動  */
		if(rand01() == 0){
			s = 2 * olds + 1;
		}else{
			s = 2 * olds + 2;
		}
	}else{
		/*  Q値が最大となる行動を選択  */
		if( (qv->qvalue[2 * olds + 1]) > (qv->qvalue[2 * olds + 2]) ){
			s = 2 * olds + 1;
		}else{
			s = 2 * olds + 2;
		}
	}
	
	return s;
}

/*********************************************************/
/* updateq() : Q値を更新する                             */
/*********************************************************/
int updateq(int s, Qvalue *qv){
	
	int qval;
	int qmax;
	
	/* 最下段の場合  */
	if(s > 6){
		if(s == 14){
			/*  報酬の付与   */
			qval = qv->qvalue[s] + ALPHA * (1000 - qv->qvalue[s]);
		}
		/*  報酬を与えるノードを増やす Start */
		else if(s == 11){
			qval = qv->qvalue[s] + ALPHA * (500 - qv->qvalue[s]);
		}
		/*  報酬を与えるノードを増やす End */
		else{
			/*  報酬なし  */
			qval = qv->qvalue[s];
		}
	}
	/*  最下段以外の場合   */
	else{
		if( (qv->qvalue[2 * s + 1]) > (qv->qvalue[2 * s + 2]) ){
			qmax = qv->qvalue[2 * s + 1];
		}
		else{
			qmax = qv->qvalue[2 * s + 2];
		}
		qval = qv->qvalue[s] + ALPHA * (GAMMA * qmax - qv->qvalue[s]);
	}
	
	return qval;
}


/*********************************************************/
/* initqvalue(Qvalue *qv) : Q値を初期化する              */
/*********************************************************/
void initqvalue(Qvalue *qv){
	
	int i=0;
	
	srand((unsigned)time(NULL));    /* time関数を用いた乱数初期化の定番式 */
	
	for(i=0; i < NODENO; ++i){
		qv->qvalue[i] = rand100();
	}
	
}

/*********************************************************/
/* printqvalue() : Q値を出力する                         */
/*********************************************************/
void printqvalue(Qvalue *qv){
	
	int i=0;
	
	for(i=0; i < NODENO; ++i){
		printf("qvalue[%d] = %d\n", i, qv->qvalue[i]);
	}
}


