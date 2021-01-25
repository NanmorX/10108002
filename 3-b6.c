/* 1951559 计算机 谢佳依 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int status;

	while (1) {
		printf("请输入x的值[0-100] : ");
		status = scanf("%d", &x); //读入x的方式scanf且格式符为%d

		if (!status)
		{
			rewind(stdin);
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
		else
		{
			//rewind(stdin);
			continue;
		}
	}

	printf("x=%d\n", x);

	return 0;
}