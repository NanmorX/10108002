/*1951559 ����� л����*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("����������ֵ�� \n");
	double k, precious = 0.0, inter = 0;
	int sum = 0;
	scanf("%lf",&k);
	precious = modf(k, &inter);
	int k1, k2, a;
	k1 = (int)(inter);
	k2 = (int)(precious * 1000) + 1;
	k2 /= 10;

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
	
	printf("����%d�����㣬�������£�\n", sum);

	k1 = (int)(inter);
	k2 = (int)(precious * 1000) + 1;
	k2 /= 10;
	a = k1 / 50;
	if (a != 0)
		printf("50Ԫ : %d��\n", a);
	k1 = k1 - a * 50;
	a = k1 / 20;
	if (a != 0)
		printf("20Ԫ : %d��\n", a);
	k1 = k1 - a * 20;
	a = k1 / 10;
	if (a != 0)
		printf("10Ԫ : %d��\n", a);
	k1 = k1 - a * 10;
	a = k1 / 5;
	if (a != 0)
		printf("5Ԫ  : %d��\n", a);
	k1 = k1 - a * 5;
	a = k1 / 1;
	if (a != 0)
		printf("1Ԫ  : %d��\n", a);
	a = k2 / 50;
	if (a != 0)
		printf("5��  : %d��\n", a);
	k2 = k2 - a * 50;
	a = k2 / 10;
	if (a != 0)
		printf("1��  : %d��\n", a);
	k2 = k2 - a * 10;
	a = k2 / 5;
	if (a != 0)
		printf("5��  : %d��\n", a);
	k2 = k2 - a * 5;
	a = k2 / 2;
	if (a != 0)
		printf("2��  : %d��\n", a);
	k2 = k2 - a * 2;
	a = k2 / 1;
	if (a != 0)
		printf("1��  : %d��\n", a);

	return 0;
}