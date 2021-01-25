/* 1951559 ����� л���� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�menu
  ��    �ܣ��˵���ʾ��ѡ��
  �����������
  �� �� ֵ��char
  ˵    ����
***************************************************************************/
char menu()
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n"
		 << "2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n"
		 << "3.�ü�ͷ�������������ң��߽�ֹͣ\n"
		 << "4.�ü�ͷ�������������ң��߽����\n"
		 << "5.�ü�ͷ��������������(�߽�ֹͣ����ʾHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n"
		 << "6.�ü�ͷ��������������(�߽���ƣ���ʾHPKM���ƶ��Ĵ��󣬴����Ҫʵ��)\n"
		 << "0.�˳�\n"
		 << "[��ѡ��0 - 6] ";
	char k;
	k = _getch();
	return k;
}

/***************************************************************************
  �������ƣ�move_by_ijkl
  ��    �ܣ�ͨ��ijkl�����ƶ�
  ���������int k ������Ƿ���ƣ�1/2��
			HANDLE hout������豸���
  �� �� ֵ����
  ˵    ��������Ҫ
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
  �������ƣ�move_by_arrow
  ��    �ܣ�ͨ����ͷ�������ƶ�
  ���������int k ������Ƿ���ƣ�5/6��
			HANDLE hout������豸���
  �� �� ֵ����
  ˵    ������������ 72 80 75 77, HPKM�ܿ��ƵĴ�����ʾ
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
  �������ƣ�move
  ��    �ܣ������ƶ�
  ���������int k ��ͨ��ijkl����������ƶ��Լ�����Ƿ���ƣ�1/2/3/4��
			HANDLE hout������豸���
  �� �� ֵ����
  ˵    ������������ 72 80 75 77, HPKM���ܿ���
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));

	/* �˾�������ǵ���ϵͳ��cls�������� */
	cls(hout);
	char k = menu();
	
	while (k - '0' != 0)
	{
		cout << k;
		cls(hout);
		/*��ʾ��ʼ�ı߿����е�����ַ� */
		if (k > '0' && k <= '4')                            //1,2,3,4
		{
			init_border(hout);
			gotoxy(hout, 35, 9);
			move(hout, k - '0');
			gotoxy(hout, 0, 23);
			cout << "��Ϸ���������س����˳�.";
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
			cout << "��Ϸ���������س����˳�.";
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