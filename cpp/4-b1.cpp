/* 1951559 ����� л���� */
#include <iostream>
#include <cmath>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
	cout << "������[0-100��)֮������֣�" << endl;
	double k, precious = 0.0, inter = 0;
	cin >> k;

	//����õ�ÿһλ��ֵ
	precious = modf(k, &inter);
	long long k1, k2;                                //k1�������֣�k2С������ 
	k1 = static_cast<long long> (inter);
	k2 = static_cast<long long> (precious * 1000) + 1;
	k2 /= 10;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
	int b0, b1;
	a9 = static_cast<int>(k1 / 1000000000);
	k1 = k1 - static_cast<long long>(a9) * 1000000000;
	a8 = static_cast<int>(k1 / 100000000);
	k1 = k1 - static_cast<long long>(a8) * 100000000;
	a7 = static_cast<int>(k1 / 10000000);
	k1 = k1 - static_cast<long long>(a7) * 10000000;
	a6 = static_cast<int>(k1 / 1000000);
	k1 = k1 - static_cast<long long>(a6) * 1000000;
	a5 = static_cast<int>(k1 / 100000);
	k1 = k1 - static_cast<long long>(a5) * 100000;
	a4 = static_cast<int>(k1 / 10000);
	k1 = k1 - static_cast<long long>(a4) * 10000;
	a3 = static_cast<int>(k1 / 1000);
	k1 = k1 - static_cast<long long>(a3) * 1000;
	a2 = static_cast<int>(k1 / 100);
	k1 = k1 - static_cast<long long>(a2) * 100;
	a1 = static_cast<int>(k1 / 10);
	k1 = k1 - static_cast<long long>(a1) * 10;
	a0 = static_cast<int>(k1 / 1);

	b1 = static_cast<int>(k2) / 10;
	k2 = k2 - static_cast<long long>(b1) * 10;
	b0 = static_cast<int>(k2) / 1;

	if (!a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1 && !a0 && !b1 && !b0)
	{
		daxie(0, 1);
		cout << "Բ��" << endl;
		return 0;
	}
	
	daxie(a9,0);
	if (a9 != 0)
	{
		cout << "ʰ";
	}
	daxie(a8, 0);
	if (a8+a9 != 0)
	{
		cout << "��";
	}


	daxie(a7, (a8 + a9 != 0)&&(a6 + a5 + a4 != 0));
	if (a7 != 0)
	{
		cout << "Ǫ";
	}
	daxie(a6,a7 && a5+a4!=0 );
	if (a6 != 0)
	{
		cout << "��";
	}
	daxie(a5, a4 && a6);
	if (a5 != 0)
	{
		cout << "ʰ";
	}
	daxie(a4, 0);
	if (a7+a6+a5+a4)
	{
		cout << "��";
	}


	daxie(a3, (a2 + a1 + a0) && (a9 + a8 + a7 + a6 + a5 + a4));
	if (a3 != 0)
	{
		cout << "Ǫ";
	}
	daxie(a2, a3 && a1 + a0 != 0);
	if (a2 != 0)
	{
		cout << "��";
	}
	daxie(a1, a2 && a0);
	if (a1 != 0)
	{
		cout << "ʰ";
	}
	daxie(a0, 0);
	if (a0 != 0 || a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1)
	{
		cout << "Բ";
	}


	//�ָ���
	if (b1 == 0 && b0 == 0)
	{
		cout << "��" << endl;
		return 0;
	}
	daxie(b1, a9+a8+a7+a6+a5+a4+a3+a2+a1+a0);
	if (b1 != 0)
	{
		cout << "��";
	}
	daxie(b0, 0);
	if (b0 != 0)
	{
		cout << "��";
	}
	else
	{
		if (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0 + b1)
			cout << "��" ;
	}
	cout << endl;

	return 0;
}
