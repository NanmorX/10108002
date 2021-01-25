/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ����������һ�����������������������ӵĺ����в������κ���ʽ��ѭ��
				 ������ų���
				 ����const�ͱ���
		������ ������ȫ�ֱ���
   ----------------------------------------------------------------------------------- */

/***************************************************************************
	�������ƣ�print_space
	��    �ܣ���ӡ�ո�
	���������num       ����������ո���
	�� �� ֵ����
	˵    ����
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
	�������ƣ�level_power
	��    �ܣ���ӡ������һ�������
	���������order - 0 ������������
			  order - 1 ������������
			  num       ����������ո���
	�� �� ֵ����
	˵    ����
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
	�������ƣ�print_power
	��    �ܣ���������ӡ������
	���������order - 0 ������������
			  order - 1 ������������
	�� �� ֵ����
	˵    ����
***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* ����ʵ�֣������в������κ���ʽ��ѭ�����������徲̬�ֲ����� */
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
  �������ƣ�main
  ��    �ܣ�
  �����������
  �� �� ֵ��0
  ˵    ����main������׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч) */
	while (1) {
		cout << "����������ַ�(A~Z)" << endl;
		end_ch = getchar();			//����������һ���ַ�
		while (getchar() != '\n')	//��ջ�����ʣ���ַ�
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* ��������ĸ��(�м�ΪA) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl;/* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* ��������ĸ��(����ΪA) */
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	cout << "��������ĸ��" << endl;
	cout << setfill('=') << setw(((long long)end_ch - 'A') * 2 + 1) << '=' << endl; /* ����ĸ����󳤶����= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}