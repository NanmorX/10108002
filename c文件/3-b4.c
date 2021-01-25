/*1951559 ¼ÆËã»ú Ð»¼ÑÒÀ*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö£º\n");
	double k, precious = 0.0, inter = 0;
	scanf("%lf",&k);

	//¼ÆËãµÃµ½Ã¿Ò»Î»µÄÖµ
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

	//·ÖÀàÊä³ö
	if (!a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1 && !a0 && !b1 && !b0)
	{
		printf("ÁãÔ²Õû\n");
		return 0;
	}

	//ÒÚÔª²¿·Ö
	_Bool ifzero = 1, ifzero1 = 1;              //ifzero:Ç°ÃæÊÇ·ñ´æÔÚ·ÇÁãÊý£¬ifzero1£ºÇ°Ò»Î»ÊÇ·ñÎª0
	if (a9 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a9)
		{
			case 9:
				printf("¾ÁÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 1:
				printf("Ò¼Ê°");
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
				printf("¾ÁÒÚ");
				break;
			case 8:
				printf("°ÆÒÚ");
				break;
			case 7:
				printf("ÆâÒÚ");
				break;
			case 6:
				printf("Â½ÒÚ");
				break;
			case 5:
				printf("ÎéÒÚ");
				break;
			case 4:
				printf("ËÁÒÚ");
				break;
			case 3:
				printf("ÈþÒÚ");
				break;
			case 2:
				printf("·¡ÒÚ");
				break;
			case 1:
				printf("Ò¼ÒÚ");
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			printf("ÒÚ");
			ifzero1 = 1;
		}
	}

	//·Ö¸îÏß
	if (a7 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a7)
		{
			case 9:
				printf("¾ÁÇª");
				break;
			case 8:
				printf("°ÆÇª");
				break;
			case 7:
				printf("ÆâÇª");
				break;
			case 6:
				printf("Â½Çª");
				break;
			case 5:
				printf("ÎéÇª");
				break;
			case 4:
				printf("ËÁÇª");
				break;
			case 3:
				printf("ÈþÇª");
				break;
			case 2:
				printf("·¡Çª");
				break;
			case 1:
				printf("Ò¼Çª");
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			if (a6 != 0 || a5 != 0 || a4 != 0)
			{
				printf("Áã");
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
				printf("¾Á°Û");
				break;
			case 8:
				printf("°Æ°Û");
				break;
			case 7:
				printf("Æâ°Û");
				break;
			case 6:
				printf("Â½°Û");
				break;
			case 5:
				printf("Îé°Û");
				break;
			case 4:
				printf("ËÁ°Û");
				break;
			case 3:
				printf("Èþ°Û");
				break;
			case 2:
				printf("·¡°Û");
				break;
			case 1:
				printf("Ò¼°Û");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && (a5 != 0 || a4 != 0))
		{
			printf("Áã");
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
				printf("¾ÁÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 1:
				printf("Ò¼Ê°");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && a4 != 0)
		{
			printf("Áã");
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
				printf("¾ÁÍò");
				break;
			case 8:
				printf("°ÆÍò");
				break;
			case 7:
				printf("ÆâÍò");
				break;
			case 6:
				printf("Â½Íò");
				break;
			case 5:
				printf("ÎéÍò");
				break;
			case 4:
				printf("ËÁÍò");
				break;
			case 3:
				printf("ÈþÍò");
				break;
			case 2:
				printf("·¡Íò");
				break;
			case 1:
				printf("Ò¼Íò");
				break;
		}
	}
	else
	{
		if (a5 != 0 || a6 != 0 || a7 != 0)
			printf("Íò");
	}

	//·Ö¸îÏß
	if (a3 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (a3)
		{
			case 9:
				printf("¾ÁÇª");
				break;
			case 8:
				printf("°ÆÇª");
				break;
			case 7:
				printf("ÆâÇª");
				break;
			case 6:
				printf("Â½Çª");
				break;
			case 5:
				printf("ÎéÇª");
				break;
			case 4:
				printf("ËÁÇª");
				break;
			case 3:
				printf("ÈþÇª");
				break;
			case 2:
				printf("·¡Çª");
				break;
			case 1:
				printf("Ò¼Çª");
				break;
		}
	}
	else
	{
		if (!ifzero)
		{
			if (a2 != 0 || a1 != 0 || a0 != 0)
			{
				printf("Áã");
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
				printf("¾Á°Û");
				break;
			case 8:
				printf("°Æ°Û");
				break;
			case 7:
				printf("Æâ°Û");
				break;
			case 6:
				printf("Â½°Û");
				break;
			case 5:
				printf("Îé°Û");
				break;
			case 4:
				printf("ËÁ°Û");
				break;
			case 3:
				printf("Èþ°Û");
				break;
			case 2:
				printf("·¡°Û");
				break;
			case 1:
				printf("Ò¼°Û");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && (a1 != 0 || a0 != 0))
		{
			printf("Áã");
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
				printf("¾ÁÊ°");
				break;
			case 8:
				printf("°ÆÊ°");
				break;
			case 7:
				printf("ÆâÊ°");
				break;
			case 6:
				printf("Â½Ê°");
				break;
			case 5:
				printf("ÎéÊ°");
				break;
			case 4:
				printf("ËÁÊ°");
				break;
			case 3:
				printf("ÈþÊ°");
				break;
			case 2:
				printf("·¡Ê°");
				break;
			case 1:
				printf("Ò¼Ê°");
				break;
		}
	}
	else
	{
		if (!ifzero && !ifzero1 && a0 != 0)
		{
			printf("Áã");
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
				printf("¾ÁÔ²");
				break;
			case 8:
				printf("°ÆÔ²");
				break;
			case 7:
				printf("ÆâÔ²");
				break;
			case 6:
				printf("Â½Ô²");
				break;
			case 5:
				printf("ÎéÔ²");
				break;
			case 4:
				printf("ËÁÔ²");
				break;
			case 3:
				printf("ÈþÔ²");
				break;
			case 2:
				printf("·¡Ô²");
				break;
			case 1:
				printf("Ò¼Ô²");
				break;
		}
	}
	else
	{
		if (a9 || a8 || a7 || a6 || a5 || a4 || a3 || a2 || a1)
			printf("Ô²");
	}

	//·Ö¸îÏß
	if (b1 == 0 && b0 == 0)
	{
		printf("Õû\n");
		return 0;
	}
	if (b1 != 0)
	{

		ifzero = 0;
		ifzero1 = 0;
		switch (b1)
		{
			case 9:
				printf("¾Á½Ç");
				break;
			case 8:
				printf("°Æ½Ç");
				break;
			case 7:
				printf("Æâ½Ç");
				break;
			case 6:
				printf("Â½½Ç");
				break;
			case 5:
				printf("Îé½Ç");
				break;
			case 4:
				printf("ËÁ½Ç");
				break;
			case 3:
				printf("Èþ½Ç");
				break;
			case 2:
				printf("·¡½Ç");
				break;
			case 1:
				printf("Ò¼½Ç");
				break;
		}
	}
	else
	{
		if (!ifzero1)
			printf("Áã");
	}
	if (b0 != 0)
	{
		ifzero = 0;
		ifzero1 = 0;
		switch (b0)
		{
			case 9:
				printf("¾Á·Ö");
				break;
			case 8:
				printf("°Æ·Ö");
				break;
			case 7:
				printf("Æâ·Ö");
				break;
			case 6:
				printf("Â½·Ö");
				break;
			case 5:
				printf("Îé·Ö");
				break;
			case 4:
				printf("ËÁ·Ö");
				break;
			case 3:
				printf("Èþ·Ö");
				break;
			case 2:
				printf("·¡·Ö");
				break;
			case 1:
				printf("Ò¼·Ö");
				break;
		}
	}
	else
	{
		if (!ifzero1)
			printf("Õû\n");
	}

	return 0;
}