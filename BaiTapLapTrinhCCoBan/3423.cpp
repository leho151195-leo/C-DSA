#include <stdio.h>
void main()
{
	int n;
	printf("Nhap so nguyen n= ");
	scanf_s("%d", &n);
	if (n >= 6)
		printf("%d", n + 2);
	else printf("0");
}