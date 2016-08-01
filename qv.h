/*********************************************************/
/*  qv.h                                                 */
/*                                                       */
/*  �����w�K�v���O����                                   */
/*  Q�w�K                                                */
/*                                                       */
/*********************************************************/
#ifndef _QV_H_
#define _QV_H_

#include <stdio.h>
#include <stdlib.h>
#include "rnd.h"

// selecta()�֐��Ŏg�p
#define EPSILON 0.3      /* �s���I���̃����_����������   */

// updataq()�֐��Ŏg�p
#define ALPHA 0.1        /* �w�K�W��     */
#define GAMMA 0.9        /* ������     */

/*  Q-Value �f�[�^�\��               */
#define NODENO 15        /* Q�l�̃m�[�h��    */

typedef struct{
	int qvalue[NODENO];  /* Q�l     */
} Qvalue;

/*  Q�w�K �֐�                       */
int selecta(int olds, Qvalue *qv);   // �s����I������
int updateq(int state, Qvalue *qv);  // Q�l���X�V����

void initqvalue(Qvalue *qv);        // Q�l������������
void printqvalue(Qvalue *qv);        // Q�l���o�͂���


#endif

