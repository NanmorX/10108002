/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <cmath>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	cout << "请输入[0-100亿)之间的数字：" << endl;
	double k, precious = 0.0, inter = 0;
	cin >> k;

	//计算得到每一位的值
	precious = modf(k, &inter);
	long long k1, k2;                                //k1整数部分，k2小数部分 
	k1 = static_cast<long long> (inter);
	k2 = static_cast<long long> (precious * 1000) + 1;
	k2 /= 10;
	int a0, a1, a2, a3, a4, a5, a6, a7, a8, a9;
	int b0, b1;
	a9 = static_cast<int>(k1 / 1000000000);
	k1 = k1 - static_cast<long long>(a9) * 1000000000;
	a8 = static_cast<int>(k1 / 100000000);
	k1 = k1 - static_cast<long long>(a8) * 100000000;
	a7 = static_cast<int>(k1 / 10000000);
	k1 = k1 - static_cast<long long>(a7) * 10000000;
	a6 = static_cast<int>(k1 / 1000000);
	k1 = k1 - static_cast<long long>(a6) * 1000000;
	a5 = static_cast<int>(k1 / 100000);
	k1 = k1 - static_cast<long long>(a5) * 100000;
	a4 = static_cast<int>(k1 / 10000);
	k1 = k1 - static_cast<long long>(a4) * 10000;
	a3 = static_cast<int>(k1 / 1000);
	k1 = k1 - static_cast<long long>(a3) * 1000;
	a2 = static_cast<int>(k1 / 100);
	k1 = k1 - static_cast<long long>(a2) * 100;
	a1 = static_cast<int>(k1 / 10);
	k1 = k1 - static_cast<long long>(a1) * 10;
	a0 = static_cast<int>(k1 / 1);

	b1 = static_cast<int>(k2) / 10;
	k2 = k2 - static_cast<long long>(b1) * 10;
	b0 = static_cast<int>(k2) / 1;

	if (!a9 && !a8 && !a7 && !a6 && !a5 && !a4 && !a3 && !a2 && !a1 && !a0 && !b1 && !b0)
	{
		daxie(0, 1);
		cout << "圆整" << endl;
		return 0;
	}
	
	daxie(a9,0);
	if (a9 != 0)
	{
		cout << "拾";
	}
	daxie(a8, 0);
	if (a8+a9 != 0)
	{
		cout << "亿";
	}


	daxie(a7, (a8 + a9 != 0)&&(a6 + a5 + a4 != 0));
	if (a7 != 0)
	{
		cout << "仟";
	}
	daxie(a6,a7 && a5+a4!=0 );
	if (a6 != 0)
	{
		cout << "佰";
	}
	daxie(a5, a4 && a6);
	if (a5 != 0)
	{
		cout << "拾";
	}
	daxie(a4, 0);
	if (a7+a6+a5+a4)
	{
		cout << "万";
	}


	daxie(a3, (a2 + a1 + a0) && (a9 + a8 + a7 + a6 + a5 + a4));
	if (a3 != 0)
	{
		cout << "仟";
	}
	daxie(a2, a3 && a1 + a0 != 0);
	if (a2 != 0)
	{
		cout << "佰";
	}
	daxie(a1, a2 && a0);
	if (a1 != 0)
	{
		cout << "拾";
	}
	daxie(a0, 0);
	if (a0 != 0 || a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1)
	{
		cout << "圆";
	}


	//分割线
	if (b1 == 0 && b0 == 0)
	{
		cout << "整" << endl;
		return 0;
	}
	daxie(b1, a9+a8+a7+a6+a5+a4+a3+a2+a1+a0);
	if (b1 != 0)
	{
		cout << "角";
	}
	daxie(b0, 0);
	if (b0 != 0)
	{
		cout << "分";
	}
	else
	{
		if (a9 + a8 + a7 + a6 + a5 + a4 + a3 + a2 + a1 + a0 + b1)
			cout << "整" ;
	}
	cout << endl;

	return 0;
}
