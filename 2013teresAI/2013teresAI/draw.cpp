/*�S�I�u�W�F�N�g��`�悷��֐��ł��B*/

#include "Data.h"

void draw(int stage[WIDTH][HEIGHT],AI_T ai[AI_NUM],Tagger tagger){
	int view=0;
	if(CheckHitKey(KEY_INPUT_V))view=1;// 8/19 zero:V�L�[�������Ă���ƕ`�惂�[�h���ς��܂��B
	static int stageGraph = LoadGraph("Stage_image\\kabe0.png"); //�ǂ̉摜�ǂݍ���
	//����stage�ɂ��������ă}�b�v�̕`��
	for(int i=0;i<WIDTH;i++){
		for(int j=0;j<HEIGHT;j++){
			if(view==0)SetDrawBright(150,150,150);// 8/19 zero: ���Â��`�ʂ���悤�ݒ�
			for(int k=0;k<AI_NUM;k++){// 8/19 zero: AI�̎��E�̂ݖ��邭�Ȃ�悤��
				if(i>=ai[k].x-VISIBLE && i<=ai[k].x+VISIBLE && j>=ai[k].y-VISIBLE && j<=ai[k].y+VISIBLE && ai[k].entry==1){
					SetDrawBright(255,255,255);
				}
			}
			if(i==WIDTH/2 || j==HEIGHT/2){//7/27 zero: �\����L��`���Ă�����Ƃ�������
				DrawBox(20*i,20*j,20*(i+1),20*(j+1),GetColor(100,100,250),0);
			}
			if(stage[i][j]==1){//�ǂ����ɔ��������`�Ƃ��Ă��܂��B//�y�̕ǂɂ��܂����B
//				DrawBox(20*i,20*j,20*(i+1),20*(j+1),GetColor(255,255,255),1);//�l�p�̕`��
				DrawRotaGraph((20*i)+10,(20*j)+10,1.0,0.0,stageGraph,FALSE,FALSE);//�ǂݍ��񂾕ǉ摜�\��
			}
		}
	}

	//�}�b�v�f�[�^�\��
	while(CheckHitKey(KEY_INPUT_P)==1){
		int ai_x[AI_NUM],ai_y[AI_NUM],ai_num=0;
		DrawBox(0,0,640,480,GetColor(0,0,0),1);
		for(int i=0;i<WIDTH;i++){
			for(int j=0;j<HEIGHT;j++){
				int cr;
				switch(stage[i][j]){
				case 1:
					cr=GetColor(100,50,0);
					break;
				case 2:
					cr=GetColor(255,0,0);
					ai_x[ai_num]=i;
					ai_y[ai_num]=j;
					ai_num++;
					break;
				case 3:
					cr=GetColor(0,0,100);
					break;
				default:
					cr=GetColor(0,0,0);
					break;
				}
				DrawBox(20*i,20*j,20*(i+1),20*(j+1),cr,1);
				cr=GetColor(255,255,255);
				//DrawBox(20*i,20*j,20*(i+1),20*(j+1),cr,0);
				DrawFormatString(i*20+5,j*20+5,cr,"%d",stage[i][j]);
				
			}
		}

		WaitTimer(100);
	}
}