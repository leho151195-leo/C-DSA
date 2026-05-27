#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100

void NhapChuoi(char* s)
{
	printf("Nhap chuoi: ");
	fgets(s, MAX, stdin); //se bi thua dau /n 
	int len = strlen(s); //cach giai quyet xoa /n
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
}

void ChuyenHoa(char* s)
{
	int len = strlen(s);
	for (int i = 0; i < len;i++)
	{
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	}
	printf("\n\"%s\"", s);
}

void ChuyenThuong(char* s)
{
	int len = strlen(s);
	for (int i = 0; i < len;i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	}
	printf("\n\"%s\"", s);
}

void InHoaChuDau(char* s)
{
	int len = strlen(s);
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			if (s[i] != ' ')
				if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
		}
		else
		{
			if (s[i] != ' ' && s[i - 1] == ' ')
			{
				if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			}
			else
			{
				if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] += 32;
			}
		}
	}
	printf("\n\"%s\"", s);
}

int main()
{
	char s[MAX];
	NhapChuoi(s);
	//ChuyenHoa(s);
	//ChuyenThuong(s);
	InHoaChuDau(s);
	return 0;
}