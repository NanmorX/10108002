/* 1951559 ����� л���� */
#include <iostream>
using namespace std;

int min(int a, int b,int c=0xfffff,int d=0xfffff)
{
	if (a < b && a < c && a < d)
		return a;
	else if (b < a && b < c && b < d)
		return b;
	else if (c < a && c < b && c < d)
		return c;
	else
		return d;
}

int main()
{
	int n, a, b, c, d;
	bool flag = 0;
	cout << "���������num��num����������" << endl;
	while (1)
	{
		if (!flag)
			cin >> n;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			flag = 0;
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			cout << "���������num��num����������" << endl;
			continue;
		}
		if (flag)
			break;
		if ((n == 2 || n == 3 || n == 4) && (!flag))
		{
			if (n == 2)
				cin >> a >> b;
			else if (n == 3)
				cin >> a >> b >> c;
			else
				cin >> a >> b >> c >> d;
			flag = 1;
		}
		else
		{
			cin.ignore(10241024, '\n'); //��ջ�����
			cout << "�����������" << endl;
			return 0;
		}
	}
	if (n == 2)
		cout << "min=" << min(a, b) << endl;
	else if (n == 3)
		cout << "min=" << min(a, b, c) << endl;
	else
		cout << "min=" << min(a, b, c, d) << endl;
	return 0;
}