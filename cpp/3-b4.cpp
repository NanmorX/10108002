/* 1951559 ����� л���� */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "������[0-100��)֮������֣�" << endl;
	double k, precious = 0.0, inter = 0;
	cin >> k;

	//����õ�ÿһλ��ֵ
	precious = modf(k, &inter);
	long long k1,k2;
	k1 = static_cast<long long> (inter);
	k2 = static_cast<long long> (precious*1000) + 1;
	k2 /= 10;
	long long a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
	long long b0, b1;
	a9 = k1 / 1000000000;
	k1 = k1 - a9 * 1000000000;
	a8 = k1 / 100000000;
	k1 = k1 - a8 * 100000000;
	a7 = k1 / 10000000;
	k1 = k1 - a7 * 10000000;
	a6 = k1 / 1000000;
	k1 = k1 - a6 * 1000000;
	a5 = k1 / 100000;
	k1 = k1 - a5 * 100000;
	a4= k1 / 10000;
	k1 = k1 - a4 * 10000;
	a3 = k1 / 1000;
	k1 = k1 - a3 * 1000;
	a2 = k1 / 100;
	k1 = k1 - a2 * 100;
	a1 = k1 / 10;
	k1 = k1 - a1 * 10;
	a0 = k1 / 1;
	b1 = k2 / 10;
	k2 = k2 - b1 * 10;
	b0 = k2 / 1;
	
	//�������
	if (!a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1 && !a0 && !b1 && !b0)
	{
		cout << "��Բ��" << endl;
		return 0;
	}

	//��Ԫ����
	bool ifzero = 1,ifzero1 = 1;              //ifzero:ǰ���Ƿ���ڷ�������ifzero1��ǰһλ�Ƿ�Ϊ0
	if (a9 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a9)
		{
			case 9:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			default:
				break;
		}
	}
	if (a8 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a8)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 7:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			cout << "��";
			ifzero1 = 1;
		}
	}

	//�ָ���
	//��Ԫ����
	if (a7 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a7)
		{
			case 9:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 1:
				cout << "ҼǪ";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			if (a6!=0||a5!=0||a4!=0)
			{
				cout << "��";
			}
			ifzero1 = 1;
		}
	}
	if (a6 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a6)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && (a5 !=0 || a4!=0))
		{
			cout << "��";
			ifzero1 = 1;
		}
	}
	if (a5 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a5)
		{
			case 9:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && a4!=0)
		{
			cout << "��";
			ifzero1 = 1;
		}
	}
	if (a4 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a4)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "����";
				break;
			case 7:
				cout << "����";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "����";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			default:
				break;
		}
	}
	else
	{
		if(a5!=0||a6!=0||a7!=0)
			cout << "��";
	}

	//�ָ���
	if (a3 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a3)
		{
			case 9:
				cout << "��Ǫ";
				break;
			case 8:
				cout << "��Ǫ";
				break;
			case 7:
				cout << "��Ǫ";
				break;
			case 6:
				cout << "½Ǫ";
				break;
			case 5:
				cout << "��Ǫ";
				break;
			case 4:
				cout << "��Ǫ";
				break;
			case 3:
				cout << "��Ǫ";
				break;
			case 2:
				cout << "��Ǫ";
				break;
			case 1:
				cout << "ҼǪ";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero )
		{
			if (a2 != 0 || a1 != 0 || a0 != 0)
			{
				cout << "��";
			}
			ifzero1 = 1;
		}
	}
	if (a2 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a2)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�ư�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && (a1 !=0 || a0!=0))
		{
			cout << "��";
			ifzero1 = 1;
		}
	}
	if (a1 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a1)
		{
			case 9:
				cout << "��ʰ";
				break;
			case 8:
				cout << "��ʰ";
				break;
			case 7:
				cout << "��ʰ";
				break;
			case 6:
				cout << "½ʰ";
				break;
			case 5:
				cout << "��ʰ";
				break;
			case 4:
				cout << "��ʰ";
				break;
			case 3:
				cout << "��ʰ";
				break;
			case 2:
				cout << "��ʰ";
				break;
			case 1:
				cout << "Ҽʰ";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && a0!=0)
		{
			cout << "��";
			ifzero1 = 1;
		}
	}
	if (a0 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a0)
		{
			case 9:
				cout << "��Բ";
				break;
			case 8:
				cout << "��Բ";
				break;
			case 7:
				cout << "��Բ";
				break;
			case 6:
				cout << "½Բ";
				break;
			case 5:
				cout << "��Բ";
				break;
			case 4:
				cout << "��Բ";
				break;
			case 3:
				cout << "��Բ";
				break;
			case 2:
				cout << "��Բ";
				break;
			case 1:
				cout << "ҼԲ";
				break;
			default:
				break;
		}
	}
	else
	{
		if(a9||a8||a7||a6||a5||a4||a3||a2||a1)
			cout << "Բ";
	}
	
	//�ָ���
	if (b1 == 0 && b0 == 0)
	{
		cout << "��" << endl;
		return 0;
	}
	if (b1 != 0)
	{
		
		ifzero = 0;
		ifzero1 = 0;
		switch (b1)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�ƽ�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero1)
			cout << "��";
	}
	if (b0 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (b0)
		{
			case 9:
				cout << "����";
				break;
			case 8:
				cout << "�Ʒ�";
				break;
			case 7:
				cout << "���";
				break;
			case 6:
				cout << "½��";
				break;
			case 5:
				cout << "���";
				break;
			case 4:
				cout << "����";
				break;
			case 3:
				cout << "����";
				break;
			case 2:
				cout << "����";
				break;
			case 1:
				cout << "Ҽ��";
				break;
			default:
				break;
		}
	}
	else
	{
		if (!ifzero1)
			cout << "��" << endl;
	}
	cout << endl;

	return 0;
}