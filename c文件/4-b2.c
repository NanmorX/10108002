/* 1951559 计算机 谢佳依 */
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
		printf("请输入年[1900-2100]、月、日：\n");
		status = scanf("%d %d %d", &y, &m, &d);
		if (!status)  //读入x的方式必须是cin>>int型变量
		{
			printf("输入错误，请重新输入\n");
			rewind(stdin);
			continue;
		}
		if (!(y >= 1900 && y <= 2100))
		{
			printf("年份不正确，请重新输入\n");
			continue;
		}
		if (!(m <= 12 && m >= 1))
		{
			printf("月份不正确，请重新输入\n");
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
			printf("日不正确，请重新输入\n");
			continue;
		}
		break;
	}
	int w = zeller(y, m, d);
	switch (w)
	{
		case 0:
			printf("星期日\n");
			break;
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
	}

	return 0;
}