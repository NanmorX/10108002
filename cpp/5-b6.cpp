/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
using namespace std;

void zeller(int y, int m[12], int d)
{
	for (int i = 1; i <= 12; i++)
	{
		int year = y;
		int mon = i;
		int w, c;
		if (mon <= 2)
		{
			mon += 12;
			year--;
		}
		c = year / 100;
		year = year - c * 100;
		w = year + year / 4 + c / 4 - 2 * c + 13 * (mon + 1) / 5 + d - 1;
		w = (w + 7 * 1000) % 7;
		m[i-1] = w;
	}
}

void calendar(int y, int m[12])
{
	//��ʼ��
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		day[1] = 29;
	cout << y << "�������:" << endl;
	cout << endl;

	for (int i = 0; i < 12; i += 3)             //3����һ��
	{
		int k[3] = { 1,1,1 };                   //��ӡ��������
		cout << std::right;
		cout << setw(13) << i + 1 << "��" 
			 << setw(12 + 5 + 13) << i + 2 << "��" 
			 << setw(30) << i + 3 << "��" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		cout << setw(5) << " " << "Sun Mon Tue Wed Thu Fri Sat";
		cout << setw(5) << " " << "Sun Mon Tue Wed Thu Fri Sat";
		cout << endl;

		//������һ�����
		cout << std::left;
		for (int p = 0; p < 3; p++)
		{
			for (int j = 0; j < m[i+p]; j++)
			{
				cout << setw(4) << " ";
			}
			for (int j = m[i+p]; j < 7; j++, k[p]++)
			{
				cout << setw(4) << k[p];
			}
			if(p!=2)
				cout << setw(4) << " ";
		}
		cout << endl;

		//ÿ�߸��������
		while (k[0] <= day[i]|| k[1] <= day[i + 1]|| k[2] <= day[i + 2])
		{
			for (int p = 0; p < 3; p++)
			{
				int step = 0;
				for (; step < 7; step++)
				{
					if (k[p] > day[i+p])
						cout << setw(4) << " ";
					else
					{
						cout << setw(4) << k[p];
						k[p]++;
					}
				}
				if (p != 2)
					cout << setw(4) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return;
}

int main()
{
	system("mode con cols=120 lines=45");
	int y, m[13] = { 0 };

	//�õ���ݺ��·�
	while (1)
	{
		cout << "���������[1900-2100]" << endl;
		cin >> y;
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
		break;
	}

	zeller(y, m, 1);
	calendar(y, m);

	return 0;
}
