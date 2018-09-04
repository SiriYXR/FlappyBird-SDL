#include "Scene.h"


Scene::Scene(Window *win) :win(win)
{
	groundPosition = 0;//ground图片位置
	wingsMark = 0;//鸟的状态

	for (int i = 0; i < 3; i++)//障碍物
	{
		obstacle[i].h = 0;
		obstacle[i].x = 0;
	}

	score = 0;
	maxScore = readHiScore();

	time = 0;
	acceleration = 0;
	birdHeight = 0;
	nofobstacle = 3;

	state = choice;
	daystate = 0;
	keyDown = 0;
	birdStatus = 1;
	deadstate = 0;

	isover = false;
}

Scene::~Scene()
{
	win = nullptr;
}

void Scene::enent()
{
	while (SDL_PollEvent(&events))
	{
		//If user closes the window
		if (events.type == SDL_QUIT)
		{
			isover = true;
			return;
		}

		if (events.type == SDL_MOUSEBUTTONDOWN)
		{
			mouseevent();
		}

		if (events.type == SDL_KEYDOWN)
		{
			keyevent();
		}
	}
}

void Scene::update()
{
	uodate_time();

	if (state == choice)
		update_choice();
	if (state == ready)
		update_bootInterface();
	if (state == init)
		update_init();
	if (state == gameing)
		update_gameing();
	if (state == dead)
	{
		if (score > maxScore)
		{
			saveHiScore(score);
			maxScore = score;
		}
		state = deadchoice;
	}
}

bool Scene::isOver()
{
	return isover;
}

void Scene::rend()
{
	if (state != pause)
	{
		win->Clear();

		if (state == choice)
			rend_choice();
		if (state == ready)
			rend_bootInterface();
		if (state == deadchoice)
			rend_gameOver();
		if (state == gameing)
			rend_gameing();

		win->Present();
	}
}

void Scene::mouseevent()
{
	int x, y;
	x = events.motion.x;
	y = events.motion.y;

	if (events.button.button == SDL_BUTTON_LEFT)
	{
		if (state == ready&&time >= 30)
		{
			state = init;
			win->mMusic->wing->play();
		}

		if (state == choice && (x > 35 && x < 175 && y>360 && y < 440))
		{
			time = 0;
			state = ready;
			update_birdcolor();
			update_daystate();
			win->mMusic->wing->play();
		}

		if (state == deadchoice &&deadstate == 4 && (x > 35 && x < 175 && y>360 && y < 440))	//判断是否点击重新开始
		{
			time = 0;
			state = ready;
			update_birdcolor();
			update_daystate();
			win->mMusic->wing->play();
		}

		if (time - lastTime > 1 && state == gameing)
		{
			keyDown = 10;
			birdStatus = 2;
			acceleration = -180;
			lastTime = time;
			win->mMusic->wing->play();
		}

		if (state == pause)
		{
			state = gameing;
			keyDown = 10;
			birdStatus = 2;
			acceleration = -180;
			lastTime = time;
			win->mMusic->wing->play();
		}

	}

	if (events.button.button == SDL_BUTTON_RIGHT)
	{
		if (state == pause)
		{
			state = gameing;
			win->mMusic->wing->play();
		}
		else if (state == gameing)
		{
			state = pause;
		}
	}

}

void Scene::keyevent()
{
	switch (events.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		isover = true;
		break;
	default:
		break;
	}
}

void Scene::uodate_time()
{
	time += 1;
	if (time == 10000)
		time = 0;
}

void Scene::update_choice()
{
	update_groundPosition();
	wingsMark = groundPosition % 128;
}

void Scene::update_bootInterface()
{
	update_groundPosition();
	temp = time % 64;

}

void Scene::update_groundPosition()
{
	groundPosition -= 2;
	if (groundPosition <= 0)
		groundPosition = 384;
}

void Scene::update_init()
{
	update_birdPcolor();
	maxScore = readHiScore();
	birdHeight = 250;
	lastTime = 0;
	time = 0;

	score = 0;
	acceleration = -180;
	birdStatus = 2;
	keyDown = 10;
	deadstate = 0;

	for (int i = 0, x = 700; i < 3; ++i, x += 240)//设置障碍物的初始位置
		obstacle[i].x = x;

	state = gameing;
}

void Scene::update_gameing()
{
	update_groundPosition();

	/***************计算高度************************/
	acceleration += 9.8;
	birdHeight += acceleration * 3 / 77;

	/***************柱子的移动**********************/
	for (int c = 0; c < 3; c++)
	{
		obstacle[c].x -= 2;
		if (obstacle[c].x <= -70)
			obstacle[c].x = 650;
		if (obstacle[c].x == 512)
		{
			obstacle[c].h = Myrand(200) + 200;
		}
	}

	/***************计算分数****************/
	for (int c = 0; c < 3; ++c)	//只要障碍物通过鸟的位置，分数就加一
	{
		if (obstacle[c].x == 100 - 66)
		{
			win->mMusic->point->play();
			++score;
		}
	}

	if (isGameOver())
	{
		state = dead;
		win->mMusic->hit->play();
	}
}

void Scene::update_birdcolor()
{
	int i;
	i = Myrand(12) % 4;
	if (i == 0)
		birdcolor = red;
	else if (i == 1)
		birdcolor = blue;
	else if (i == 2)
		birdcolor = green;
	else
		birdcolor = yellow;
}

void Scene::update_birdPcolor()
{
	if (birdcolor == yellow)
	{
		win->mPicture->Load_yellowBird();
	}
	else if (birdcolor == red)
	{
		win->mPicture->Load_redBird();
	}
	else if (birdcolor == blue)
	{
		win->mPicture->Load_blueBird();
	}
	else if (birdcolor == green)
	{
		win->mPicture->Load_greenBird();
	}
}

void Scene::update_daystate()
{
	daystate = (Myrand(10) + 1) % 2;
}

bool Scene::isGameOver()
{
	//鸟是否碰到障碍物
	for (int i = 0; i < nofobstacle; ++i)
		if (obstacle[i].x >= 35 && obstacle[i].x <= 135 && (obstacle[i].h<(birdHeight + 27) || (obstacle[i].h - 155)>birdHeight))
		{

			return true;
		}
	//判断鸟是否撞到地面
	if (birdHeight > 420)
	{
		return true;
	}
	return false;
}

void Scene::rend_choice()
{
	win->Draw(win->mPicture->startInterface, 0, 0);

	rend_ground();

	if (wingsMark >= 0 && wingsMark < 32)
		win->Draw(win->mPicture->wingCentered0, 175, 220);
	if (wingsMark >= 32 && wingsMark < 64)
		win->Draw(win->mPicture->wingUp0, 175, 216);
	if (wingsMark >= 64 && wingsMark < 96)
		win->Draw(win->mPicture->wingCentered0, 175, 220);
	if (wingsMark >= 96 && wingsMark <= 128)
		win->Draw(win->mPicture->wingDown0, 175, 224);
}

void Scene::rend_bootInterface()
{
	if (temp >= 0 && temp < 16)
		if (daystate == 0)
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyUp_day_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyUp_day_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyUp_day_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyUp_day_green, 0, 0);
		}
		else
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyUp_night_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyUp_night_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyUp_night_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyUp_night_green, 0, 0);
		}
	if (temp >= 16 && temp < 32)
		if (daystate == 0)
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyCentered_day_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyCentered_day_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyCentered_day_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyCentered_day_green, 0, 0);
		}
		else
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyCentered_night_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyCentered_night_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyCentered_night_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyCentered_night_green, 0, 0);
		}
	if (temp >= 32 && temp < 48)
		if (daystate == 0)
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyDown_day_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyDown_day_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyDown_day_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyDown_day_green, 0, 0);
		}
		else
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyDown_night_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyDown_night_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyDown_night_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyDown_night_green, 0, 0);
		}
	if (temp >= 48 && temp < 64)
		if (daystate == 0)
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyCentered_day_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyCentered_day_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyCentered_day_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyCentered_day_green, 0, 0);
		}
		else
		{
			if (birdcolor == yellow)
				win->Draw(win->mPicture->readyCentered_night_yellow, 0, 0);
			else if (birdcolor == red)
				win->Draw(win->mPicture->readyCentered_night_red, 0, 0);
			else if (birdcolor == blue)
				win->Draw(win->mPicture->readyCentered_night_blue, 0, 0);
			else if (birdcolor == green)
				win->Draw(win->mPicture->readyCentered_night_green, 0, 0);

		}

	rend_ground();
}

void Scene::rend_gameing()
{
	if (!daystate)
		win->Draw(win->mPicture->background_day, 0, 0);
	else
		win->Draw(win->mPicture->background_night, 0, 0);

	rend_obstacle();
	rend_Bird();
	rend_score_L(170, 40);
	rend_ground();
}

void Scene::rend_Bird()
{
	//利用模拟时间实现鸟的动态变化
	temp = time % 16;
	//水平
	if (birdStatus == 1)
	{
		if (temp >= 0 && temp < 4)
			win->Draw(win->mPicture->wingCentered0, 100, birdHeight);
		if (temp >= 4 && temp < 8)
			win->Draw(win->mPicture->wingUp0, 100, birdHeight);
		if (temp >= 8 && temp < 12)
			win->Draw(win->mPicture->wingCentered0, 100, birdHeight);
		if (temp >= 12 && temp < 16)
			win->Draw(win->mPicture->wingDown0, 100, birdHeight);
		if (keyDown > 0)
		{
			--keyDown;
			if (keyDown == 0)
			{
				birdStatus = 4;
				keyDown = 5;
			}
		}
	}
	//斜向上20度
	else if (birdStatus == 2)
	{
		if (temp >= 0 && temp < 4)
			win->Draw(win->mPicture->wingCentered20, 100, birdHeight);
		if (temp >= 4 && temp < 8)
			win->Draw(win->mPicture->wingUp20, 100, birdHeight);
		if (temp >= 8 && temp < 12)
			win->Draw(win->mPicture->wingCentered20, 100, birdHeight);
		if (temp >= 12 && temp < 16)
			win->Draw(win->mPicture->wingDown20, 100, birdHeight);
		if (keyDown > 0)
		{
			--keyDown;
			if (keyDown == 0)
			{
				birdStatus = 1;
				keyDown = 20;
			}
		}
	}
	//斜向下20度
	else if (birdStatus == 4)
	{
		if (temp >= 0 && temp < 4)
			win->Draw(win->mPicture->wingCentered_20, 100, birdHeight);
		if (temp >= 4 && temp < 8)
			win->Draw(win->mPicture->wingUp_20, 100, birdHeight);
		if (temp >= 8 && temp < 12)
			win->Draw(win->mPicture->wingCentered_20, 100, birdHeight);
		if (temp >= 12 && temp < 16)
			win->Draw(win->mPicture->wingDown_20, 100, birdHeight);
	}
}

void Scene::rend_ground()
{
	win->Draw(win->mPicture->ground, groundPosition, 448);
	win->Draw(win->mPicture->ground, groundPosition - 384, 448);
}

void Scene::rend_gameOver()
{
	//显示背景
	if (daystate == 0)
		win->Draw(win->mPicture->background_day, 0, 0);
	else
		win->Draw(win->mPicture->background_night, 0, 0);

	if (birdHeight < 420)//如果鸟到达地面，游戏结束，退出循环
		rend_birdfall();
	else
		rend_scorecard();
}

void Scene::rend_obstacle()
{
	for (int c = 0; c < 3; c++)
	{
		win->Draw(win->mPicture->obstacleUp, obstacle[c].x, obstacle[c].h);
		win->Draw(win->mPicture->obstacleDown, obstacle[c].x, (obstacle[c].h - 400));
	}
}

void Scene::rend_birdfall()
{
	//显示柱子
	rend_obstacle();
	//显示地面
	rend_ground();

	//显示鸟
	temp = time % 16;
	if (temp >= 0 && temp < 4)
		win->Draw(win->mPicture->wingCentered_90, 100, birdHeight);
	if (temp >= 4 && temp < 8)
		win->Draw(win->mPicture->wingUp_90, 100, birdHeight);
	if (temp >= 8 && temp < 12)
		win->Draw(win->mPicture->wingCentered_90, 100, birdHeight);
	if (temp >= 12 && temp < 16)
		win->Draw(win->mPicture->wingDown_90, 100, birdHeight);

	//模拟鸟下降速度变化
	acceleration += 9.8;
	birdHeight += acceleration * 2 / 77;

}

void Scene::rend_scorecard()
{
	rend_obstacle();
	//显示地面
	rend_ground();
	win->Draw(win->mPicture->wingCentered_90, 100, birdHeight - 13);
	//画结束界面
	if (deadstate == 0)
	{
		deadstate++;
		win->Draw(win->mPicture->gameOver, 55, 60);
		win->mMusic->die->play();
		SDL_Delay(400);	//平均延迟400毫秒
	}
	else if (deadstate == 1)
	{
		deadstate++;
		win->mMusic->wing->play();
		for (int i = 500; i >= 150; i -=25)
		{
			win->Clear();
			if (daystate == 0)
				win->Draw(win->mPicture->background_day, 0, 0);
			else
				win->Draw(win->mPicture->background_night, 0, 0);
			rend_obstacle();
			rend_ground();
			win->Draw(win->mPicture->wingCentered_90, 100, birdHeight - 13);
			win->Draw(win->mPicture->gameOver, 55, 60);
			win->Draw(win->mPicture->scoreCard, 35, i);
			win->Present();
			SDL_Delay(1);
		}
		
		SDL_Delay(400);

	}
	else if (deadstate == 2)
	{
		deadstate++;
		win->Draw(win->mPicture->wingCentered_90, 100, birdHeight - 13);
		win->Draw(win->mPicture->gameOver, 55, 60);
		win->Draw(win->mPicture->scoreCard, 35, 150);
		win->Draw(win->mPicture->restart, 35, 350);
		win->Draw(win->mPicture->ranking, 200, 350);
		SDL_Delay(400);
	}
	else if (deadstate == 3)
	{
		deadstate++;
		for (int i = 0; i <= score; i++)
		{
			win->Clear();
			if (daystate == 0)
				win->Draw(win->mPicture->background_day, 0, 0);
			else
				win->Draw(win->mPicture->background_night, 0, 0);
			rend_obstacle();
			rend_ground();
			win->Draw(win->mPicture->wingCentered_90, 100, birdHeight - 13);
			win->Draw(win->mPicture->gameOver, 55, 60);
			win->Draw(win->mPicture->scoreCard, 35, 150);
			win->Draw(win->mPicture->restart, 35, 350);
			win->Draw(win->mPicture->ranking, 200, 350);

			rend_score_S(271, 195, i);
			rend_score_S(271, 260, maxScore);
			win->Present();
			SDL_Delay(50);
		}
		SDL_Delay(400);
		if (score > 10)
			win->mMusic->wing->play();
	}
	else if (deadstate == 4)
	{
		if (daystate == 0)
			win->Draw(win->mPicture->background_day, 0, 0);
		else
			win->Draw(win->mPicture->background_night, 0, 0);
		rend_obstacle();
		rend_ground();
		win->Draw(win->mPicture->wingCentered_90, 100, birdHeight - 13);
		win->Draw(win->mPicture->gameOver, 55, 60);
		win->Draw(win->mPicture->scoreCard, 35, 150);
		win->Draw(win->mPicture->restart, 35, 350);
		win->Draw(win->mPicture->ranking, 200, 350);

		//判断显示奖牌
		if (score >= 10 && score < 15)
			win->Draw(win->mPicture->copper, 67, 205);
		if (score >= 15 && score < 30)
			win->Draw(win->mPicture->silver, 67, 205);
		if (score >= 30 && score < 50)
			win->Draw(win->mPicture->gold, 67, 205);
		if (score >= 50)
			win->Draw(win->mPicture->platinum, 67, 205);


		rend_score_S(271, 195, score);//写出分数
		rend_score_S(271, 260, maxScore);//打印出最高分数
	}
}

void Scene::rend_score_L(int x, int y)
{
	int i, n, dx, _score;
	dx = 35;
	_score = score;

	if (_score >= 0 && _score < 10)
		n = 1;
	else if (_score >= 10 && _score < 100)
		n = 2;
	else if (_score >= 100 && _score < 1000)
		n = 3;
	x = x + (n - 1)*(dx / 2);

	for (i = 0; i < n; i++)
	{
		switch (_score % 10)
		{
		case 0:
			win->Draw(win->mPicture->number0_L, x - i*dx, y);
			break;
		case 1:
			win->Draw(win->mPicture->number1_L, x - i*dx, y);
			break;
		case 2:
			win->Draw(win->mPicture->number2_L, x - i*dx, y);
			break;
		case 3:
			win->Draw(win->mPicture->number3_L, x - i*dx, y);
			break;
		case 4:
			win->Draw(win->mPicture->number4_L, x - i*dx, y);
			break;
		case 5:
			win->Draw(win->mPicture->number5_L, x - i*dx, y);
			break;
		case 6:
			win->Draw(win->mPicture->number6_L, x - i*dx, y);
			break;
		case 7:
			win->Draw(win->mPicture->number7_L, x - i*dx, y);
			break;
		case 8:
			win->Draw(win->mPicture->number8_L, x - i*dx, y);
			break;
		case 9:
			win->Draw(win->mPicture->number9_L, x - i*dx, y);
			break;
		default:
			break;
		}
		_score /= 10;
	}
}

void Scene::rend_score_S(int x, int y, int score)
{
	int i, n, dx, _score;
	dx = 21;
	_score = score;

	if (_score >= 0 && _score < 10)
		n = 1;
	else if (_score >= 10 && _score < 100)
		n = 2;
	else if (_score >= 100 && _score < 1000)
		n = 3;
	x = x + (n - 1)*(dx / 2);

	for (i = 0; i < n; i++)
	{
		switch (_score % 10)
		{
		case 0:
			win->Draw(win->mPicture->number0_S, x - i*dx, y);
			break;
		case 1:
			win->Draw(win->mPicture->number1_S, x - i*dx, y);
			break;
		case 2:
			win->Draw(win->mPicture->number2_S, x - i*dx, y);
			break;
		case 3:
			win->Draw(win->mPicture->number3_S, x - i*dx, y);
			break;
		case 4:
			win->Draw(win->mPicture->number4_S, x - i*dx, y);
			break;
		case 5:
			win->Draw(win->mPicture->number5_S, x - i*dx, y);
			break;
		case 6:
			win->Draw(win->mPicture->number6_S, x - i*dx, y);
			break;
		case 7:
			win->Draw(win->mPicture->number7_S, x - i*dx, y);
			break;
		case 8:
			win->Draw(win->mPicture->number8_S, x - i*dx, y);
			break;
		case 9:
			win->Draw(win->mPicture->number9_S, x - i*dx, y);
			break;
		default:
			break;
		}
		_score /= 10;
	}
}
