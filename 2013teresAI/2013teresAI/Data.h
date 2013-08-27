#pragma once

#include "DxLib.h"
#include <string.h>
#include <iostream>
#include <math.h>
using namespace std;

#define AI_NUM 1
#define TAGGER_NUM 3
#define ROUND_MAX 100
#define TIME_LIMIT 20
//�X�e�[�W�̋K��
#define WIDTH 32
#define HEIGHT 24
//1�}�X�̑傫��
#define BOX (640/WIDTH)
//AI�̎��E#
#define VISIBLE 10
#define CENTER VISIBLE
//AI�̈ړ����x
#define AI_SPEED 4
//�P�C�T�c�̈ړ����x
#define TAGGER_SPEED 2
typedef enum{
	OPENING,
	SETTING,
	RUNNING,
	ENDING,
} Mode;

typedef enum{
	N,
	E,
	S,
	W,
	STOP,
} Action;

typedef struct{
	char name[100];//���O
	int Graph;//AI�̉摜
	Action (*moveFunc)(int view[2*VISIBLE+1][2*VISIBLE+1]);		// �s����Ԃ��֐�
	int x;//���Wx
	int y;//���Wy
	int s_x;//�h�b�g���x���̍��W(���炩�ȓ����j
	int s_y;//�h�b�g���x���̍��W(���炩�ȓ����j
	int step;//�����ړ�������
	Action act;//AI�̍s��
	int life;//
	int view[2*VISIBLE+1][2*VISIBLE+1];//
	int entry;
	int treasure;
} AI_T;

typedef struct{
	char name[100];//���O
	int Graph;
	Action (*moveFunc)(int tagger_x , int tagger_y,int Stage[WIDTH][HEIGHT]);		// �s����Ԃ��֐�
	int x;
	int y;
	int s_x;
	int s_y;
	int step;
	Action act;
} Tagger;

int intro(AI_T *ai);
void make_Stage(int Stage[WIDTH][HEIGHT]);
void draw(int stage[WIDTH][HEIGHT],AI_T ai[],Tagger tagger);