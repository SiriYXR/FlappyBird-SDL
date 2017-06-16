#pragma once
#include "Picture.h"

#include <string>

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")
#pragma comment(lib,"SDL2test.lib")
#include <SDL.h>
#include <stdexcept>

class Window
{
public:
	Window();
	~Window();

	//Start SDL and TTF, create the window and renderer
	void Init(std::string title = "Window",const int SCREEN_WIDTH = 640,const int SCREEN_HEIGHT = 480 );
	//Quit SDL and TTF
	void Quit();
	//Draw an SDL_Texture
	void Draw(SDL_Texture *tex, SDL_Rect &dstRect, SDL_Rect *clip = NULL, float angle = 0.0, int xPivot = 0, int yPivot = 0, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void Draw(SDL_Texture *tex,int x,int y);
	//Render some text
	SDL_Texture* RenderText(const std::string &message, const std::string &fontFile, SDL_Color color, int fontSize);
	//Clear window
	void Clear();
	//Present renderer
	void Present();
	//Get the window's box
	SDL_Rect Box();
	
	
	void StartMovie();
	void EscapeMovie();

public:
	Picture *mPicture;

private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	SDL_Rect mBox;

	
};


