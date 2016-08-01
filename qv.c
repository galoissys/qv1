/*********************************************************/
/*  qv.c                                                 */
/*                                                       */
/*  �����w�K�v���O����                                   */
/*  Q�w�K                                                */
/*                                                       */
/*********************************************************/
#include "qv.h"

/*********************************************************/
/*  Q�w�K �֐�                                           */
/*********************************************************/

/*********************************************************/
/* selecta() : �s����I������                            */
/*********************************************************/
int selecta(int olds, Qvalue *qv){
	
	int s;
	
	srand((unsigned)time(NULL));    /* time�֐���p���������������̒�Ԏ� */
	
	/* ��-greedy�@�ɂ��s���I��  */
	if(rand1() < EPSILON){
		/*  �����_���ɍs��  */
		if(rand01() == 0){
			s = 2 * olds + 1;
		}else{
			s = 2 * olds + 2;
		}
	}else{
		/*  Q�l���ő�ƂȂ�s����I��  */
		if( (qv->qvalue[2 * olds + 1]) > (qv->qvalue[2 * olds + 2]) ){
			s = 2 * olds + 1;
		}else{
			s = 2 * olds + 2;
		}
	}
	
	return s;
}

/*********************************************************/
/* updateq() : Q�l���X�V����                             */
/*********************************************************/
int updateq(int s, Qvalue *qv){
	
	int qval;
	int qmax;
	
	/* �ŉ��i�̏ꍇ  */
	if(s > 6){
		if(s == 14){
			/*  ��V�̕t�^   */
			qval = qv->qvalue[s] + ALPHA * (1000 - qv->qvalue[s]);
		}
		/*  ��V��^����m�[�h�𑝂₷ Start */
		else if(s == 11){
			qval = qv->qvalue[s] + ALPHA * (500 - qv->qvalue[s]);
		}
		/*  ��V��^����m�[�h�𑝂₷ End */
		else{
			/*  ��V�Ȃ�  */
			qval = qv->qvalue[s];
		}
	}
	/*  �ŉ��i�ȊO�̏ꍇ   */
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
/* initqvalue(Qvalue *qv) : Q�l������������              */
/*********************************************************/
void initqvalue(Qvalue *qv){
	
	int i=0;
	
	srand((unsigned)time(NULL));    /* time�֐���p���������������̒�Ԏ� */
	
	for(i=0; i < NODENO; ++i){
		qv->qvalue[i] = rand100();
	}
	
}

/*********************************************************/
/* printqvalue() : Q�l���o�͂���                         */
/*********************************************************/
void printqvalue(Qvalue *qv){
	
	int i=0;
	
	for(i=0; i < NODENO; ++i){
		printf("qvalue[%d] = %d\n", i, qv->qvalue[i]);
	}
}


