/* 1951559 ����� л���� */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int score[1005];
	int total[101];
	memset(total, 0, sizeof(total));
	cout << "������ɼ������1000��������-1����" << endl;
	cin >> score[0];
	while (score[0] < 0)
	{
		cout << "����Ч����" << endl;
		cin >> score[0];
	}
	int i = 1;
	while (1)
	{
		cin >> score[i];
		if (score[i] == -1)
		{
			i--;
			break;
		}
		i++;
	}
	cout << "���������Ϊ:" << endl;
	for (int j = 0; j <= i; j++)
	{
		cout << score[j] << " ";
		total[score[j]]++;
		if ((j + 1) % 10 == 0 || j == i)
			cout << endl;
	}
	cout << "�����������Ķ�Ӧ��ϵΪ:" << endl;
	for (int i = 100; i >= 0; i--)
	{
		if (total[i] != 0)
			cout << i << " " << total[i] << endl;
	}

	return 0;
}