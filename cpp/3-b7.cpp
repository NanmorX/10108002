/* 1951559 ����� л���� */
#include <iostream>
using namespace std;

int main()
{
	int y, m, d;
	//�õ���ݺ��·�
	while (1)
	{
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> y >> m;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		else
		{
			cout << "����Ƿ�������������" << endl;
			//cin.clear(); //���������
			//cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}

	//�õ�����
	while (1)
	{
		cout << "������" << y << "��" << m << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> d;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			cout << "����Ƿ�������������" << endl;
			continue;
		}
		if (d >= 0 && d <= 6)
			break;
		else
		{
			cout << "����Ƿ�������������" << endl;
			//cin.clear(); //���������
			//cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}

	cout << endl;
	cout << y << "��" << m << "�µ�����Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;

	int k = 1;
	int daymax;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		daymax = 31;
	}
	else
	{
		daymax = 30;
	}
	if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			daymax = 29;
		else
			daymax = 28;
	}

	//������һ�����
	for (int i = 0; i < d; i++)
	{
		cout << "        ";
	}
	for (int i = d; i < 7; i++, k++)
	{
		cout << "   " << k << "    ";
	}
	cout << endl;

	//ÿ�߸��������
	while (k <= daymax)
	{
		if (k < 10)
			cout << "   " << k << "    ";
		else
			cout << "  " << k << "    ";

		k++;
		if ((k - 7 + d - 1) % 7 == 0)
			cout << endl;
	}
	cout << endl;

	return 0;
}
