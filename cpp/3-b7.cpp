/* 1951559 计算机 谢佳依 */
#include <iostream>
using namespace std;

int main()
{
	int y, m, d;
	//得到年份和月份
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		else
		{
			cout << "输入非法，请重新输入" << endl;
			//cin.clear(); //清除错误标记
			//cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}

	//得到星期
	while (1)
	{
		cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> d;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
		if (d >= 0 && d <= 6)
			break;
		else
		{
			cout << "输入非法，请重新输入" << endl;
			//cin.clear(); //清除错误标记
			//cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}

	cout << endl;
	cout << y << "年" << m << "月的日历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;

	int k = 1;
	int daymax;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		daymax = 31;
	}
	else
	{
		daymax = 30;
	}
	if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			daymax = 29;
		else
			daymax = 28;
	}

	//月历第一行输出
	for (int i = 0; i < d; i++)
	{
		cout << "        ";
	}
	for (int i = d; i < 7; i++, k++)
	{
		cout << "   " << k << "    ";
	}
	cout << endl;

	//每七个换行输出
	while (k <= daymax)
	{
		if (k < 10)
			cout << "   " << k << "    ";
		else
			cout << "  " << k << "    ";

		k++;
		if ((k - 7 + d - 1) % 7 == 0)
			cout << endl;
	}
	cout << endl;

	return 0;
}
