#include <stdio.h>
#include <math.h>

void NhapSND(int &n)
{
	do
	{
		printf("Nhap so nguyen duong n= ");
		scanf_s("%d", &n);
	} while (!(n > 0));
}

void USMax(int n)
{
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0)
		{
			if (i > max)
			{
				max = i;
			}
			printf("\ni= %d la uoc so", i);
		}
	}
	printf("\n%d la US lon nhat", max);
}

int USLMax(int n)
{
	int max = 0;
	for (int i = 1; i <= n; i++)
	{
		if (n % i == 0 && i % 2 == 1)
		{
			if (i > max)
			{
				max = i;
			}
		}
	}
	printf("\n%d la US le lon nhat", max);
	return max;
}

void main()
{
	int n;
	NhapSND(n);
	//USMax(n);
	//USLMax(n);
	for (int i = n / 2; i >= 1; i--)
	
	{
		if (n % i == 0 && i % 2 == 1)
		{
			printf("\n%d la US le lon nhat", i);
			break;
		}
	}
}