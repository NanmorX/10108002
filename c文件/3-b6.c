/* 1951559 ����� л���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int status;

	while (1) {
		printf("������x��ֵ[0-100] : ");
		status = scanf("%d", &x); //����x�ķ�ʽscanf�Ҹ�ʽ��Ϊ%d

		if (!status)
		{
			rewind(stdin);
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			//rewind(stdin);
			continue;
		}
	}

	printf("x=%d\n", x);

	return 0;
}