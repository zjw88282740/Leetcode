/*Description

    有一枚特殊硬币，这枚硬币掷出正面的概率为p，反面的概率为1-p。

    现在开始掷硬币，直到正反两面均出现过时停下。问掷硬币的期望次数。

    输入数据第一行包含一个整数T<=20，表示测试组数，

     
Input

    第一行包含一个 数字T，表明测试数据的组数。

    接下来是T行，

    每行测试数据包含一个精确到千分位的实数p（0<p<1）。

     
Output

    每组数据输出一行，包含一个整数，表示期望次数四舍五入到整数的值。

     
Sample Input

    1
    0.500

Sample Output

    3

Hint

    附：期望次数 = ∑掷硬币次数 * 该次数出现的概率（掷硬币次数>=2）
*/
#include <stdio.h>
#include <math.h>

double fun(float);

int main(void)
{
	int T;
	scanf("%d",&T);
	double a[20],p,x;
	for(int i=0;i<T;i++)
	{
		scanf("%lf",&a[i]);
	}
	for(int i=0;i<T;i++)
	{
		p=a[i];
		x=fun(p);
		x=x+0.5;
		printf("%d\n",(int)x);
	}
	return 0;
}

double fun(float p)
{
	double sum=0;
	for(int i=2;;i++)
	{
		double sum_prev;
		sum_prev=sum;
		sum=i*(pow(p,i-1)*(1-p)+p*pow(1-p,i-1))+sum;
		//printf("%lf %lf",sum,sum_prev);
		if(sum-sum_prev<0.001)
		{
			return sum;
		}
		else
			continue;
	}
}
