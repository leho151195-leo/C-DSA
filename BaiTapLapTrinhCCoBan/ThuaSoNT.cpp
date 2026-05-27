#include <stdio.h>
#include <math.h>

void NhapSND(int& n)
{
	do
	{
		printf("Nhap so nguyen duong n= ");
		scanf_s("%d", &n);
	} while (!(n >= 2));
}

int KiemtraSNT(int n)
{
	if (n == 2)
		return 1;
	if (n < 2 || n % 2 == 0)
		return 0;
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void main()
{
	int n;
	NhapSND(n);
	printf(" %d = ", n);
	int i = 2;
	int dem = 0;
	while (i != 1)
	{
		if (n%i==0)
		{
			n=n/i;
			dem++;
			
			if (n % i != 0)
			{
				if (dem > 1)
					printf(" %d^%d ", i, dem);
				else printf(" %d ", i);

				if (n != 1)
					printf(" x ");
			}
		}
		else
		{
			dem = 0;
			do
			{
				i++;
			} while (KiemtraSNT(i) == 0);
		}
	}
}


