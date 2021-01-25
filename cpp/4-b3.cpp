/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	int w, c;
	if (m <= 2)
	{
		m += 12;
		y--;
	}
	c = y / 100;
	y = y - c * 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	w = (w + 7 * 1000) % 7;
	return w;
}

void calendar(int y,int m, int w)
{
	cout << endl;
	cout << y << "��" << m << "��" << endl;
	cout << setfill('=') << setw(54) << "=" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << setfill('=') << setw(54) << "=" << endl;

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
	for (int i = 0; i < w; i++)
	{
		cout << setw(8) << " ";
	}
	for (int i = w; i < 7; i++, k++)
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
		if ((k - 7 + w - 1) % 7 == 0)
			cout << endl;
	}
	cout << endl;
}

int main()
{
	int y, m;
	//�õ���ݺ��·�
	while (1)
	{
		cout << "��������[1900-2100]����" << endl;
		cin >> y >> m ;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cout << "�����������������" << endl;
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
		if (!(y >= 1900 && y <= 2100))
		{
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		if (!(m <= 12 && m >= 1))
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		break;
	}
	int w = zeller(y, m, 1);
	calendar(y, m, w);
	return 0;
}
