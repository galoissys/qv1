/*********************************************************/
/*  qlrn.c                                               */
/*                                                       */
/*  �����w�K�v���O����                                   */
/*  Q�w�K                                                */
/*                                                       */
/*********************************************************/
#include "qlrn.h"

#define GENMAX 1000     /*  �w�K�̌J��Ԃ���  */

int qlearning(){
	
	/*  Q�l�̍\����  */
	Qvalue qv, *pqv;
	pqv = &qv;
	
	/*  Q�l�̏�����   */
	initqvalue(pqv);
	
	printqvalue(pqv);
	
	
	/*  �w�K�̖{��  */
	int i=0;
	int s=0;  /*  ���  */
	int t=0;  /*  ����  */
	
	for(i=0; i < GENMAX; ++i){
		s = 0;
		for(t=0; t < 3; ++t){
			/*  �s���I��  */
			s = selecta(s, pqv);
			
			/*  Q�l�̍X�V   */
			pqv->qvalue[s] = updateq(s, pqv);
			
		}
		printf("*** Learnnig count = %d ***\n", i);
		printqvalue(pqv);
	}
	
	
	return 0;
}


