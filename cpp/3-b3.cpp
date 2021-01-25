/* 1951559 计算机 谢佳依 */
#include <iostream>
using namespace std;

int main()
{
	int y, m, d,k;
	cout << "请输入年，月，日：" << endl;
	cin >> y >> m >> d;

	if (m > 12|| m <= 0)
	{
		cout << "输入错误-月份不正确" << endl;
	}
	else if ((m == 2 && d > 29)|| d < 1 || d > 31)
	{
		cout << "输入错误-日与月的关系非法" << endl;
	}
	else if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			k = 30 * 1 + 1 + d;
			cout << y << "-" << m << "-" << d << "是" << y << "年的第" << k << "天" << endl;
		}
		else
		{
			if (d != 29)
			{
				k = 30 * 1 + 1 + d;
				cout << y << "-" << m << "-" << d << "是" << y << "年的第" << k << "天" << endl;
			}
			else
			{
				cout << "输入错误-日与月的关系非法" << endl;
			}
		}
	}
	else
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			switch (m)
			{
				case 1:
					k = d;
					break;
				case 2:
					k = 30 * 1 + 1 + d;
					break;
				case 3:
					k = 30 * 2 + 0 + d;
					break;
				case 4:
					k = 30 * 3 + 1 + d;
					break;
				case 5:
					k = 30 * 4 + 1 + d;
					break;
				case 6:
					k = 30 * 5 + 2 + d;
					break;
				case 7:
					k = 30 * 6 + 2 + d;
					break;
				case 8:
					k = 30 * 7 + 3 + d;
					break;
				case 9:
					k = 30 * 8 + 4 + d;
					break;
				case 10:
					k = 30 * 9 + 4 + d;
					break;
				case 11:
					k = 30 * 10 + 5 + d;
					break;
				case 12:
					k = 30 * 11 + 5 + d;
					break;
				default:
					break;
			}
		}
		else
		{
			switch (m)
			{
				case 1:
					k = d;
					break;
				case 2:
					k = 30 * 1 + 1 + d;
					break;
				case 3:
					k = 30 * 2 - 1 + d;
					break;
				case 4:
					k = 30 * 3 + 0 + d;
					break;
				case 5:
					k = 30 * 4 + 0 + d;
					break;
				case 6:
					k = 30 * 5 + 1 + d;
					break;
				case 7:
					k = 30 * 6 + 1 + d;
					break;
				case 8:
					k = 30 * 7 + 2 + d;
					break;
				case 9:
					k = 30 * 8 + 3 + d;
					break;
				case 10:
					k = 30 * 9 + 3 + d;
					break;
				case 11:
					k = 30 * 10 + 4 + d;
					break;
				case 12:
					k = 30 * 11 + 4 + d;
					break;
				default:
					break;
			}
		}
		cout << y << "-" << m << "-" << d << "是" << y << "年的第"<<k<<"天" << endl;
	}

	return 0;
}