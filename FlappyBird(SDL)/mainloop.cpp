#include "function.h"
#include "Scene.h"

void mainloop(Window *win)
{
	Scene *scene = new Scene(win);//ʵ������������

	
	win->StartMovie();
	while (true)
	{
		scene->enent();//�¼�����

		if (scene->isOver())
			break;

		scene->update();//���³���

		scene->rend();//��Ⱦ����

		SDL_Delay(15);//ÿ֡�ӳ�15ms
	}
	win->EscapeMovie();

	delete scene;
}