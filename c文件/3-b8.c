/* 1951559 计算机 谢佳依*/
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c;
	long sum, num = 0;
	_Bool _1, _2, _3, _4, _5, _6, _7, _8, _9;
	for (a = 123; a < 651; a++)
	{
		for (b = 123; b < 877; b++)
		{
			for (c = 651; c < 988; c++)
			{
				if (!(a < b && b < c))
					continue;
				if (a + b + c != 1953)
					continue;
				_1 = _2 = _3 = _4 = _5 = _6 = _7 = _8 = _9 = 0;
				sum = a * 1000000 + b * 1000 + c;
				for (int i = 0; i < 9; i++)
				{
					switch (sum % 10)
					{
						case 1:
							_1 = 1;
							break;
						case 2:
							_2 = 1;
							break;
						case 3:
							_3 = 1;
							break;
						case 4:
							_4 = 1;
							break;
						case 5:
							_5 = 1;
							break;
						case 6:
							_6 = 1;
							break;
						case 7:
							_7 = 1;
							break;
						case 8:
							_8 = 1;
							break;
						case 9:
							_9 = 1;
							break;
						default:
							break;
					}
					sum /= 10;
					if (_1 && _2 && _3 && _4 && _5 && _6 && _7 && _8 && _9)
					{
						num++;
						printf("No.%3d", num);
						printf(" : %d+%d+%d=1953\n", a, b, c);
					}
				}
			}
		}
	}
	printf("total=%d\n", num);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}