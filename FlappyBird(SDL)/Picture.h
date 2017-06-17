#pragma once

#pragma comment(lib,"SDL2.lib")
#pragma comment(lib,"SDL2main.lib")

#include <SDL.h>
#include <stdexcept>
#include <string>

class Picture
{
public:
	Picture(SDL_Renderer *Ren);
	~Picture();

	//Load an image
	SDL_Texture * Picture::LoadImage(const std::string & file);
	void delimage(SDL_Texture* image);

	void Load_yellowBird();
	void Load_redBird();
	void Load_blueBird();
	void Load_greenBird();

private:
	SDL_Renderer *Renderer=nullptr;

public:
	 SDL_Texture *loading =nullptr;
	 SDL_Texture *outgame =nullptr;
	 SDL_Texture *startInterface =nullptr;
	 SDL_Texture *gameOver =nullptr;
	 SDL_Texture *scoreCard =nullptr;
	 SDL_Texture *restart =nullptr;
	 SDL_Texture *ranking =nullptr;

	 SDL_Texture *background_day =nullptr;	//创建背景图对象
	 SDL_Texture *background_night =nullptr;
	 SDL_Texture *ground =nullptr;	//创建地面图对象

	 SDL_Texture *copper =nullptr;
	 SDL_Texture *silver =nullptr;
	 SDL_Texture *gold =nullptr;
	 SDL_Texture *platinum =nullptr;

	 SDL_Texture *obstacleUp =nullptr;	//创建柱子图对象（柱子朝上）
	 SDL_Texture *obstacleDown =nullptr;	//创建柱子图对象（柱子朝下）

	 SDL_Texture *wingUp_90 =nullptr;
	 SDL_Texture *wingCentered_90 =nullptr;
	 SDL_Texture *wingDown_90 =nullptr;

	 SDL_Texture *wingUp0 =nullptr;
	 SDL_Texture *wingCentered0 =nullptr;
	 SDL_Texture *wingDown0 =nullptr;

	 SDL_Texture *wingUp20 =nullptr;
	 SDL_Texture *wingCentered20 =nullptr;
	 SDL_Texture *wingDown20 =nullptr;

	 SDL_Texture *wingUp_20 =nullptr;
	 SDL_Texture *wingCentered_20 =nullptr;
	 SDL_Texture *wingDown_20 =nullptr;

	 SDL_Texture *readyUp_day_yellow =nullptr;	//创建准备界面图对象（鸟的翅膀向上）
	 SDL_Texture *readyCentered_day_yellow =nullptr;	//创建准备界面图对象
	 SDL_Texture *readyDown_day_yellow =nullptr;	//创建准备界面图对象（鸟的翅膀向下）
	 SDL_Texture *readyUp_day_red =nullptr;
	 SDL_Texture *readyCentered_day_red =nullptr;
	 SDL_Texture *readyDown_day_red =nullptr;
	 SDL_Texture *readyUp_day_blue =nullptr;
	 SDL_Texture *readyCentered_day_blue =nullptr;
	 SDL_Texture *readyDown_day_blue =nullptr;
	 SDL_Texture *readyUp_day_green =nullptr;
	 SDL_Texture *readyCentered_day_green =nullptr;
	 SDL_Texture *readyDown_day_green =nullptr;

	 SDL_Texture *readyUp_night_yellow =nullptr;	//创建准备界面图对象（鸟的翅膀向上）
	 SDL_Texture *readyCentered_night_yellow =nullptr;	//创建准备界面图对象
	 SDL_Texture *readyDown_night_yellow =nullptr;	//创建准备界面图对象（鸟的翅膀向下）
	 SDL_Texture *readyUp_night_red =nullptr;
	 SDL_Texture *readyCentered_night_red =nullptr;
	 SDL_Texture *readyDown_night_red =nullptr;
	 SDL_Texture *readyUp_night_blue =nullptr;
	 SDL_Texture *readyCentered_night_blue =nullptr;
	 SDL_Texture *readyDown_night_blue =nullptr;
	 SDL_Texture *readyUp_night_green =nullptr;
	 SDL_Texture *readyCentered_night_green =nullptr;
	 SDL_Texture *readyDown_night_green =nullptr;

	 SDL_Texture *number0_L =nullptr;
	 SDL_Texture *number1_L =nullptr;
	 SDL_Texture *number2_L =nullptr;
	 SDL_Texture *number3_L =nullptr;
	 SDL_Texture *number4_L =nullptr;
	 SDL_Texture *number5_L =nullptr;
	 SDL_Texture *number6_L =nullptr;
	 SDL_Texture *number7_L =nullptr;
	 SDL_Texture *number8_L =nullptr;
	 SDL_Texture *number9_L =nullptr;

	 SDL_Texture *number0_S =nullptr;
	 SDL_Texture *number1_S =nullptr;
	 SDL_Texture *number2_S =nullptr;
	 SDL_Texture *number3_S =nullptr;
	 SDL_Texture *number4_S =nullptr;
	 SDL_Texture *number5_S =nullptr;
	 SDL_Texture *number6_S =nullptr;
	 SDL_Texture *number7_S =nullptr;
	 SDL_Texture *number8_S =nullptr;
	 SDL_Texture *number9_S =nullptr;
};

