/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

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
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
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

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：menu
  功    能：菜单显示和选择
  输入参数：无
  返 回 值：char
  说    明：
***************************************************************************/
char menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n"
		 << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n"
		 << "3.用箭头键控制上下左右，边界停止\n"
		 << "4.用箭头键控制上下左右，边界回绕\n"
		 << "5.用箭头键控制上下左右(边界停止，演示HPKM可移动的错误，此项不需要实现)\n"
		 << "6.用箭头键控制上下左右(边界回绕，演示HPKM可移动的错误，此项不需要实现)\n"
		 << "0.退出\n"
		 << "[请选择0 - 6] ";
	char k;
	k = _getch();
	return k;
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：通过ijkl控制移动
  输入参数：int k ：光标是否回绕（1/2）
			HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：不重要
***************************************************************************/
void move_by_ijkl(const HANDLE hout ,int k)
{
	int x = 35, y = 9;
	char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 'q' || ch == 'Q')
			break;
		if (ch == 'i' || ch == 'I')
		{
			if (y > 1)
			{
				gotoxy(hout, x, y - 1);
				y--;
			}
			else if (k == 2 && y == 1)
			{
				y = 17;
				gotoxy(hout, x, y);
			}
		}
		if (ch == 'j' || ch == 'J')
		{
			if (x > 1)
			{
				gotoxy(hout, x - 1, y);
				x--;
			}
			else if (k == 2 && x == 1)
			{
				x = 69;
				gotoxy(hout, x, y);
			}
		}
		if (ch == 'k' || ch == 'K')
		{
			if (y < 17 )
			{
				gotoxy(hout, x, y + 1);
				y++;
			}
			else if (k == 2 && y == 17)
			{
				y = 1;
				gotoxy(hout, x, y);
			}
		}
		if (ch == 'l' || ch == 'L')
		{
			if (x < 69)
			{
				gotoxy(hout, x + 1, y);
				x++;
			}
			else if (k == 2 && x == 69)
			{
				x = 1;
				gotoxy(hout, x, y);
			}
		}
		if (ch == ' ')
		{
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
	}
	return;
}

/***************************************************************************
  函数名称：move_by_arrow
  功    能：通过箭头键控制移动
  输入参数：int k ：光标是否回绕（5/6）
			HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：上下左右 72 80 75 77, HPKM能控制的错误演示
***************************************************************************/
void move_by_arrow(const HANDLE hout, int k)
{
	int x = 35, y = 9;
	char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 'q' || ch == 'Q')
			break;
		if (ch == 72)
		{
			if (y > 1)
			{
				gotoxy(hout, x, y - 1);
				y--;
			}
			else if (k == 6 && y == 1)
			{
				y = 17;
				gotoxy(hout, x, y);
			}
		}
		if (ch == 75)
		{
			if (x > 1)
			{
				gotoxy(hout, x - 1, y);
				x--;
			}
			else if (k == 6 && x == 1)
			{
				x = 69;
				gotoxy(hout, x, y);
			}
		}
		if (ch == 80)
		{
			if (y < 17)
			{
				gotoxy(hout, x, y + 1);
				y++;
			}
			else if (k == 6 && y == 17)
			{
				y = 1;
				gotoxy(hout, x, y);
			}
		}
		if (ch == 77)
		{
			if (x < 69)
			{
				gotoxy(hout, x + 1, y);
				x++;
			}
			else if (k == 6 && x == 69)
			{
				x = 1;
				gotoxy(hout, x, y);
			}
		}
		if (ch == ' ')
		{
			showch(hout, x, y, ' ');
			gotoxy(hout, x, y);
		}
	}
	return;
}

/***************************************************************************
  函数名称：move
  功    能：控制移动
  输入参数：int k ：通过ijkl或方向键控制移动以及光标是否回绕（1/2/3/4）
			HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：上下左右 72 80 75 77, HPKM不能控制
***************************************************************************/
void move(const HANDLE hout, int k)
{
	int x = 35, y = 9;
	char ch;
	while (1)
	{
		ch = _getch();
		if (ch == 'q' || ch == 'Q')
			break;
		if (k == 4 || k == 3)
		{
			if (ch == -32)
			{
				char a = _getch();
				if (a == 72 && ch == -32)
				{
					if (y > 1)
					{
						gotoxy(hout, x, y - 1);
						y--;
					}
					else if (k == 4 && y == 1)
					{
						y = 17;
						gotoxy(hout, x, y);
					}
				}
				if (a == 75 && ch == -32)
				{
					if (x > 1)
					{
						gotoxy(hout, x - 1, y);
						x--;
					}
					else if (k == 4 && x == 1)
					{
						x = 69;
						gotoxy(hout, x, y);
					}
				}
				if (a == 80 && ch == -32)
				{
					if (y < 17)
					{
						gotoxy(hout, x, y + 1);
						y++;
					}
					else if (k == 4 && y == 17)
					{
						y = 1;
						gotoxy(hout, x, y);
					}
				}
				if (a == 77 && ch == -32)
				{
					if (x < 69)
					{
						gotoxy(hout, x + 1, y);
						x++;
					}
					else if (k == 4 && x == 69)
					{
						x = 1;
						gotoxy(hout, x, y);
					}
				}
			}
		}
		if (k == 1 || k == 2)
		{
			if (ch == 'i' || ch == 'I')
			{
				if (y > 1)
				{
					gotoxy(hout, x, y - 1);
					y--;
				}
				else if (k == 2 && y == 1)
				{
					y = 17;
					gotoxy(hout, x, y);
				}
			}
			if (ch == 'j' || ch == 'J')
			{
				if (x > 1)
				{
					gotoxy(hout, x - 1, y);
					x--;
				}
				else if (k == 2 && x == 1)
				{
					x = 69;
					gotoxy(hout, x, y);
				}
			}
			if (ch == 'k' || ch == 'K')
			{
				if (y < 17)
				{
					gotoxy(hout, x, y + 1);
					y++;
				}
				else if (k == 2 && y == 17)
				{
					y = 1;
					gotoxy(hout, x, y);
				}
			}
			if (ch == 'l' || ch == 'L')
			{
				if (x < 69)
				{
					gotoxy(hout, x + 1, y);
					x++;
				}
				else if (k == 2 && x == 69)
				{
					x = 1;
					gotoxy(hout, x, y);
				}
			}
		}
		if (ch == ' ')
		{
			showch(hout, x, y, ' ');			
			gotoxy(hout, x, y);
		}
	}
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));

	/* 此句的作用是调用系统的cls命令清屏 */
	cls(hout);
	char k = menu();
	
	while (k - '0' != 0)
	{
		cout << k;
		cls(hout);
		/*显示初始的边框及其中的随机字符 */
		if (k > '0' && k <= '4')                            //1,2,3,4
		{
			init_border(hout);
			gotoxy(hout, 35, 9);
			move(hout, k - '0');
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键退出.";
			char c = _getch();
			while (c != 13)
			{
				c = _getch();
			}
			cls(hout);
			k = menu();
			continue;
		}
		else if (k > '4' && k <= '6')                      //5,6
		{
			init_border(hout);
			gotoxy(hout, 35, 9);
			move_by_arrow(hout, k - '0');
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键退出.";
			char c = _getch();
			while (c != 13)
			{
				c = _getch();
			}
			cls(hout);
			k = menu();
			continue;
		}
		else
		{
			k = menu();
		}
	}
	
	return 0;
}