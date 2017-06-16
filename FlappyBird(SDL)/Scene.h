#pragma once
#include "function.h"

class Scene
{
public:
	Scene(Window *win);
	~Scene();

	void enent();
	void update();
	bool isOver();
	void rend();


private:
	void mouseevent();
	void keyevent();

	void update_choice();
	void update_bootInterface();
	void update_groundPosition();
	void update_init();
	void update_gameing();
	void update_birdcolor();
	void update_birdPcolor();
	void update_daystate();
	

	bool isGameOver();
	
	void rend_choice();
	void rend_bootInterface();
	void rend_gameing();
	void rend_Bird();
	void rend_ground();
	void rend_gameOver();
	void rend_obstacle();
	void rend_birdfall();
	void rend_scorecard();
	void rend_score_L(int x, int y);
	void rend_score_S(int x, int y, int score);

private:
	Window *win;
	SDL_Event events;
	State state;
	Birdcolor birdcolor;
	int daystate;
	int keyDown;
	int birdStatus;
	int deadstate;
	
	int score;
	int maxScore;

	int time;
	int temp;
	int lastTime;

	float acceleration;
	float birdHeight;
	int nofobstacle;
	Obstacle obstacle[3];
	int groundPosition;
	int wingsMark;

	int c;

	bool isover;
};

