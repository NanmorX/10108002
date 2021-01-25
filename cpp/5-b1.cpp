/* 1951559 计算机 谢佳依 */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int score[1005];
	int total[101];
	memset(total, 0, sizeof(total));
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	cin >> score[0];
	while (score[0] < 0)
	{
		cout << "无有效输入" << endl;
		cin >> score[0];
	}
	int i = 1;
	while (1)
	{
		cin >> score[i];
		if (score[i] == -1)
		{
			i--;
			break;
		}
		i++;
	}
	cout << "输入的数组为:" << endl;
	for (int j = 0; j <= i; j++)
	{
		cout << score[j] << " ";
		total[score[j]]++;
		if ((j + 1) % 10 == 0 || j == i)
			cout << endl;
	}
	cout << "分数与人数的对应关系为:" << endl;
	for (int i = 100; i >= 0; i--)
	{
		if (total[i] != 0)
			cout << i << " " << total[i] << endl;
	}

	return 0;
}