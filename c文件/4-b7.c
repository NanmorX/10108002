/* 1951559 ����� л���� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������һ��ȫ�ֱ������������徲̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
      ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
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
		printf("%2d", n);
		printf("# %c-->%c\n", src, dst);
		return;
	}
	hanoi(n - 1, src, dst, tmp);
	printf("%2d", n);
	printf("# %c-->%c\n", src, dst);
	hanoi(n - 1, tmp, src, dst);
	return;
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
	
	//�൱��c++�е�input����
	while (1)
	{
		printf("�����뺺ŵ���Ĳ���(1-16)��\n");
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
	printf("�ƶ�����Ϊ:\n");
	hanoi(n, src, tmp, dst);
	return 0;
}
