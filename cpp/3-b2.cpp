/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入[0-100亿)之间的数字：" << endl;
	double k, precious = 0.0, inter = 0;
	cin >> k;
	precious = modf(k, &inter);             //分解整数部分和小数部分
	long long k1;
	k1 = static_cast<long long> (inter);    //强制类型转换

	//整数部分
	long long a;
	a = k1 / 1000000000;
	cout << "十亿位 : " << a << endl;
	k1 = k1 - a * 1000000000;
	a = k1 / 100000000;
	cout << "亿位   : " << a << endl;
	k1 = k1 - a * 100000000;
	a = k1 / 10000000;
	cout << "千万位 : " << a << endl;
	k1 = k1 - a * 10000000;
	a = k1 / 1000000;
	cout << "百万位 : " << a << endl;
	k1 = k1 - a * 1000000;
	a = k1 / 100000;
	cout << "十万位 : " << a << endl;
	k1 = k1 - a * 100000;
	a = k1 / 10000;
	cout << "万位   : " << a << endl;
	k1 = k1 - a * 10000;
	a = k1 / 1000;
	cout << "千位   : " << a << endl;
	k1 = k1 - a * 1000;
	a = k1 / 100;
	cout << "百位   : " << a << endl;
	k1 = k1 - a * 100;
	a = k1 / 10;
	cout << "十位   : " << a << endl;
	k1 = k1 - a * 10;
	a = k1 / 1;
	cout << "圆     : " << a << endl;

	//小数部分
	long long k2;
	k2 = static_cast<long long>(precious * 1000) + 1;      //考虑double类型的存储，+1
	k2 /= 10;
	a = k2 / 10;
	cout << "角     : " << a << endl;
	k2 = k2 - a * 10;
	a = k2 / 1;
	cout << "分     : " << a << endl;

	return 0;
}