/*1951559 ����� л����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("������[0-100��)֮������֣�\n");
	double k, precious = 0.0, inter = 0;
	scanf("%lf",&k);

	//����õ�ÿһλ��ֵ
	precious = modf(k, &inter);
	long long k1, k2;
	k1 = (long long)(inter);
	k2 = (long long)(precious * 1000) + 1;
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
	a4 = k1 / 10000;
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
		printf("��Բ��\n");
		return 0;
	}

	//��Ԫ����
	_Bool ifzero = 1, ifzero1 = 1;              //ifzero:ǰ���Ƿ���ڷ�������ifzero1��ǰһλ�Ƿ�Ϊ0
	if (a9 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a9)
		{
			case 9:
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 1:
				printf("Ҽʰ");
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
				printf("����");
				break;
			case 8:
				printf("����");
				break;
			case 7:
				printf("����");
				break;
			case 6:
				printf("½��");
				break;
			case 5:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 2:
				printf("����");
				break;
			case 1:
				printf("Ҽ��");
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			printf("��");
			ifzero1 = 1;
		}
	}

	//�ָ���
	if (a7 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a7)
		{
			case 9:
				printf("��Ǫ");
				break;
			case 8:
				printf("��Ǫ");
				break;
			case 7:
				printf("��Ǫ");
				break;
			case 6:
				printf("½Ǫ");
				break;
			case 5:
				printf("��Ǫ");
				break;
			case 4:
				printf("��Ǫ");
				break;
			case 3:
				printf("��Ǫ");
				break;
			case 2:
				printf("��Ǫ");
				break;
			case 1:
				printf("ҼǪ");
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			if (a6 != 0 || a5 != 0 || a4 != 0)
			{
				printf("��");
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
				printf("����");
				break;
			case 8:
				printf("�ư�");
				break;
			case 7:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 5:
				printf("���");
				break;
			case 4:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 2:
				printf("����");
				break;
			case 1:
				printf("Ҽ��");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && (a5 != 0 || a4 != 0))
		{
			printf("��");
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
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 1:
				printf("Ҽʰ");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && a4 != 0)
		{
			printf("��");
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
				printf("����");
				break;
			case 8:
				printf("����");
				break;
			case 7:
				printf("����");
				break;
			case 6:
				printf("½��");
				break;
			case 5:
				printf("����");
				break;
			case 4:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 2:
				printf("����");
				break;
			case 1:
				printf("Ҽ��");
				break;
		}
	}
	else
	{
		if (a5 != 0 || a6 != 0 || a7 != 0)
			printf("��");
	}

	//�ָ���
	if (a3 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a3)
		{
			case 9:
				printf("��Ǫ");
				break;
			case 8:
				printf("��Ǫ");
				break;
			case 7:
				printf("��Ǫ");
				break;
			case 6:
				printf("½Ǫ");
				break;
			case 5:
				printf("��Ǫ");
				break;
			case 4:
				printf("��Ǫ");
				break;
			case 3:
				printf("��Ǫ");
				break;
			case 2:
				printf("��Ǫ");
				break;
			case 1:
				printf("ҼǪ");
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			if (a2 != 0 || a1 != 0 || a0 != 0)
			{
				printf("��");
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
				printf("����");
				break;
			case 8:
				printf("�ư�");
				break;
			case 7:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 5:
				printf("���");
				break;
			case 4:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 2:
				printf("����");
				break;
			case 1:
				printf("Ҽ��");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && (a1 != 0 || a0 != 0))
		{
			printf("��");
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
				printf("��ʰ");
				break;
			case 8:
				printf("��ʰ");
				break;
			case 7:
				printf("��ʰ");
				break;
			case 6:
				printf("½ʰ");
				break;
			case 5:
				printf("��ʰ");
				break;
			case 4:
				printf("��ʰ");
				break;
			case 3:
				printf("��ʰ");
				break;
			case 2:
				printf("��ʰ");
				break;
			case 1:
				printf("Ҽʰ");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && a0 != 0)
		{
			printf("��");
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
				printf("��Բ");
				break;
			case 8:
				printf("��Բ");
				break;
			case 7:
				printf("��Բ");
				break;
			case 6:
				printf("½Բ");
				break;
			case 5:
				printf("��Բ");
				break;
			case 4:
				printf("��Բ");
				break;
			case 3:
				printf("��Բ");
				break;
			case 2:
				printf("��Բ");
				break;
			case 1:
				printf("ҼԲ");
				break;
		}
	}
	else
	{
		if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1)
			printf("Բ");
	}

	//�ָ���
	if (b1 == 0 && b0 == 0)
	{
		printf("��\n");
		return 0;
	}
	if (b1 != 0)
	{

		ifzero = 0;
		ifzero1 = 0;
		switch (b1)
		{
			case 9:
				printf("����");
				break;
			case 8:
				printf("�ƽ�");
				break;
			case 7:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 5:
				printf("���");
				break;
			case 4:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 2:
				printf("����");
				break;
			case 1:
				printf("Ҽ��");
				break;
		}
	}
	else
	{
		if (!ifzero1)
			printf("��");
	}
	if (b0 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (b0)
		{
			case 9:
				printf("����");
				break;
			case 8:
				printf("�Ʒ�");
				break;
			case 7:
				printf("���");
				break;
			case 6:
				printf("½��");
				break;
			case 5:
				printf("���");
				break;
			case 4:
				printf("����");
				break;
			case 3:
				printf("����");
				break;
			case 2:
				printf("����");
				break;
			case 1:
				printf("Ҽ��");
				break;
		}
	}
	else
	{
		if (!ifzero1)
			printf("��\n");
	}

	return 0;
}