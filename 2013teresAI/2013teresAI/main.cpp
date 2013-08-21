#include"DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow )
{
	ChangeWindowMode(TRUE);
	//SetMouseDispFlag(TRUE);
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	SetScreenMemToVramFlag(FALSE);
	SetAlwaysRunFlag(TRUE);
	SetDrawScreen( DX_SCREEN_BACK);
	if(DxLib_Init()==-1)		// �c�w���C�u��������������
	{
		return -1 ;			// �G���[���N�����璼���ɏI��
	}

	while(ProcessMessage()!=-1){
		ClearDrawScreen();
		ScreenFlip();
	}

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;				// �\�t�g�̏I�� 
}