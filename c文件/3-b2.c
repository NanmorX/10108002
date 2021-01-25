/* 1951559 计算机 谢佳依 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("请输入[0-100亿)之间的数字：\n");
	double k, precious = 0.0, inter = 0;
	scanf("%lf", &k);
	precious = modf(k, &inter);
	long long k1;
	k1 = (long long)(inter);

	long long a;
	a = k1 / 1000000000;
	printf("十亿位 : %lld\n", a);
	k1 = k1 - a * 1000000000;
	a = k1 / 100000000;
	printf("亿位   : %lld\n", a);
	k1 = k1 - a * 100000000;
	a = k1 / 10000000;
	printf("千万位 : %lld\n", a);
	k1 = k1 - a * 10000000;
	a = k1 / 1000000;
	printf("百万位 : %lld\n",a);
	k1 = k1 - a * 1000000;
	a = k1 / 100000;
	printf("十万位 : %lld\n",a);
	k1 = k1 - a * 100000;
	a = k1 / 10000;
	printf("万位   : %lld\n", a);
	k1 = k1 - a * 10000;
	a = k1 / 1000;
	printf("千位   : %lld\n", a);
	k1 = k1 - a * 1000;
	a = k1 / 100;
	printf("百位   : %lld\n", a);
	k1 = k1 - a * 100;
	a = k1 / 10;
	printf("个位   : %lld\n", a);
	k1 = k1 - a * 10;
	a = k1 / 1;
	printf("圆     : %lld\n", a);

	long long k2;
	k2 = (long long)(precious * 1000) + 1;
	k2 /= 10;
	a = k2 / 10;
	printf("角     : %lld\n", a);
	k2 = k2 - a * 10;
	a = k2 / 1;
	printf("分     : %lld\n", a);

	return 0;
}
