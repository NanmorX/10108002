/* 1951559 ����� л���� */
#include <iostream>
using namespace std;

//���뺯��
void input(int map[9][9])
{
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			int a;
			while (1)
			{
				cin >> a;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(65536, '\n');
					cout << "�����������"<<i+1<<"��"<<j+1<<"��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				else if (a >= 1 && a <= 9)
				{
					map[i][j] = a;
					break;
				}
				else
				{
					cout << "�����������"<<i+1<<"��"<<j+1<<"��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
			}
		}
	}
	return ;
}

//����Ƿ��������Ľ�
int check(int map[9][9])
{
	for (int i = 0; i < 9; i++)
	{
		int bo[9] = { 0,0,0,0,0,0,0,0,0 };
		for (int j = 0; j < 9; j++)
		{
			if (bo[map[i][j]-1])
				return 0;
			bo[map[i][j]-1] = 1;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		int bo[9] = { 0,0,0,0,0,0,0,0,0 };
		for (int j = 0; j < 9; j++)
		{
			if (bo[map[j][i]-1])
				return 0;
			bo[map[j][i]-1] = 1;
		}
	}
	for (int i = 0; i < 9; i+=3)
	{
		int bo[9] = { 0,0,0,0,0,0,0,0,0 };
		for (int j = 0; j < 9; j+=3)
		{
			if (bo[map[i][j]-1] || bo[map[i][j + 1]-1] || bo[map[i][j + 2]-1])
				return 0;
			bo[map[i][j]-1] = 1;
			bo[map[i][j+1]-1] = 1;
			bo[map[i][j+2]-1] = 1;
		}
	}
	return 1;
}

int main()
{
	int map[9][9];
	input(map);
	if (check(map))
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;
	return 0;
}
/*
5 1 6 2 7 4 3 9 8
7 9 3 5 6 8 4 1 2
8 2 4 3 9 1 7 6 5
4 5 1 6 3 7 2 8 9
3 7 2 1 8 9 6 5 4
9 6 8 4 5 2 1 3 7 
2 3 5 8 4 6 9 7 1
6 4 9 7 1 5 8 2 3
1 8 7 9 2 3 5 4 6
*/