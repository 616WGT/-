#include<stdio.h>
#include<iostream>
using namespace std;
int a[4] = { 1,1,1,1 };
int question(int A, int k, int count, int s)
{
	
	int h = 0;
	int x;
	int r;
	int flag1 = 1;
	int flag2 = 0;
	int flag3 = 0;
	if (A == 1)
	{
		h = 10;
	}
	else if (A == 2)
	{
		h = 100;
	}
	else if (A == 3)
	{
		h = 1000;
	}
	for (int i = 0; i < count; i++)
	{
		printf("(%d) ", i + 1);
		
		r = rand() % 7 + 2;
		for (int j = 0; j < r + 1; j++)
		{
			flag3 = 0;
			if (j != r)
			{
				if (flag3 == 0) 
				{
					if (k == 1 && flag2 == 0 && rand() % 2 == 1)
					{
						printf(" ( ");

						flag2 = 1;
						flag1 = 1;
					}
					if (s == 1)
					{
						printf("%d", rand() % h);

					}
					else
					{
						printf("%.2f", rand() / (double)(RAND_MAX / h));

					}
					if (k == 1 && flag2 == 1 && rand() % 2 == 1 && flag1 != 1)
					{
						printf(" ) ");

						flag2 = 0;
					}
					flag1 = 0;
					flag3 = 1;
				}
				while(1)
				{
					x = rand() % 4;
					switch (x)
					{
					
					case 0:
						if (a[0] == 1)
						{
							printf(" + ");
							flag3 = 0;
							break;
						}

					case 1:
						if (a[1] == 1)
						{
							printf(" - ");
							flag3 = 0;
							break;
						}
					case 2:
						if (a[2] == 1)
						{
							printf(" * ");
							flag3 = 0;
							break;
						}
					case 3:
						if (a[3] == 1)
						{
							printf(" / ");
							flag3 = 0;
							break;
						}
					}
					if (flag3 == 0)
						break;
				}
			}
			else
			{
				printf("%d ", rand() % h);
				
				if (flag2 == 1)
				{
					printf(" ) ");
					
					flag2 = 0;
				}
				printf(" = ?\n");
				
			}
		}
	}
	return 0;
}

void set(int i, int j, int m, int n)
{
	a[0] = i;
	a[1] = j;
	a[2] = m;
	a[3] = n;
}
int main()
{
	int q, w, e, r;
	int i, j, m, n;
	cout << "请选择是否有加减乘除运算符  1为需要  0为不需要   输入例如：1  1  0   1" << endl;
	cin >> i >> j >> m >> n;
	set(i, j, m, n);
	cout << "请选择最大值    1为10   2为100   3为1000" << endl;
	cin >> q;
	cout << "请选择有无括号    1有   0为无" << endl;
	cin >> w;
	cout << "请选择整数还是小数    1为整数   0为小数" << endl;
	cin >> r;
	cout << "请输入题目数量：" << endl;
	cin >> e;
		question(q, w, e, r);
		cout << endl << a[3];
	return 0;
}

