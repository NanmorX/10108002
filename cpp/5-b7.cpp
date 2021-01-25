/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <cstring>
#include <cstdio>
#include <time.h>
using namespace std;

void bom(int map[10][26], int num)
{
	while (num)
	{
		int x = rand() % 10;
		int y = rand() % 26;
		if (map[x][y] != -1)
		{
			map[x][y] = -1;
			num--;
		}
	}
}

void mark(int map[10][26], int i, int j)
{
	if (i - 1 >= 0 && j - 1 >= 0 && map[i - 1][j - 1] != -1)
		map[i - 1][j - 1]++;
	if (i - 1 >= 0 && map[i - 1][j] != -1)
		map[i - 1][j]++;
	if (i - 1 >= 0 && j + 1 < 26 && map[i - 1][j + 1] != -1)
		map[i - 1][j + 1]++;
	if (j - 1 >= 0 && map[i][j - 1] != -1)
		map[i][j - 1]++;
	if (j + 1 < 26 && map[i][j + 1] != -1)
		map[i][j + 1]++;
	if (i + 1 < 10 && j - 1 >= 0 && map[i + 1][j - 1] != -1)
		map[i + 1][j - 1]++;
	if (i + 1 < 10 && map[i + 1][j] != -1)
		map[i + 1][j]++;
	if (i + 1 < 10 && j + 1 < 26 && map[i + 1][j + 1] != -1)
		map[i + 1][j + 1]++;
}

void cou(int map[10][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (map[i][j] == -1)
			{
				mark(map, i, j);
			}
		}
	}
	return;
}

void output(int map[10][26])
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (map[i][j] != -1)
				cout << map[i][j] << " ";
			else
				cout << "* ";
		}
		cout << endl;
	}
}

int main()
{
	srand((unsigned int)(time(0)));
	int map[10][26] = { 0 };
	/*for (int i = 0; i < 10; i++)
		for (int j = 0; j < 26; j++)
			map[i][j] = 0;*/
	//埋雷特殊化为-1
	//memset(map, 0, sizeof(map));
	bom(map, 50);
	cou(map);
	output(map);
	return 0;
}