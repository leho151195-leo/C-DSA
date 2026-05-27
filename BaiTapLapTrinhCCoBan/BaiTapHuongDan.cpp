#include <stdio.h>
void main()
{
	char ch;
	printf("Nhap ch: ");
	scanf_s("%c", &ch);
	if (ch >= '0' && ch <= '9')
		printf("\nDay la ky tu so");
	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		printf("\nDay la ky tu chu cai");
	else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%')
		printf("\nDay la ky tu phep toan");
	else printf("\nDay la ky tu dang khac");


}