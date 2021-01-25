/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int plante1[10];
int plante2[10];
int plante3[10];
int step = 1;
int num1 = 0, num2 = 0, num3 = 0; //��ǰ�м�����

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
	cout << "��" << std::right << setw(4) << step << " ��(";
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
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�input�����Լ�hanoi�����ĵ���
  �����������
  �� �� ֵ��0
  ˵    �����������(��������뺯��)�����õݹ麯��
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
	cout << std::left<<setw(21)<<"��ʼ:";
	print_plante('A');
	print_plante('B');
	print_plante('C');
	cout << endl;
	hanoi(n, src, tmp, dst);
	return 0;
}
