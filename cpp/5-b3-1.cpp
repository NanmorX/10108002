/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int plante1[10];
int plante2[10];
int plante3[10];
int step = 1;
int num1 = 0, num2 = 0, num3 = 0; //当前有几个盘

void print_plante(char ch)
{
	if (ch == 'A')
	{
		if (plante1[0] == 10)
			cout << ch << ":";
		else
			cout << ch << ": ";
		int i;
		for (i = 0; i < 10; i++)
		{
			if (plante1[i] != 0)
				cout << plante1[i] << " ";
			else
				break;
		}
		if (i != 10)
			cout << setw(static_cast < __int64>(20) - static_cast<__int64>(static_cast<__int64>(i) * static_cast < __int64>(2))) << " ";
	}
	else if (ch == 'B')
	{
		if (plante2[0] == 10)
			cout << ch << ":";
		else
			cout << ch << ": ";
		int i;
		for (i = 0; i < 10; i++)
		{
			if (plante2[i] != 0)
				cout << plante2[i] << " ";
			else
				break;
		}
		if (i != 10)
			cout << setw(static_cast <__int64>(20) - static_cast<__int64>(static_cast<__int64>(i) * static_cast <__int64>(2))) << " ";
	}
	else
	{
		if (plante3[0] == 10)
			cout << ch << ":";
		else
			cout << ch << ": ";
		int i;
		for (i = 0; i < 10; i++)
		{
			if (plante3[i] != 0)
				cout << plante3[i] << " ";
			else
				break;
		}
		if (i != 10)
			cout << setw(static_cast <__int64>(20) - static_cast<__int64>(static_cast<__int64>(i) * static_cast <__int64>(2))) << " ";
	}
}

void print_level(int n,char src, char dst)
{
	cout << "第" << std::right << setw(4) << step << " 步(";
	cout << std::right << setw(2) << n << "): ";
	cout << src << "-->" << dst << " ";
	switch (dst)
	{
		case 'A':
			num1 ++;
			break;
		case 'B':
			num2 ++;
			break;
		case'C':
			num3 ++;
		default:
			break;
	}
	if (dst == 'A' && src == 'B')
	{
		plante1[num1 - 1] = plante2[num2- 1];
		plante2[num2 - 1] = 0;
	}
	else if (dst == 'A' && src == 'C')
	{
		plante1[num1 - 1] = plante3[num3 - 1];
		plante3[num3 - 1] = 0;
	}
	else if (dst == 'B' && src == 'A')
	{
		plante2[num2 - 1] = plante1[num1 - 1];
		plante1[num1 - 1] = 0;
	}
	else if (dst == 'B' && src == 'C')
	{
		plante2[num2 - 1] = plante3[num3 - 1];
		plante3[num3 - 1] = 0;
	}
	else if (dst == 'C' && src == 'A')
	{
		plante3[num3 - 1] = plante1[num1 - 1];
		plante1[num1 - 1] = 0;
	}
	else
	{
		plante3[num3 - 1] = plante2[num2 - 1];
		plante2[num2 - 1] = 0;
	}
	switch (src)
	{
		case 'A':
			num1 --;
			break;
		case 'B':
			num2 --;
			break;
		case'C':
			num3 --;
		default:
			break;
	}
	print_plante('A');
	print_plante('B');
	print_plante('C');
	cout << endl;
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
  函数名称：input
  功    能：输入层数、起始/目标柱
  输入参数：int n：层数
			char src：起始柱
			char dst：目标柱
  返 回 值：
  说    明：
***************************************************************************/
void input(int& n, char& src, char& dst)
{
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)：" << endl;
		cin >> n;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if (n >= 1 && n <= 16)
		{
			cin.ignore(10241024, '\n');
			break;
		}
		else
		{
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}
	while (1)
	{
		cout << "请输入起始柱(A-C)：" << endl;
		cin >> src;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if ((src >= 'A' && src <= 'C') || (src >= 'a' && src <= 'c'))
		{
			cin.ignore(10241024, '\n');
			if (src >= 'a' && src <= 'c')
				src = src - 32;
			break;
		}
		else
		{
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}
	while (1)
	{
		cout << "请输入目标柱(A-C)：" << endl;
		cin >> dst;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c'))
		{
			if (dst >= 'a' && dst <= 'c')
				dst = dst - 32;
			if (dst == src)
			{

				cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
				cin.ignore(10241024, '\n'); //清空缓冲区
				continue;
			}
			else
			{
				cin.ignore(10241024, '\n');
				break;
			}
		}
		else
		{
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}
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
	memset(plante1, 0, sizeof(plante1));
	memset(plante2, 0, sizeof(plante2));
	memset(plante3, 0, sizeof(plante3));
	input(n, src, dst);
	if (src != 'A' && dst != 'A')
		tmp = 'A';
	else if (src != 'B' && dst != 'B')
		tmp = 'B';
	else
		tmp = 'C';
	for (int i = 0; i < n; i++)
	{
		if (src == 'A')
			plante1[i] = n - i;
		else if (src == 'B')
			plante2[i] = n - i;
		else
			plante3[i] = n - i;
	}
	switch (src) 
	{
		case 'A':
			num1 = n;
			break;
		case 'B':
			num2 = n;
			break;
		case'C':
			num3 = n;
		default:
			break;
	}
	cout << std::left<<setw(21)<<"初始:";
	print_plante('A');
	print_plante('B');
	print_plante('C');
	cout << endl;
	hanoi(n, src, tmp, dst);
	return 0;
}
