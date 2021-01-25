/* 1951559 计算机 谢佳依 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int plante[3][10];
int step = 1;
int num[3] = { 0,0,0 };  //当前有几个盘

void print_plante(char ch)
{
	if (plante[ch - 'A'][0] == 10)
		printf("%c:", ch);
	else
		printf("%c: ", ch);
	int i;
	for (i = 0; i < 10; i++)
	{
		if (plante[ch - 'A'][i] != 0)
			printf("%d ", plante[ch - 'A'][i]);
		else
			break;
	}
	if (i != 10)
		printf("%*c",20-i*2,' ');
}

void print_level(int n, char src, char dst)
{
	printf("第%4d步(", step);
	printf("%2d): ", n);
	printf("%c-->%c ", src, dst);
	num[dst - 'A']++;
	plante[dst - 'A'][num[dst - 'A'] - 1] = plante[src - 'A'][num[src - 'A'] - 1];
	plante[src - 'A'][num[src - 'A'] - 1] = 0;
	num[src - 'A']--;
	print_plante('A');
	print_plante('B');
	print_plante('C');
	printf("\n");
	step++;
	return;
}

/***************************************************************************
	函数名称：hanoi
	功    能：打印n层汉诺塔的移动顺序
	输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
	返 回 值：
	说    明：1、函数名、形参、返回类型均不准动
			2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n == 0)
	{
		return;
	}
	if (n == 1)
	{
		print_level(n, src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	print_level(n, src, dst);
	hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  函数名称：main
  功    能：input函数以及hanoi函数的调用
  输入参数：无
  返 回 值：0
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int n;
	char src, tmp, dst;
	memset(plante, 0, sizeof(plante));

	//相当于c++中的input函数
	while (1)
	{
		printf("请输入汉诺塔的层数(1-10)：\n");
		int status = scanf("%d", &n);
		if (!status)  //读入x的方式必须是cin>>int型变量
		{
			rewind(stdin);
			continue;
		}
		if (n >= 1 && n <= 16)
		{
			rewind(stdin);
			break;
		}
		else
		{
			rewind(stdin);
			continue;
		}
	}
	while (1)
	{
		printf("请输入起始柱(A-C)：\n");
		int status = scanf("%c", &src);
		if (!status)  //读入x的方式必须是cin>>int型变量
		{
			rewind(stdin);
			continue;
		}
		if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c'))
		{
			rewind(stdin);
			if (src >= 'a' && src <= 'c')
				src = src - 32;
			break;
		}
		else
		{
			rewind(stdin);
			continue;
		}
	}
	while (1)
	{
		printf("请输入目标柱(A-C)：\n");
		int status = scanf("%c", &dst);
		if (!status)  //读入x的方式必须是cin>>int型变量
		{
			rewind(stdin);
			continue;
		}
		if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c'))
		{
			if (dst >= 'a' && dst <= 'c')
				dst = dst - 32;
			if (dst == src)
			{

				printf("目标柱(%c)不能与起始柱(%c)相同\n", dst, src);
				rewind(stdin);
				continue;
			}
			else
			{
				rewind(stdin);
				break;
			}
		}
		else
		{
			rewind(stdin);
			continue;
		}
	}

	if (src != 'A' && dst != 'A')
		tmp = 'A';
	else if (src != 'B' && dst != 'B')
		tmp = 'B';
	else
		tmp = 'C';
	for (int i = 0; i < n; i++)
	{
		if (src < 'D')
			plante[src - 'A'][i] = (int)(n)-i;
	}
	if (src < 'D')
		num[src - 'A'] = (int)n;
	printf("初始:%*c", 15, ' ');
	print_plante('A');
	print_plante('B');
	print_plante('C');
	printf("\n");
	hanoi(n, src, tmp, dst);
	return 0;
}
