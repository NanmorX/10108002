/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 定义符号常量
				 定义const型变量
		不允许 ：定义全局变量
   ----------------------------------------------------------------------------------- */

/***************************************************************************
	函数名称：print_space
	功    能：打印空格
	输入参数：num       ：用来计算空格数
	返 回 值：无
	说    明：
***************************************************************************/
void print_space(int num)
{
	if (num <= 0)
		return;
	if (num == 1)
	{
		cout << " ";
		return;
	}
	else
	{
		cout << " ";
		print_space(num - 1);
	}
	return;
}

/***************************************************************************
	函数名称：level_power
	功    能：打印三角塔一层的数据
	输入参数：order - 0 ：正三角形塔
			  order - 1 ：倒三角形塔
			  num       ：用来计算空格数
	返 回 值：无
	说    明：
***************************************************************************/
void level_tower(char start_ch, char end_ch, int order)
{
	if (start_ch == end_ch)
	{
		cout << start_ch;
		return;
	}
	if (order == 0)
	{
		cout << end_ch;
		level_tower(start_ch, end_ch - 1, order);
		cout << end_ch;
	}
	else
	{
		cout << start_ch;
		level_tower(start_ch + 1, end_ch, order);
		cout << start_ch;
	}
	return;
}

/***************************************************************************
	函数名称：print_power
	功    能：正向或反向打印三角塔
	输入参数：order - 0 ：正三角形塔
			  order - 1 ：倒三角形塔
	返 回 值：无
	说    明：
***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	int num1 = end_ch - start_ch ;
	int num2 = start_ch - 'A' ;
	if (start_ch == end_ch && order == 1)
	{
		print_space(num2);
		cout << start_ch << endl;
		return;
	}
	if (end_ch == start_ch && order == 0)
	{
		print_space(num1);
		level_tower('A', start_ch, order);
		cout << endl;
		return;
	}
	if (order == 0)
	{
		print_space(num1);
		level_tower('A', start_ch, order);
		cout << endl;
		print_tower(start_ch+1 , end_ch , order);
	}
	else
	{
		print_space(num2);
		level_tower(start_ch, end_ch, order);
		cout << endl;
		print_tower(start_ch + 1, end_ch, order);
	}
	return;
}

/***************************************************************************
  函数名称：main
  功    能：
  输入参数：无
  返 回 值：0
  说    明：main函数不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	while (1) {
		cout << "请输入结束字符(A~Z)" << endl;
		end_ch = getchar();			//读缓冲区第一个字符
		while (getchar() != '\n')	//清空缓冲区剩余字符
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}