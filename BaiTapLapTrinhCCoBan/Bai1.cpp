#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int KiemTraSNT(int n)
{
	if (n < 2)
		return 0;
	for (int i = 2; i <n; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}

void NhapMaTranVuong(int a[MAX][MAX], int &m, int& n)
{
	do
	{
		printf("Nhap so cot va dong nxn = ");
		scanf("%d", &n);
	} while (!(n > 0 && n <= MAX));
	m = n;
}

void RandomPhanTu(int a[MAX][MAX], int& m, int& n)
{
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			a[i][j] = (rand() % 20) + 1;
		}
	}
}

void InMaTranVuong(int a[MAX][MAX], int& m, int& n)
{
	printf("\nMa Tran Vuong: \n");
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
}

void InSNTDuongCheoPhu(int a[MAX][MAX], int& m, int& n)
{
	printf("\n\n");
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			int temp = KiemTraSNT(a[i][j]);
			if (i + j == (n - 1)&&temp==1)
				printf("%d \t", a[i][j]);
			else
				printf(" \t");
		}
		printf("\n");
	}
}

void InSoLonThu2(int a[MAX][MAX], int& m, int& n)
{
	printf("\nSo lon nhat Max= ");
	int max = 0;
	int temp = 0;
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (a[i][j] > max)
				max = a[i][j];
		}
	}
	printf("%d", max);
	printf("\nSo lon thu hai = ");
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			if (a[i][j] > temp&& a[i][j]<max)
				temp = a[i][j];
		}
	}
	printf("%d", temp);
}

void TongChuSo(int a[MAX][MAX], int& m, int& n)
{
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{
			int tong = 0;
			int temp = a[i][j];
			while (temp != 0)
			{
				tong += temp%10;
				temp /= 10;
			}
			printf("\nTong cac chu so a[%d][%d]= %d la %d", i, j, a[i][j], tong);
		}
	}
}

void InBienVaTongBien(int a[MAX][MAX], int& m, int& n)
{
	printf("\n\n");
	int tong = 0;
	for (int i = 0; i < m;i++)
	{
		for (int j = 0; j < n;j++)
		{			
			if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
			{
				printf("%d \t", a[i][j]);
				tong += a[i][j];
			}
			else
				printf("   \t");
			
		}
		printf("\n");
	}
	printf("Tong bien = %d", tong);
}

void SapXepMaTran(int a[MAX][MAX], int& m, int& n)
{
	printf("\n\n");
		for (int j = 0; j < n;j++)
		{
			if (j % 2 == 0)
			{
				for (int x = 0;x < m - 1;x++)
				{
					for (int y = x + 1; y < m;y++)
					{
						int temp = a[x][j];
						{
							if (a[x][j] < a[y][j])
							{
								a[x][j] = a[y][j];
								a[y][j] = temp;
							}
						}
					}
				}
			}
		}
		printf("sắp xếp ma trận\n");
	InMaTranVuong(a, m, n);
}

int main()
{
		srand(int(time(NULL)));
		int a[MAX][MAX];
		int m, n;
		NhapMaTranVuong(a, m, n);
		RandomPhanTu(a, m, n);
		InMaTranVuong(a, m, n); //1.a
		InSNTDuongCheoPhu(a, m, n); //1.b
		InSoLonThu2(a, m, n); //1.c
		TongChuSo(a, m, n); //1.d
		InBienVaTongBien(a, m, n); //1.e
		SapXepMaTran(a, m, n); //1.f

		return 0;
}