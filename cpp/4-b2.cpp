/* 1951559 ����� л���� */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	int w,c;
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

int main()
{
	int y, m, d;
	while (1)
	{
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> y >> m >> d;
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
		if(!(m<=12&&m>=1))
		{
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
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
		if (!(d >= 1 && d <= daymax))
		{
			cout << "�ղ���ȷ������������" << endl;
			continue;
		}
		break;
	}
	int w = zeller(y,m,d);
	switch (w)
	{
		case 0:
			cout << "������" << endl;
			break;
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
	}

	return 0;
}