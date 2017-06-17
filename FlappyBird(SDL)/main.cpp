//===============================
//程序名称：FlappyBird(SDL)
//版本号：1.0
//制作人：杨新瑞
//
//创建时间：2017-6-16 08:22:14
//完工时间：2017-6-17 16:45:35
//代码量：1441行
//制作周期：2 天
//
//===============================

#include "function.h"

int main(int argc,char **argv)
{
	Window *window = new Window;
	window->Init(u8"FlappyBird(SDL)", 384, 512);//添加u8以支持中文

	mainloop(window);

	window->Quit();
	delete window;
	return 0;
}
