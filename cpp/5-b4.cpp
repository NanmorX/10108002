/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <conio.h>
#include <windows.h>
using namespace std;

int plante[3][10];
int step = 0;
int num[3] = { 0,0,0 };  //��ǰ�м�����
int v, bo;               //v���ƶ��ٶȣ�bo���Ƿ���ʾ�ڲ�����

/* ���ж���궨�塢������������������ȫ�ֱ����ȣ�����ȫ�ֱ����ĸ���Ҫ���ع淶 */

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
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
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

/* ��������Լ��ĺ��� */

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
		cout << "��" << std::right << setw(4) << step << "��(";
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
		cout << "��" << std::right << setw(4) << step << "��(";
		cout << n << "#: ";
		cout << src << "-->" << dst << ")  ";
	}
	else
	{
		cout << "��ʼ:  ";
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
	�������ƣ�hanoi
	��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	���������int n������
			char src����ʼ��
			char tmp���м���
			char dst��Ŀ����
	�� �� ֵ��
	˵    ����1�����������βΡ��������;���׼��
			2������������������κ���ʽ��ѭ��
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
  �������ƣ�input
  ��    �ܣ������������ʼ/Ŀ����
  ���������int n������
			char src����ʼ��
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input(int& n, char& src, char& dst)
{
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
		cin >> n;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
		if (n >= 1 && n <= 16)
		{
			cin.ignore(10241024, '\n');
			break;
		}
		else
		{
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}
	while (1)
	{
		cout << "��������ʼ��(A-C)��" << endl;
		cin >> src;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
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
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}
	while (1)
	{
		cout << "������Ŀ����(A-C)��" << endl;
		cin >> dst;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
		if ((dst >= 'A' && dst <= 'C') || (dst >= 'a' && dst <= 'c'))
		{
			if (dst >= 'a' && dst <= 'c')
				dst = dst - 32;
			if (dst == src)
			{

				cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
				cin.ignore(10241024, '\n'); //��ջ�����
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
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}
	while (1)
	{
		cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���): " << endl;
		cin >> v;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
		if (v>=0&&v<=5)
		{
			break;
		}
		else
		{
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}
	while (1)
	{
		cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ): " << endl;
		cin >> bo;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
		if (bo == 0 || bo == 1)
		{
			break;
		}
		else
		{
			cin.ignore(10241024, '\n'); //��ջ�����
			continue;
		}
	}
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << v << "����ʾ�ڲ�����ֵ" << endl;
	}
	else
	{
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << v << "������ʾ�ڲ�����ֵ" << endl;
	}
	if (bo)
	{
		gotoxy(hout, 0, 17);
		cout << "��ʼ:  ";
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