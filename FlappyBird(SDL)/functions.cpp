#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void saveHiScore(int score)
{
	FILE *fp;
	fp = fopen("data\\Save\\score.txt", "w");	//以写的方式打开文件
	if (fp)	//打开成功
	{
		fprintf(fp, "%d", score);	//将最高分数写入文件
		fclose(fp);	//关闭文件
	}
}

int readHiScore()
{
	FILE *fp;
	int score = 0;
	fp = fopen("data\\Save\\score.txt", "r");	//以读的方式打开文件
	if (fp)	//打开成功
	{
		fscanf(fp, "%d", &score);	//将最高分数从文件中读出
		fclose(fp);	//关闭文件
	}
	return score;
}

int Myrand(int max,int min)
{
	int num;
	srand((unsigned)time(NULL));//选取种子文件
	do
	{
		num = (int)rand() % max;
	} while (num < min || num > max);

	return num;
}
