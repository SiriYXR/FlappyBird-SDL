//===============================
//�������ƣ�FlappyBird(SDL)
//�汾�ţ�1.0
//�����ˣ�������
//
//����ʱ�䣺2017-6-16 08:22:14
//�깤ʱ�䣺
//����������
//�������ڣ�1 ��
//
//===============================

#include "function.h"

int main(int argc,char **argv)
{
	Window *window = new Window;
	window->Init(u8"FlappyBird(SDL)", 384, 512);//����u8��֧������

	mainloop(window);

	window->Quit();
	delete window;
	return 0;
}