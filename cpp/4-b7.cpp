/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

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
		return ;
	}
	if (n == 1)
	{
		cout << setw(2) << n;
		cout << "# " << src << "-->" << dst << endl;
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	cout << setw(2) << n;
	cout << "# " << src << "-->" << dst << endl;
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
void input(int &n, char &src, char &dst)
{
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-16)："<<endl;
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
		cout << "请输入起始柱(A-C)："<<endl;
		cin >> src;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if ((src >= 'A' && src <= 'C')||(src >= 'a' && src <= 'c'))
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
	input(n, src, dst);
	if (src != 'A' && dst != 'A')
		tmp = 'A';
	else if (src != 'B' && dst != 'B')
		tmp = 'B';
	else
		tmp = 'C';
	cout << "移动步骤为:" << endl;
	hanoi(n, src, tmp, dst);
	return 0;
}
