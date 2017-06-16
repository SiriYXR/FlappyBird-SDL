#include "Picture.h"

#pragma comment(lib,"SDL2_image.lib")
#include <SDL_image.h>
#include <stdexcept>

Picture::Picture(SDL_Renderer *Ren) :Renderer(Ren)
{
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);

	loading = LoadImage("data/Picture/other/Load.png");
	outgame = LoadImage("data/Picture/other/Escape.png");
	gameOver = LoadImage("data/Picture/other/gameOver.png");
	scoreCard = LoadImage("data/Picture/other/Scorecard.png");
	startInterface = LoadImage("data/Picture/other/Start.png");
	ranking = LoadImage("data/Picture/other/Ranking.png");
	restart = LoadImage("data/Picture/other/Again.png");

	background_day = LoadImage("data/Picture/background/day.png");
	background_night = LoadImage("data/Picture/background/night.png");
	ground = LoadImage("data/Picture/background/ground.png");

	copper = LoadImage("data/Picture/Medals/copper.png");
	silver = LoadImage("data/Picture/Medals/silver.png");
	gold = LoadImage("data/Picture/Medals/gold.png");
	platinum = LoadImage("data/Picture/Medals/platinum.png");

	obstacleUp = LoadImage("data/Picture/obstacle/up.png");
	obstacleDown = LoadImage("data/Picture/obstacle/down.png");

	wingUp0 = LoadImage("data/Picture/bird/yellow/up0.png");
	wingCentered0 = LoadImage("data/Picture/bird/yellow/level0.png");
	wingDown0 = LoadImage("data/Picture/bird/yellow/down0.png");

	wingUp20 = LoadImage("data/Picture/bird/yellow/up20.png");
	wingCentered20 = LoadImage("data/Picture/bird/yellow/level20.png");
	wingDown20 = LoadImage("data/Picture/bird/yellow/down20.png");

	wingUp_20 = LoadImage("data/Picture/bird/yellow/up-20.png");
	wingCentered_20 = LoadImage("data/Picture/bird/yellow/level-20.png");
	wingDown_20 = LoadImage("data/Picture/bird/yellow/down-20.png");

	wingUp_90 = LoadImage("data/Picture/bird/yellow/up-90.png");
	wingCentered_90 = LoadImage("data/Picture/bird/yellow/level-90.png");
	wingDown_90 = LoadImage("data/Picture/bird/yellow/down-90.png");

	readyUp_day_yellow = LoadImage("data/Picture/guide/day/yellow/up.png");
	readyCentered_day_yellow = LoadImage("data/Picture/guide/day/yellow/level.png");
	readyDown_day_yellow = LoadImage("data/Picture/guide/day/yellow/down.png");
	readyUp_day_red = LoadImage("data/Picture/guide/day/red/up.png");
	readyCentered_day_red = LoadImage("data/Picture/guide/day/red/level.png");
	readyDown_day_red = LoadImage("data/Picture/guide/day/red/down.png");
	readyUp_day_blue = LoadImage("data/Picture/guide/day/blue/up.png");
	readyCentered_day_blue = LoadImage("data/Picture/guide/day/blue/level.png");
	readyDown_day_blue = LoadImage("data/Picture/guide/day/blue/down.png");
	readyUp_day_green = LoadImage("data/Picture/guide/day/green/up.png");
	readyCentered_day_green = LoadImage("data/Picture/guide/day/green/level.png");
	readyDown_day_green = LoadImage("data/Picture/guide/day/green/down.png");

	readyUp_night_yellow = LoadImage("data/Picture/guide/night/yellow/up.png");
	readyCentered_night_yellow = LoadImage("data/Picture/guide/night/yellow/level.png");
	readyDown_night_yellow = LoadImage("data/Picture/guide/night/yellow/down.png");
	readyUp_night_red = LoadImage("data/Picture/guide/night/red/up.png");
	readyCentered_night_red = LoadImage("data/Picture/guide/night/red/level.png");
	readyDown_night_red = LoadImage("data/Picture/guide/night/red/down.png");
	readyUp_night_blue = LoadImage("data/Picture/guide/night/blue/up.png");
	readyCentered_night_blue = LoadImage("data/Picture/guide/night/blue/level.png");
	readyDown_night_blue = LoadImage("data/Picture/guide/night/blue/down.png");
	readyUp_night_green = LoadImage("data/Picture/guide/night/green/up.png");
	readyCentered_night_green = LoadImage("data/Picture/guide/night/green/level.png");
	readyDown_night_green = LoadImage("data/Picture/guide/night/green/down.png");

	number0_L = LoadImage("data/Picture/number/L/0.png");
	number1_L = LoadImage("data/Picture/number/L/1.png");
	number2_L = LoadImage("data/Picture/number/L/2.png");
	number3_L = LoadImage("data/Picture/number/L/3.png");
	number4_L = LoadImage("data/Picture/number/L/4.png");
	number5_L = LoadImage("data/Picture/number/L/5.png");
	number6_L = LoadImage("data/Picture/number/L/6.png");
	number7_L = LoadImage("data/Picture/number/L/7.png");
	number8_L = LoadImage("data/Picture/number/L/8.png");
	number9_L = LoadImage("data/Picture/number/L/9.png");

	number0_S = LoadImage("data/Picture/number/S/0.png");
	number1_S = LoadImage("data/Picture/number/S/1.png");
	number2_S = LoadImage("data/Picture/number/S/2.png");
	number3_S = LoadImage("data/Picture/number/S/3.png");
	number4_S = LoadImage("data/Picture/number/S/4.png");
	number5_S = LoadImage("data/Picture/number/S/5.png");
	number6_S = LoadImage("data/Picture/number/S/6.png");
	number7_S = LoadImage("data/Picture/number/S/7.png");
	number8_S = LoadImage("data/Picture/number/S/8.png");
	number9_S = LoadImage("data/Picture/number/S/9.png");
}


Picture::~Picture()
{
	delimage(loading);
	delimage(outgame);
	delimage(gameOver);
	delimage(scoreCard);
	delimage(startInterface);
	delimage(ranking);
	delimage(restart);

	delimage(background_day);
	delimage(background_night);
	delimage(ground);

	delimage(copper);
	delimage(silver);
	delimage(gold);
	delimage(platinum);

	delimage(obstacleUp);
	delimage(obstacleDown);

	delimage(wingUp0);
	delimage(wingCentered0);
	delimage(wingDown0);

	delimage(wingUp20);
	delimage(wingCentered20);
	delimage(wingDown20);

	delimage(wingUp_20);
	delimage(wingCentered_20);
	delimage(wingDown_20);

	delimage(wingUp_90);
	delimage(wingCentered_90);
	delimage(wingDown_90);

	delimage(readyUp_day_yellow);
	delimage(readyCentered_day_yellow);
	delimage(readyDown_day_yellow);
	delimage(readyUp_day_red);
	delimage(readyCentered_day_red);
	delimage(readyDown_day_red);
	delimage(readyUp_day_blue);
	delimage(readyCentered_day_blue);
	delimage(readyDown_day_blue);
	delimage(readyUp_day_green);
	delimage(readyCentered_day_green);
	delimage(readyDown_day_green);

	delimage(readyUp_night_yellow);
	delimage(readyCentered_night_yellow);
	delimage(readyDown_night_yellow);
	delimage(readyUp_night_red);
	delimage(readyCentered_night_red);
	delimage(readyDown_night_red);
	delimage(readyUp_night_blue);
	delimage(readyCentered_night_blue);
	delimage(readyDown_night_blue);
	delimage(readyUp_night_green);
	delimage(readyCentered_night_green);
	delimage(readyDown_night_green);

	delimage(number0_L);
	delimage(number1_L);
	delimage(number2_L);
	delimage(number3_L);
	delimage(number4_L);
	delimage(number5_L);
	delimage(number6_L);
	delimage(number7_L);
	delimage(number8_L);
	delimage(number9_L);

	delimage(number0_S);
	delimage(number1_S);
	delimage(number2_S);
	delimage(number3_S);
	delimage(number4_S);
	delimage(number5_S);
	delimage(number6_S);
	delimage(number7_S);
	delimage(number8_S);
	delimage(number9_S);
}

/**
*  Loads an image directly to texture using SDL_image's
*  built in function IMG_LoadTexture
*  @param file The image file to load
*  @return SDL_Texture* to the loaded texture
*/
SDL_Texture * Picture::LoadImage(const std::string & file)
{
	SDL_Texture *texture = IMG_LoadTexture(Renderer, file.c_str());
	if (texture == nullptr) {
		throw std::runtime_error("LoadTexture");
	}
	return texture;
}

void Picture::delimage(SDL_Texture * image)
{
	SDL_DestroyTexture(image);
}

void Picture::Load_yellowBird()
{
	delimage(wingUp0);
	delimage(wingCentered0);
	delimage(wingDown0);

	delimage(wingUp20);
	delimage(wingCentered20);
	delimage(wingDown20);

	delimage(wingUp_20);
	delimage(wingCentered_20);
	delimage(wingDown_20);

	delimage(wingUp_90);
	delimage(wingCentered_90);
	delimage(wingDown_90);

	wingUp0 = LoadImage("data/Picture/bird/yellow/up0.png");
	wingCentered0 = LoadImage("data/Picture/bird/yellow/level0.png");
	wingDown0 = LoadImage("data/Picture/bird/yellow/down0.png");

	wingUp20 = LoadImage("data/Picture/bird/yellow/up20.png");
	wingCentered20 = LoadImage("data/Picture/bird/yellow/level20.png");
	wingDown20 = LoadImage("data/Picture/bird/yellow/down20.png");

	wingUp_20 = LoadImage("data/Picture/bird/yellow/up-20.png");
	wingCentered_20 = LoadImage("data/Picture/bird/yellow/level-20.png");
	wingDown_20 = LoadImage("data/Picture/bird/yellow/down-20.png");

	wingUp_90 = LoadImage("data/Picture/bird/yellow/up-90.png");
	wingCentered_90 = LoadImage("data/Picture/bird/yellow/level-90.png");
	wingDown_90 = LoadImage("data/Picture/bird/yellow/down-90.png");

}

void Picture::Load_redBird()
{
	delimage(wingUp0);
	delimage(wingCentered0);
	delimage(wingDown0);

	delimage(wingUp20);
	delimage(wingCentered20);
	delimage(wingDown20);

	delimage(wingUp_20);
	delimage(wingCentered_20);
	delimage(wingDown_20);

	delimage(wingUp_90);
	delimage(wingCentered_90);
	delimage(wingDown_90);

	wingUp0 = LoadImage("data/Picture/bird/red/up0.png");
	wingCentered0 = LoadImage("data/Picture/bird/red/level0.png");
	wingDown0 = LoadImage("data/Picture/bird/red/down0.png");

	wingUp20 = LoadImage("data/Picture/bird/red/up20.png");
	wingCentered20 = LoadImage("data/Picture/bird/red/level20.png");
	wingDown20 = LoadImage("data/Picture/bird/red/down20.png");

	wingUp_20 = LoadImage("data/Picture/bird/red/up-20.png");
	wingCentered_20 = LoadImage("data/Picture/bird/red/level-20.png");
	wingDown_20 = LoadImage("data/Picture/bird/red/down-20.png");

	wingUp_90 = LoadImage("data/Picture/bird/red/up-90.png");
	wingCentered_90 = LoadImage("data/Picture/bird/red/level-90.png");
	wingDown_90 = LoadImage("data/Picture/bird/red/down-90.png");
}

void Picture::Load_blueBird()
{
	delimage(wingUp0);
	delimage(wingCentered0);
	delimage(wingDown0);

	delimage(wingUp20);
	delimage(wingCentered20);
	delimage(wingDown20);

	delimage(wingUp_20);
	delimage(wingCentered_20);
	delimage(wingDown_20);

	delimage(wingUp_90);
	delimage(wingCentered_90);
	delimage(wingDown_90);

	wingUp0 = LoadImage("data/Picture/bird/blue/up0.png");
	wingCentered0 = LoadImage("data/Picture/bird/blue/level0.png");
	wingDown0 = LoadImage("data/Picture/bird/blue/down0.png");

	wingUp20 = LoadImage("data/Picture/bird/blue/up20.png");
	wingCentered20 = LoadImage("data/Picture/bird/blue/level20.png");
	wingDown20 = LoadImage("data/Picture/bird/blue/down20.png");

	wingUp_20 = LoadImage("data/Picture/bird/blue/up-20.png");
	wingCentered_20 = LoadImage("data/Picture/bird/blue/level-20.png");
	wingDown_20 = LoadImage("data/Picture/bird/blue/down-20.png");

	wingUp_90 = LoadImage("data/Picture/bird/blue/up-90.png");
	wingCentered_90 = LoadImage("data/Picture/bird/blue/level-90.png");
	wingDown_90 = LoadImage("data/Picture/bird/blue/down-90.png");
}

void Picture::Load_greenBird()
{
	delimage(wingUp0);
	delimage(wingCentered0);
	delimage(wingDown0);

	delimage(wingUp20);
	delimage(wingCentered20);
	delimage(wingDown20);

	delimage(wingUp_20);
	delimage(wingCentered_20);
	delimage(wingDown_20);

	delimage(wingUp_90);
	delimage(wingCentered_90);
	delimage(wingDown_90);

	wingUp0 = LoadImage("data/Picture/bird/green/up0.png");
	wingCentered0 = LoadImage("data/Picture/bird/green/level0.png");
	wingDown0 = LoadImage("data/Picture/bird/green/down0.png");

	wingUp20 = LoadImage("data/Picture/bird/green/up20.png");
	wingCentered20 = LoadImage("data/Picture/bird/green/level20.png");
	wingDown20 = LoadImage("data/Picture/bird/green/down20.png");

	wingUp_20 = LoadImage("data/Picture/bird/green/up-20.png");
	wingCentered_20 = LoadImage("data/Picture/bird/green/level-20.png");
	wingDown_20 = LoadImage("data/Picture/bird/green/down-20.png");

	wingUp_90 = LoadImage("data/Picture/bird/green/up-90.png");
	wingCentered_90 = LoadImage("data/Picture/bird/green/level-90.png");
	wingDown_90 = LoadImage("data/Picture/bird/green/down-90.png");
}
