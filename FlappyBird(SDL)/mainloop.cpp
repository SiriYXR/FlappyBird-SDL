#include "function.h"
#include "Scene.h"

void mainloop(Window *win)
{
	Scene *scene = new Scene(win);//实例化场景对象

	
	win->StartMovie();
	while (true)
	{
		scene->enent();//事件场景

		if (scene->isOver())
			break;

		scene->update();//更新场景

		scene->rend();//渲染场景

		SDL_Delay(15);//每帧延迟15ms
	}
	win->EscapeMovie();

	delete scene;
}