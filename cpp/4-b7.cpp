/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
   3������������������������ʼ/Ŀ�����ĺ���������������ʹ��ѭ�������������
   4����������ú������У���main�в���������κ���ʽ��ѭ����while��do-while��for��if-goto��
	  ���������main�н��У���main���������ѭ��
   --------------------------------------------------------------------- */

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
  �������ƣ�input
  ��    �ܣ������������ʼ/Ŀ����
  ���������int n������
			char src����ʼ��
			char dst��Ŀ����
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void input(int &n, char &src, char &dst)
{
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-16)��"<<endl;
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
		cout << "��������ʼ��(A-C)��"<<endl;
		cin >> src;
		if (cin.fail())  //����x�ķ�ʽ������cin>>int�ͱ���
		{
			cin.clear(); //���������
			cin.ignore(10241024, '\n'); //��ջ�����
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
	input(n, src, dst);
	if (src != 'A' && dst != 'A')
		tmp = 'A';
	else if (src != 'B' && dst != 'B')
		tmp = 'B';
	else
		tmp = 'C';
	cout << "�ƶ�����Ϊ:" << endl;
	hanoi(n, src, tmp, dst);
	return 0;
}
