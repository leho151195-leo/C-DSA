#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100

struct SinhVien
{
	int Ma;
	char Ten[100];
	int NamSinh;
	float DTB;
};

void NhapSinhVien(SinhVien& sv)
{
	printf("\n Nhap Ma: ");
	scanf("%d", &sv.Ma);
	printf("\n Nhap Ten: ");
	getchar();
	gets_s(sv.Ten);
	printf("\n Nhap Nam sinh: ");
	scanf("%d", &sv.NamSinh);
	printf("\n Nhap DTB: ");
	scanf("%f", &sv.DTB);
}

void InSinhVien(SinhVien sv)
{
	printf("\n %-02d %-20s %-10d %-5.2f", sv.Ma, sv.Ten, sv.NamSinh, sv.DTB);
}

void InHeader()
{
	printf("\n %-2s %-20s %-10s %-5s", "Ma", "Ten", "Nam Sinh", "DTB");
}

void NhapTongSoPhanTu(int& n)
{
	do
	{
		printf("\nNhap tong so phan tu: ");
		scanf("%d", &n);
	} while (!(n > 0 && n <= MAX));
}

void NhapMang(SinhVien sinhViens[MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n Nhap thong tin sinh vien [sv%d] = ", i);
		NhapSinhVien(sinhViens[i]);
	}
}

void InMang(SinhVien sinhViens[MAX], int n)
{
	printf("\nMang 1 chieu sinh vien\n ");
	InHeader();
	for (int i = 0; i < n; i++)
	{
		// printf("\n Thong tin sinh vien [sv%d] = ", i);
		InSinhVien(sinhViens[i]);
	}
}

void TaoMangSinhVien(SinhVien sinhViens[MAX], int& n)
{
	n = 8;
	sinhViens[0] = { 1, "Nguyen Tri Phuong", 2002, 8.9 };
	sinhViens[1] = { 2, "Nguyen Trai", 2003, 2 };
	sinhViens[2] = { 3, "Nguyen Thi Minh Khai", 2005, 6 };
	sinhViens[3] = { 4, "Tran Phu", 2001, 6 };
	sinhViens[4] = { 5, "An Duong Vuong", 1999, 7.9 };
	sinhViens[5] = { 6, "Au Co", 2005, 6 };
	sinhViens[6] = { 7, "Lac Long Quan", 2001, 6 };
	sinhViens[7] = { 8, "Thanh Thai", 1999, 7.9 };
}

void InSinhVienTheoDTB(SinhVien sinhViens[MAX], int n, float DTB)
{
	printf("\n\nDanh sach sinh vien co DTB >= %0.2f \n", DTB);
	InHeader();
	for (int i = 0; i < n; i++)
	{
		if (sinhViens[i].DTB >= DTB)
			InSinhVien(sinhViens[i]);
	}
}

void main()
{
	SinhVien sinhViens[MAX];
	int n = 0;

	// NhapTongSoPhanTu(n);
	// NhapMang(sinhViens, n);
	TaoMangSinhVien(sinhViens, n);
	InMang(sinhViens, n);

	float DTB = 8.0;
	InSinhVienTheoDTB(sinhViens, n, DTB);
}
