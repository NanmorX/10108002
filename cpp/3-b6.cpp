/* 1951559 计算机 谢佳依 */
#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1)
	{
		cout << "请输入x的值[0-100] : ";
		cin >> x;
		if (cin.fail())  //读入x的方式必须是cin>>int型变量
		{
			cin.clear(); //清除错误标记
			cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			//cin.clear(); //清除错误标记
			//cin.ignore(10241024, '\n'); //清空缓冲区
			continue;
		}
	}

	cout << "x=" << x << endl;

	return 0;
}