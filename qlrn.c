/*********************************************************/
/*  qlrn.c                                               */
/*                                                       */
/*  強化学習プログラム                                   */
/*  Q学習                                                */
/*                                                       */
/*********************************************************/
#include "qlrn.h"

#define GENMAX 1000     /*  学習の繰り返し回数  */

int qlearning(){
	
	/*  Q値の構造体  */
	Qvalue qv, *pqv;
	pqv = &qv;
	
	/*  Q値の初期化   */
	initqvalue(pqv);
	
	printqvalue(pqv);
	
	
	/*  学習の本体  */
	int i=0;
	int s=0;  /*  状態  */
	int t=0;  /*  時刻  */
	
	for(i=0; i < GENMAX; ++i){
		s = 0;
		for(t=0; t < 3; ++t){
			/*  行動選択  */
			s = selecta(s, pqv);
			
			/*  Q値の更新   */
			pqv->qvalue[s] = updateq(s, pqv);
			
		}
		printf("*** Learnnig count = %d ***\n", i);
		printqvalue(pqv);
	}
	
	
	return 0;
}


