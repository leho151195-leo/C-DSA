#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100

struct SinhVien
{
	int MaSo;
	char HoTen[MAX];
	int NamSinh;
	float DTB;
};

void TaoSinhVien(SinhVien SVs[MAX], int& n)
{
	n = 10;
	SVs[0] = { 1, "Nguyen Tri Phuong", 2002, 8.9 };
	SVs[1] = { 2, "Nguyen Trai", 2003, 4 };
	SVs[2] = { 3, "Nguyen Thi Minh Khai", 2005, 6 };
	SVs[3] = { 4, "Tran Phu", 2001, 6 };
	SVs[4] = { 5, "An Duong Vuong", 1999, 7.9 };
	SVs[5] = { 6, "Au Co", 2005, 9 };
	SVs[6] = { 7, "Lac Long Quan", 2001, 6 };
	SVs[7] = { 8, "Thanh Thai", 1999, 8 };
	SVs[8] = { 9, "Duy Tan", 2001, 8.2 };
	SVs[9] = { 10, "Minh Mang", 1997, 4.5 };
}

void InHeader()
{
	printf("\n %-10s %-25s %-15s %-10s", "Ma So", "Ho Ten", "Nam Sinh", "DTB");
}

void InSinhVien(SinhVien SV)
{
	printf("\n %-10d %-25s %-15d %-10.2f", SV.MaSo, SV.HoTen, SV.NamSinh, SV.DTB);
}

void InMangSV(SinhVien SVs[MAX], int n)
{
	printf("\nMang 1 chieu Sinh Vien: \n");
	InHeader();
	for (int i = 0; i < n; i++)
	{
		InSinhVien(SVs[i]);
	}
}

void InSinhVienTheoDTB(SinhVien SVs[MAX], int n, float DTB)
{
	printf("\n\nDanh sach sinh vien co DTB >= %0.2f \n", DTB);
	InHeader();
	for (int i = 0; i < n; i++)
	{
		if (SVs[i].DTB >= DTB)
			InSinhVien(SVs[i]);
	}
}

void SapXepTangTheoDTB(SinhVien SVs[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SVs[i].DTB > SVs[j].DTB)
			{
				SinhVien temp = SVs[i];
				SVs[i] = SVs[j];
				SVs[j] = temp;
			}
		}
	}
}

void SapXepTangTheoNamSinh(SinhVien SVs[MAX], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (SVs[i].NamSinh > SVs[j].NamSinh)
			{
				SinhVien temp = SVs[i];
				SVs[i] = SVs[j];
				SVs[j] = temp;
			}
		}
	}
}


void main()
{
	SinhVien SVs[MAX];
	int n;
	TaoSinhVien(SVs, n);
	InMangSV(SVs, n);

	SapXepTangTheoNamSinh(SVs, n);
	InMangSV(SVs, n);
}