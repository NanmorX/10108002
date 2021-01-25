/* 1951559 计算机 谢佳依 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int y, m, d;
	int status;
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		status = scanf("%d %d", &y, &m);
		if (!status)  //读入x的方式必须是cin>>int型变量
		{
			rewind(stdin);
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		else
		{
			printf("输入非法，请重新输入\n");
			//rewind(stdin);
			continue;
		}
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",y,m);
		status = scanf("%d",&d);
		if (!status)  //读入x的方式必须是cin>>int型变量
		{
			rewind(stdin);
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (d >= 0 && d <= 6)
			break;
		else
		{
			printf("输入非法，请重新输入\n");
			//rewind(stdin);
			continue;
		}
	}
	
	printf("\n");
	printf("%d年%d月的日历为:\n",y,m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int k = 1;
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
	for (int i = 0; i < d; i++)
	{
		printf("        ");
	}
	for (int i = d; i < 7; i++, k++)
	{
		printf("   %d    ",k);
	}
	printf("\n");
	while (k <= daymax)
	{
		if (k < 10)
			printf("   %d    ",k);
		else
			printf("  %d    ",k);
		k++;
		if ((k - 7 + d - 1) % 7 == 0)
			printf("\n");
	}
	printf("\n");
	
	return 0;
}
