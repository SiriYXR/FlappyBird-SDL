#include "function.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void saveHiScore(int score)
{
	FILE *fp;
	fp = fopen("data\\Save\\score.txt", "w");	//��д�ķ�ʽ���ļ�
	if (fp)	//�򿪳ɹ�
	{
		fprintf(fp, "%d", score);	//����߷���д���ļ�
		fclose(fp);	//�ر��ļ�
	}
}

int readHiScore()
{
	FILE *fp;
	int score = 0;
	fp = fopen("data\\Save\\score.txt", "r");	//�Զ��ķ�ʽ���ļ�
	if (fp)	//�򿪳ɹ�
	{
		fscanf(fp, "%d", &score);	//����߷������ļ��ж���
		fclose(fp);	//�ر��ļ�
	}
	return score;
}

int Myrand(int max,int min)
{
	int num;
	srand((unsigned)time(NULL));//ѡȡ�����ļ�
	do
	{
		num = (int)rand() % max;
	} while (num < min || num > max);

	return num;
}
