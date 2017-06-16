#pragma once
#include "Window.h"

enum State
{
	choice,
	ready,
	init,
	gameing,
	pause,
	dead,
	deadchoice
};

enum Birdcolor
{
	yellow,
	red,
	blue,
	green
};

struct Obstacle	//障碍物位置信息结构体
{
	int x;
	int h;
};

void mainloop(Window *win);

void saveHiScore(int score);
int readHiScore();

int Myrand(int max, int min = 0);
