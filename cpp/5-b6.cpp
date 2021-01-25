/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <iomanip>
using namespace std;

void zeller(int y, int m[12], int d)
{
	for (int i = 1; i <= 12; i++)
	{
		int year = y;
		int mon = i;
		int w, c;
		if (mon <= 2)
		{
			mon += 12;
			year--;
		}
		c = year / 100;
		year = year - c * 100;
		w = year + year / 4 + c / 4 - 2 * c + 13 * (mon + 1) / 5 + d - 1;
		w = (w + 7 * 1000) % 7;
		m[i-1] = w;
	}
}

void calendar(int y, int m[12])
{
	//初始化
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		day[1] = 29;
	cout << y << "年的日历:" << endl;
	cout << endl;

	for (int i = 0; i < 12; i += 3)             //3个月一组
	{
		int k[3] = { 1,1,1 };                   //打印日期数组
		cout << std::right;
		cout << setw(13) << i + 1 << "月" 
			 << setw(12 + 5 + 13) << i + 2 << "月" 
			 << setw(30) << i + 3 << "月" << endl;
		cout << "Sun Mon Tue Wed Thu Fri Sat";
		cout << setw(5) << " " << "Sun Mon Tue Wed Thu Fri Sat";
		cout << setw(5) << " " << "Sun Mon Tue Wed Thu Fri Sat";
		cout << endl;

		//月历第一行输出
		cout << std::left;
		for (int p = 0; p < 3; p++)
		{
			for (int j = 0; j < m[i+p]; j++)
			{
				cout << setw(4) << " ";
			}
			for (int j = m[i+p]; j < 7; j++, k[p]++)
			{
				cout << setw(4) << k[p];
			}
			if(p!=2)
				cout << setw(4) << " ";
		}
		cout << endl;

		//每七个换行输出
		while (k[0] <= day[i]|| k[1] <= day[i + 1]|| k[2] <= day[i + 2])
		{
			for (int p = 0; p < 3; p++)
			{
				int step = 0;
				for (; step < 7; step++)
				{
					if (k[p] > day[i+p])
						cout << setw(4) << " ";
					else
					{
						cout << setw(4) << k[p];
						k[p]++;
					}
				}
				if (p != 2)
					cout << setw(4) << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	return;
}

int main()
{
	system("mode con cols=120 lines=45");
	int y, m[13] = { 0 };

	//得到年份和月份
	while (1)
	{
		cout << "请输入年份[1900-2100]" << endl;
		cin >> y;
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
		break;
	}

	zeller(y, m, 1);
	calendar(y, m);

	return 0;
}
