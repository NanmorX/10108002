/* 1951559 计算机 谢佳依 */
#include <iostream>
using namespace std;

int zeller(int y, int m, int d)
{
	int w,c;
	if (m <= 2)
	{
		m += 12;
		y--;
	}
	c = y / 100;
	y = y - c * 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	w = (w + 7 * 1000) % 7;
	return w;
}

int main()
{
	int y, m, d;
	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if (!(y >= 1900 && y <= 2100))
		{
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		if(!(m<=12&&m>=1))
		{
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
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
		if (!(d >= 1 && d <= daymax))
		{
			cout << "日不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	int w = zeller(y,m,d);
	switch (w)
	{
		case 0:
			cout << "星期日" << endl;
			break;
		case 1:
			cout << "星期一" << endl;
			break;
		case 2:
			cout << "星期二" << endl;
			break;
		case 3:
			cout << "星期三" << endl;
			break;
		case 4:
			cout << "星期四" << endl;
			break;
		case 5:
			cout << "星期五" << endl;
			break;
		case 6:
			cout << "星期六" << endl;
			break;
	}

	return 0;
}