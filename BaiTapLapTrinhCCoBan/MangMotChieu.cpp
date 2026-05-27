// Viết các hàm sau:
	// 1. Nhập giá trị các phần tử từ bàn phím
	// a. Nhập giá trị các phần tử từ bàn phím
	// b. Nhập giá trị các phần tử sao cho mảng toàn giá trị chẵn
	// c. Nhập giá trị các phần tử sao cho các phần tử trong mảng có giá trị tăng dần
	// 2. Random giá trị các phần tử 
	// a. Random giá trị các phần tử
	// b. Random giá trị các phần tử sao cho mảng toàn lẻ
	// c. Random giá trị các phần tử sao cho mảng toàn số nguyên tố
	// d. Random giá trị các phần tử sao cho mảng có giá trị luôn luôn tăng dần
	// e. Random giá trị các phần tử sao cho giá trị từ 50 -> 100
	// e. Random giá trị các phần tử sao cho giá trị từ -100 -> +100
	// 3. In giá trị các phần tử trong mảng
	// a. In giá trị các phần tử trong mảng
	// b. In giá trị các phần chẵn trong mảng
	// c. In giá trị các phần tử là số nguyên tố trong mảng
	// 4. Tính tổng / trung bình
	// a. Tính tổng các phần tử trong mảng
	// b. Tính trung bình cộng các phần tử chẵn trong mảng
	// 5. Tìm max / min
	// a. Tìm giá trị lớn nhất trong mảng
	// b. Tìm giá trị CHẴN lớn nhất trong mảng
	// c. Tìm số nguyên tố nhỏ nhất trong mảng
	// d. Tìm số lẻ nhỏ nhất lớn hơn tất cả các giá trị chẵn trong mảng
	// vd: 2 4 3 6 7 9 11 -> số lẻ nhỏ nhất lớn hơn tất cả các giá trị chẵn trong mảng là: 7

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int KiemTraSNT(int n)
{
	if (n == 2)
	{
		return 1;
	}
	if (n < 2)
	{
		return 0;
	}
	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}
	return 1;
}

void NhapTongSoPT(int& n)
{
	do
	{
		printf("Nhap tong so phan tu: ");
		scanf("%d", &n);
	} while (!(n > 0));
}

void NhapPhanTu(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\nNhap a[% d] = ", i);
		scanf("\%d", &a[i]);
	}
}

void RandomPhanTu(int a[MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = (rand() % 20) + 1;
	}
}

void InMang1Chieu(int a[MAX], int n)
{
	printf("\n\nMang 1 chieu");
	for (int i = 0; i < n; i++)
	{
		printf("\na[%d] = %d\t", i, a[i]);
	}
}

void themcuoi(int a[MAX], int& n, int x)
{
	a[n] = x;
	n++;
}

void themdau(int a[MAX], int& n, int x)
{
	for (int i = n; i >0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = x;
	n++;
}

void themvitri(int a[MAX], int& n, int vt, int x)
{
	for (int i = n; i > vt; i--)
	{
		a[i] = a[i - 1];
	}
	a[vt] = x;
	n++;
}

void xoacuoi(int a[MAX], int& n)
{
	n--;
}

void xoadau(int a[MAX], int& n)
{
	for (int i = 0; i < n-1;i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void xoavitri(int a[MAX], int& n, int vt)
{
	for (int i = vt; i < n - 1;i++)
	{
		a[i] = a[i + 1];
	}
	n--;
}

void dichtrai(int a[MAX], int& n)
{
	int temp = a[0];
	for (int i = 0; i < n - 1;i++)
	{
		a[i] = a[i + 1];
	}
	a[n - 1] = temp;
}

void dichphai(int a[MAX], int& n)
{
	int temp = a[n - 1];
	for (int i = n; i > 0; i--)
	{
		a[i] = a[i - 1];
	}
	a[0] = temp;
}

void main()
{
	srand(int(time(NULL)));
	int a[MAX];
	int n = 0;

	NhapTongSoPT(n);
	RandomPhanTu(a, n);
	InMang1Chieu(a, n);

	int x = 111;
	int vt = 2;
	dichphai(a, n);
	InMang1Chieu(a, n);

}