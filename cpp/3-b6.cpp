/* 1951559 ����� л���� */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1)
	{
		cout << "������x��ֵ[0-100] : ";
		cin >> x;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			//cin.clear(); //���������
			//cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}

	cout << "x=" << x << endl;

	return 0;
}