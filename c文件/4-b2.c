/* 1951559 ����� л���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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

int main()
{
	int y, m, d;
	while (1)
	{
		int status;
		printf("��������[1900-2100]���¡��գ�\n");
		status = scanf("%d %d %d", &y, &m, &d);
		if (!status)  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			printf("�����������������\n");
			rewind(stdin);
			continue;
		}
		if (!(y >= 1900 && y <= 2100))
		{
			printf("��ݲ���ȷ������������\n");
			continue;
		}
		if (!(m <= 12 && m >= 1))
		{
			printf("�·ݲ���ȷ������������\n");
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
			printf("�ղ���ȷ������������\n");
			continue;
		}
		break;
	}
	int w = zeller(y, m, d);
	switch (w)
	{
		case 0:
			printf("������\n");
			break;
		case 1:
			printf("����һ\n");
			break;
		case 2:
			printf("���ڶ�\n");
			break;
		case 3:
			printf("������\n");
			break;
		case 4:
			printf("������\n");
			break;
		case 5:
			printf("������\n");
			break;
		case 6:
			printf("������\n");
			break;
	}

	return 0;
}