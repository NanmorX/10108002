/* 1951559 ����� л���� */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "������[0-100��)֮������֣�" << endl;
	double k, precious = 0.0, inter = 0;
	cin >> k;
	precious = modf(k, &inter);             //�ֽ��������ֺ�С������
	long long k1;
	k1 = static_cast<long long> (inter);    //ǿ������ת��

	//��������
	long long a;
	a = k1 / 1000000000;
	cout << "ʮ��λ : " << a << endl;
	k1 = k1 - a * 1000000000;
	a = k1 / 100000000;
	cout << "��λ   : " << a << endl;
	k1 = k1 - a * 100000000;
	a = k1 / 10000000;
	cout << "ǧ��λ : " << a << endl;
	k1 = k1 - a * 10000000;
	a = k1 / 1000000;
	cout << "����λ : " << a << endl;
	k1 = k1 - a * 1000000;
	a = k1 / 100000;
	cout << "ʮ��λ : " << a << endl;
	k1 = k1 - a * 100000;
	a = k1 / 10000;
	cout << "��λ   : " << a << endl;
	k1 = k1 - a * 10000;
	a = k1 / 1000;
	cout << "ǧλ   : " << a << endl;
	k1 = k1 - a * 1000;
	a = k1 / 100;
	cout << "��λ   : " << a << endl;
	k1 = k1 - a * 100;
	a = k1 / 10;
	cout << "ʮλ   : " << a << endl;
	k1 = k1 - a * 10;
	a = k1 / 1;
	cout << "Բ     : " << a << endl;

	//С������
	long long k2;
	k2 = static_cast<long long>(precious * 1000) + 1;      //����double���͵Ĵ洢��+1
	k2 /= 10;
	a = k2 / 10;
	cout << "��     : " << a << endl;
	k2 = k2 - a * 10;
	a = k2 / 1;
	cout << "��     : " << a << endl;

	return 0;
}