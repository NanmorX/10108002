/* 1951559 ����� л���� */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "����������ֵ�� " << endl;
	double k, precious = 0.0, inter = 0;
	int sum = 0;
	cin >> k;
	precious = modf(k, &inter);
	int k1,k2,a;
	k1 = static_cast<int>(inter);
	k2 = static_cast<int>(precious * 1000) + 1;
	k2 /= 10;

	//����д�ķ���ʮ���޴�����ʵ�����ұ����洢�������Ͳ�����ִ��һ��
	a = k1 / 50;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 50;
	a = k1 / 20;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 20;
	a = k1 / 10;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 10;
	a = k1 / 5;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 5;
	a = k1 / 1;
	if (a != 0) 
		sum += a;
	a = k2 / 50;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 50;
	a = k2 / 10;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 10;
	a = k2 / 5;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 5;
	a = k2 / 2;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 2;
	a = k2 / 1;
	if (a != 0) 
		sum += a;

	cout << "����" << sum << "�����㣬�������£�" << endl;
	k1 = static_cast<int>(inter);
	k2 = static_cast<int>(precious * 1000) + 1;
	k2 /= 10;
	a = k1 / 50;
	if (a != 0)
		cout << "50Ԫ : " << a << "��" << endl;
	k1 = k1 - a * 50;
	a = k1 / 20;
	if (a != 0) 
		cout << "20Ԫ : " << a << "��" << endl;
	k1 = k1 - a * 20;
	a = k1 / 10;
	if (a != 0) 
		cout << "10Ԫ : " << a << "��" << endl;
	k1 = k1 - a * 10;
	a = k1 / 5;
	if (a != 0) 
		cout << "5Ԫ  : " << a << "��" << endl;
	k1 = k1 - a * 5;
	a = k1 / 1;
	if (a != 0) 
		cout << "1Ԫ  : " << a << "��" << endl;
	a = k2 / 50;
	if (a != 0)
		cout << "5��  : " << a << "��" << endl;
	k2 = k2 - a * 50;
	a = k2 / 10;
	if (a != 0) 
		cout << "1��  : " << a << "��" << endl;
	k2 = k2 - a * 10;
	a = k2 / 5;
	if (a != 0) 
		cout << "5��  : " << a << "��" << endl;
	k2 = k2 - a * 5;
	a = k2 / 2;
	if (a != 0) 
		cout << "2��  : " << a << "��" << endl;
	k2 = k2 - a * 2;
	a = k2 / 1;
	if (a != 0) 
		cout << "1��  : " << a << "��" << endl;

	return 0;
}