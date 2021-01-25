/* 1951559 ����� л���� */
/* ����֤ 1954263 ��������1952219 ���Ȼ��1952553 �ų��ǡ�1950082 �����1953797 ��ʫ�� ��ɨ���ڲ����� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int mark(int map[10][26], int i, int j)
{
	if (map[i][j] < 0 || map[i][j]>8)
		return 0;
	int k=0;
	if (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] == -1)
		k++;
	if (i - 1 >= 0 && map[i - 1][j] == -1)
		k++;
	if (i - 1 >= 0 && j + 1 < 26 && map[i - 1][j + 1] == -1)
		k++;
	if (j - 1 >= 0 && map[i][j - 1] == -1)
		k++;
	if (j + 1 < 26 && map[i][j + 1] == -1)
		k++;
	if (i + 1 < 10 && j - 1 >= 0 && map[i + 1][j - 1] == -1)
		k++;
	if (i + 1 < 10 && map[i + 1][j] == -1)
		k++;
	if (i + 1 < 10 && j + 1 < 26 && map[i + 1][j + 1] == -1)
		k++;
	if (k == map[i][j])
		return 1;
	else
		return 0;
}

void check(int map[10][26])
{
	int num = 0;
	_Bool bo = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (map[i][j] == -1)
			{
				num++;
			}
			else
			{
				if (!mark(map, i, j))
				{
					bo = 0;
				}
			}
		}
	}
	if (num != 50)
		printf("����1\n");
	else if(bo==0)
		printf("����2\n");
	else
		printf("��ȷ\n");
	return;
}

void input(int map[10][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			char c;
			char temp;
			c = getchar();
			temp = getchar();
			if (j == 25)
				temp = getchar();
			if (c == '*')
				map[i][j] = -1;
			else
				map[i][j] = c - '0';
		}
	}
}

int main()
{
	int map[10][26];
	input(map);
	check(map);
	return 0;
}
