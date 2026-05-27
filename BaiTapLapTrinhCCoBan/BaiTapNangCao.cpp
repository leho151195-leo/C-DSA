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

void XoaTrangTrai(char* s)
{
	int len = strlen(s);
	while (s[0] == ' ')
	{
		strcpy(s, s + 1);
	}
	printf("\n\"%s\"", s);
}

void XoaTrangPhai(char* s)
{
	int len = strlen(s);
	while (s[strlen(s) - 1] == ' ')
	{
		s[strlen(s) - 1] = '\0';
	}
	printf("\n\"%s\"", s);
}

void XoaTrangGiua(char* s)
{
	char* p;
	p = strstr(s, "  ");
	while (p != NULL)
	{
		strcpy(p, p + 1);
		p = strstr(s, "  ");
	}
	printf("\n\"%s\"", s);
}

void main()
{
	char s[MAX];
	NhapChuoi(s);
	//XoaTrangTrai(s);
	//XoaTrangPhai(s);
	XoaTrangGiua(s);
}