#include "function.h"
#include "Scene.h"

void mainloop(Window *win)
{
	Scene *scene = new Scene(win);

	
	win->StartMovie();
	while (true)
	{
		scene->enent();

		if (scene->isOver())
			break;

		scene->update();

		scene->rend();
	}
	win->EscapeMovie();

	delete scene;
}