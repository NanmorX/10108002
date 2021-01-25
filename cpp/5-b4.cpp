/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
using namespace std;

int plante[3][10];
int step = 0;
int num[3] = { 0,0,0 };  //当前有几个盘
int v, bo;               //v是移动速度，bo是是否显示内部数组

/* 运行定义宏定义、常变量、函数声明、全局变量等，其中全局变量的个数要遵守规范 */

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/* 允许添加自己的函数 */

void print_plante(char ch)
{
	if (plante[ch-'A'][0] == 10)
		cout << ch << ":";
	else
		cout << ch << ": ";
	int i;
	for (i = 0; i < 10; i++)
	{
		if (plante[ch-'A'][i] != 0)
			cout << plante[ch-'A'][i] << " ";
		else
			break;
	}
	if (i != 10)
		cout << setw(static_cast <__int64>(20) - static_cast<__int64>(static_cast<__int64>(i) * static_cast <__int64>(2))) << " ";
}

void print_level(int n, char src, char dst, const HANDLE hout)
{
	if (step)
	{
		num[dst - 'A']++;
		plante[dst - 'A'][num[dst - 'A'] - 1] = plante[src - 'A'][num[src - 'A'] - 1];
		plante[src - 'A'][num[src - 'A'] - 1] = 0;
		num[src - 'A']--;
	}

	if (bo&&step)
	{
		gotoxy(hout, 0, 17);
		cout << "第" << std::right << setw(4) << step << "步(";
		cout << n << "#: ";
		cout << src << "-->" << dst << ")  ";
		print_plante('A');
		print_plante('B');
		print_plante('C');
		if (v == 0)
		{
			char c = _getch();
			while (c != 13)
			{
				c = _getch();
			}
		}
		else if (v == 1)
			Sleep(1000);
		else if (v == 2)
			Sleep(500);
		else if (v == 3)
			Sleep(100);
		else if (v == 4)
			Sleep(50);
		else
			Sleep(5);
	}

	for (int i = 9; i >=0; i--)
	{
		if (plante[0][i])
			if (plante[0][i] != 10)
				showch(hout, 11, 11 - i, plante[0][i] + '0');
			else
			{
				showch(hout, 10, 11 - i, '1');
				showch(hout, 11, 11 - i, '0');
			}
		else
		{
			showch(hout, 11, 11 - i, ' ');
			showch(hout, 10, 11 - i, ' ');
		}
		if (plante[1][i])
			if (plante[1][i] != 10)
				showch(hout, 21, 11 - i, plante[1][i] + '0');
			else
			{
				showch(hout, 20, 11 - i, '1');
				showch(hout, 21, 11 - i, '0');
			}
		else
		{
			showch(hout, 21, 11 - i, ' ');
			showch(hout, 20, 11 - i, ' ');
		}
		if (plante[2][i])
			if (plante[2][i] != 10)
				showch(hout, 31, 11 - i, plante[2][i] + '0');
			else
			{
				showch(hout, 30, 11 - i, '1');
				showch(hout, 31, 11 - i, '0');
			}
		else
		{
			showch(hout, 31, 11 - i, ' ');
			showch(hout, 30, 11 - i, ' ');
		}
	}

	gotoxy(hout, 0, 17);

	if (step)
	{
		cout << "第" << std::right << setw(4) << step << "步(";
		cout << n << "#: ";
		cout << src << "-->" << dst << ")  ";
	}
	else
	{
		cout << "初始:  ";
	}

	if (bo)
	{
		print_plante('A');
		print_plante('B');
		print_plante('C');
	}
	if (step)
	{
		gotoxy(hout, 12 + (dst - 'A') * 10 , 11 - num[dst - 'A'] + 1);
	}
	else
	{
		gotoxy(hout, 12 , 11 - n + 1);
	}

	step++;

	if (v == 0)
	{
		char c = _getch();
		while (c != 13)
		{
			c = _getch();
		}
	}
	else if (v == 1)
		Sleep(1000);
	else if (v == 2)
		Sleep(500);
	else if (v == 3)
		Sleep(100);
	else if (v == 4)
		Sleep(50);
	else
		Sleep(5);

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
void hanoi(int n, char src, char tmp, char dst, const HANDLE hout)
{
	if (n == 0)
	{
		return;
	}
	if (n == 1)
	{
		print_level(n, src, dst, hout);
		return;
	}
	hanoi(n - 1, src, dst, tmp, hout);
	print_level(n, src, dst, hout);
	hanoi(n - 1, tmp, src, dst, hout);
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
	while (1)
	{
		cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短): " << endl;
		cin >> v;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if (v>=0&&v<=5)
		{
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
		cout << "请输入是否显示内部数组值(0-不显示 1-显示): " << endl;
		cin >> bo;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if (bo == 0 || bo == 1)
		{
			break;
		}
		else
		{
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int n;
	char src, tmp, dst;

	memset(plante, 0, sizeof(plante));
	input(n, src, dst);
	if (src != 'A' && dst != 'A')
		tmp = 'A';
	else if (src != 'B' && dst != 'B')
		tmp = 'B';
	else
		tmp = 'C';
	for (int i = 0; i < n; i++)
	{
		plante[src-'A'][i] = n - i;
	}
	num[src - 'A'] = n;
	cls(hout);
	if (bo)
	{
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << v << "，显示内部数组值" << endl;
	}
	else
	{
		cout << "从 " << src << " 移动到 " << dst << "，共 " << n << " 层，延时设置为 " << v << "，不显示内部数组值" << endl;
	}
	if (bo)
	{
		gotoxy(hout, 0, 17);
		cout << "初始:  ";
		print_plante('A');
		print_plante('B');
		print_plante('C');
		if (v == 0)
		{
			char c = _getch();
			while (c != 13)
			{
				c = _getch();
			}
		}
		else if (v == 1)
			Sleep(1000);
		else if (v == 2)
			Sleep(500);
		else if (v == 3)
			Sleep(100);
		else if (v == 4)
			Sleep(50);
		else
			Sleep(5);
	}
	gotoxy(hout, 0, 12);
	cout << setw(9) << " ";
	cout << "=========================" << endl;
	cout << setw(11) << " ";
	cout << "A         B         C" << endl;
	print_level(n, src, dst, hout);
	hanoi(n,src,tmp,dst,hout);
	gotoxy(hout, 0, 18);
	return 0;
}