/* 1951559 ����� л���� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
long long num = 0;

/***************************************************************************
  �������ƣ�fibonacci
  ��    �ܣ�����fibonacci���еĵ�n���ֵ
  ���������int n
  �� �� ֵ��fibonacci���еĵ�n���ֵ
  ˵    ����
***************************************************************************/
long long fibonacci(int n)
{
	num++;
	//cout << num << endl;
	/* ��Ҫ����ɱ����� */
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2) + 1;
}

/***************************************************************************
  �������ƣ�main
  ��    �ܣ�
  �����������
  �� �� ֵ��0
  ˵    ����main�����������޸�
***************************************************************************/
int main()
{
	long long n, f;
	cout << "������Fibonacci���е�����[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//���ʱ��Ƶ��
	QueryPerformanceCounter(&begin);	//��ó�ʼӲ����ʱ������
	f = fibonacci(n);
	cout << "Fibonacci���е�" << n << "���ֵ : " << f << endl;
	cout << "�ݹ麯����ִ�д����� " << num << endl;
	QueryPerformanceCounter(&end);//�����ֹӲ����ʱ������
	cout << "������Ƶ�� : " << tick.QuadPart << "Hz" << endl;
	cout << "���������� : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "��" << endl;

	return 0;
}