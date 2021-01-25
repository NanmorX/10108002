/* 1951559 ����� л���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int plante[3][10];
int step = 1;
int num[3] = { 0,0,0 };  //��ǰ�м�����

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
	printf("��%4d��(", step);
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
	memset(plante, 0, sizeof(plante));

	//�൱��c++�е�input����
	while (1)
	{
		printf("�����뺺ŵ���Ĳ���(1-10)��\n");
		int status = scanf("%d", &n);
		if (!status)  //����x�ķ�ʽ������cin>>int�ͱ���
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
		printf("��������ʼ��(A-C)��\n");
		int status = scanf("%c", &src);
		if (!status)  //����x�ķ�ʽ������cin>>int�ͱ���
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
		printf("������Ŀ����(A-C)��\n");
		int status = scanf("%c", &dst);
		if (!status)  //����x�ķ�ʽ������cin>>int�ͱ���
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

				printf("Ŀ����(%c)��������ʼ��(%c)��ͬ\n", dst, src);
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
	printf("��ʼ:%*c", 15, ' ');
	print_plante('A');
	print_plante('B');
	print_plante('C');
	printf("\n");
	hanoi(n, src, tmp, dst);
	return 0;
}
