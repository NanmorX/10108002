/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cout << "请输入找零值： " << endl;
	double k, precious = 0.0, inter = 0;
	int sum = 0;
	cin >> k;
	precious = modf(k, &inter);
	int k1,k2,a;
	k1 = static_cast<int>(inter);
	k2 = static_cast<int>(precious * 1000) + 1;
	k2 /= 10;

	//以下写的方法十分愚蠢，其实可以找变量存储张数，就不用再执行一遍
	a = k1 / 50;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 50;
	a = k1 / 20;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 20;
	a = k1 / 10;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 10;
	a = k1 / 5;
	if (a != 0) 
		sum += a;
	k1 = k1 - a * 5;
	a = k1 / 1;
	if (a != 0) 
		sum += a;
	a = k2 / 50;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 50;
	a = k2 / 10;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 10;
	a = k2 / 5;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 5;
	a = k2 / 2;
	if (a != 0) 
		sum += a;
	k2 = k2 - a * 2;
	a = k2 / 1;
	if (a != 0) 
		sum += a;

	cout << "共有" << sum << "张找零，具体如下：" << endl;
	k1 = static_cast<int>(inter);
	k2 = static_cast<int>(precious * 1000) + 1;
	k2 /= 10;
	a = k1 / 50;
	if (a != 0)
		cout << "50元 : " << a << "张" << endl;
	k1 = k1 - a * 50;
	a = k1 / 20;
	if (a != 0) 
		cout << "20元 : " << a << "张" << endl;
	k1 = k1 - a * 20;
	a = k1 / 10;
	if (a != 0) 
		cout << "10元 : " << a << "张" << endl;
	k1 = k1 - a * 10;
	a = k1 / 5;
	if (a != 0) 
		cout << "5元  : " << a << "张" << endl;
	k1 = k1 - a * 5;
	a = k1 / 1;
	if (a != 0) 
		cout << "1元  : " << a << "张" << endl;
	a = k2 / 50;
	if (a != 0)
		cout << "5角  : " << a << "张" << endl;
	k2 = k2 - a * 50;
	a = k2 / 10;
	if (a != 0) 
		cout << "1角  : " << a << "张" << endl;
	k2 = k2 - a * 10;
	a = k2 / 5;
	if (a != 0) 
		cout << "5分  : " << a << "张" << endl;
	k2 = k2 - a * 5;
	a = k2 / 2;
	if (a != 0) 
		cout << "2分  : " << a << "张" << endl;
	k2 = k2 - a * 2;
	a = k2 / 1;
	if (a != 0) 
		cout << "1分  : " << a << "张" << endl;

	return 0;
}