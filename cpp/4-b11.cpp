/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
long long num = 0;

/***************************************************************************
  函数名称：fibonacci
  功    能：返回fibonacci数列的第n项的值
  输入参数：int n
  返 回 值：fibonacci数列的第n项的值
  说    明：
***************************************************************************/
long long fibonacci(int n)
{
	num++;
	//cout << num << endl;
	/* 按要求完成本函数 */
	if (n == 1 || n == 2)
		return 1;
	else
		return fibonacci(n - 1) + fibonacci(n - 2) + 1;
}

/***************************************************************************
  函数名称：main
  功    能：
  输入参数：无
  返 回 值：0
  说    明：main函数不允许修改
***************************************************************************/
int main()
{
	long long n, f;
	cout << "请输入Fibonacci数列的项数[1-46]" << endl;
	cin >> n;

	LARGE_INTEGER tick, begin, end;
	QueryPerformanceFrequency(&tick);	//获得时钟频率
	QueryPerformanceCounter(&begin);	//获得初始硬件定时器计数
	f = fibonacci(n);
	cout << "Fibonacci数列第" << n << "项的值 : " << f << endl;
	cout << "递归函数的执行次数： " << num << endl;
	QueryPerformanceCounter(&end);//获得终止硬件定时器计数
	cout << "计数器频率 : " << tick.QuadPart << "Hz" << endl;
	cout << "计数器计数 : " << end.QuadPart - begin.QuadPart << endl;
	cout << setiosflags(ios::fixed) << setprecision(6) << double(end.QuadPart - begin.QuadPart) / tick.QuadPart << "秒" << endl;

	return 0;
}