// Viết các hàm sau
// 1. Nhập mảng, random mảng, in mảng 2 chiều
// 2. In những phần tử là số nguyên tố trong mảng
// 3. Xử lý trên dòng
// a. In những phần tử trên dòng x (x nhập từ bàn phím)
// b. Tìm phần tử lớn nhất trên dòng x
// c. Tính tổng các phần tử trên dòng x	
// 4. Xử lý trên cột
// a. In những phần tử trên cột x (x nhập từ bàn phím)
// b. Tìm phần tử lớn nhất trên cột x
// c. Tính tổng các phần tử trên cột x

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int KiemTraSNT(int n)
{
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i*i <= n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void nhapmang2chieu(int a[MAX][MAX], int &m, int &n)
{
	do
	{
		printf("Nhap so dong m= ");
		scanf("%d", &m);
		printf("Nhap so cot n= ");
		scanf("%d", &n);
	} while (!(m > 0 && m <= MAX && n > 0 && n <= MAX));
}

void nhapphantu(int a[MAX][MAX], int &m, int n)
{
	for (int i = 0; i < m;i++)
		for (int j = 0; j < n;j++)
		{
			printf("\na[%d][%d]= ", i, j);
			scanf("%d", &a[i][j]);
		}
}

void randommang2chieu(int a[MAX][MAX], int& m, int &n)
{
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			a[i][j] = (rand() % 20) + 1;
		}
	}
}

void inmang2chieu(int a[MAX][MAX], int& m, int& n)
{
	printf("\nMang 2 chieu: \n");
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	srand(int(time(NULL)));
	int a[MAX][MAX];
	int m, n;
	nhapmang2chieu(a, m, n);
	randommang2chieu(a, m, n);
	inmang2chieu(a, m, n);

	int temp = KiemTraSNT(a[m][n]);
	if (temp == 1)
	{
		inmang2chieu(a, m, n);
	}
}