#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 100

struct NgayThang
{
	int Ngay, Thang, Nam;
};

struct NhanVien
{
	int MaNhanVien;
	char TenNhanVien[50];
	NgayThang NamSinh; //struct NgayThang
	int GioiTinh; //Nam=1, Nu=0
	float Luong; //10=10T
};

void TaoNhanVien(NhanVien NVs[MAX], int& n)
{
	n = 10;
	NVs[0] = {1, "Nguyen Tri Phuong", {1, 2,2004}, 1, 10};
	NVs[1] = {2, "Nguyen Trai", {1,5,2003}, 1, 15 };
	NVs[2] = {3, "Nguyen Thi Minh Khai", {1, 1,2003}, 1, 7};
	NVs[3] = {4, "Tran Phu", {1, 1,1992}, 1, 8 };
	NVs[4] = {5, "An Duong Vuong", {23, 1,2003}, 1, 7};
	NVs[5] = {6, "Au Co", {4, 1,2003}, 1, 15};
	NVs[6] = {7, "Lac Long Quan", {1, 7,2001}, 1, 22};
	NVs[7] = {8, "Thanh Thai", {1, 1,2000}, 1, 4};
	NVs[8] = {9, "Duy Van Tan", {1, 12,2003}, 1, 3};
	NVs[9] = {10, "Minh Van Mang", {24, 12,1996}, 1, 2};
}

void InHeader()
{
	printf("\n %-10s %-25s %-15s %-15s %-12s", "MaNV", "TenNV", "NamSinh", "GioiTinh", "Luong");
}

void InNhanVien(NhanVien NV)
{
	char GT[5];
	if (NV.GioiTinh == 1)
	{
		strcpy(GT, "NAM");
	}
	else strcpy(GT, "NU");
	printf("\n %-10d %-25s %d/%d/%d %15s %12.2f", 
		NV.MaNhanVien, NV.TenNhanVien, NV.NamSinh.Ngay, NV.NamSinh.Thang, NV.NamSinh.Nam, GT, NV.Luong);
}

void InMangNV(NhanVien NVs[MAX], int n)
{
	printf("\nMang 1 chieu Nhan Vien: \n");
	InHeader();
	for (int i = 0; i < n; i++)
	{
		InNhanVien(NVs[i]);
	}
}

void InTheoTuoi(NhanVien NVs[MAX], int n)
{
	printf("\nMang 1 chieu Nhan Vien tren 25 tuoi: \n");
	InHeader();
	for (int i = 0; i < n; i++)
	{
		int tuoi;
		tuoi = 2026 - NVs[i].NamSinh.Nam;
		if (tuoi>25)
		InNhanVien(NVs[i]);
	}
}

void InTheoLuong(NhanVien NVs[MAX], int n)
{
	printf("\nMang 1 chieu Nhan Vien luong tren 10T: \n");
	InHeader();
	for (int i = 0; i < n; i++)
	{
		int luong;
		luong = NVs[i].Luong;
		if (luong > 10)
			InNhanVien(NVs[i]);
	}
}

void LuongGiamDan(NhanVien NVs[MAX], int n)
{
	printf("\nMang 1 chieu Nhan Vien luong giam dan: \n");
	InHeader();
	for (int i = 0; i < n; i++)
	{
		int luong;
		luong = NVs[i].Luong;
		if (luong > 10)
			InNhanVien(NVs[i]);
	}
}

int main()
{
	int n = 0;
	NhanVien NVs[MAX];
	TaoNhanVien(NVs, n);
	InMangNV(NVs, n);
	InTheoLuong(NVs, n);
}