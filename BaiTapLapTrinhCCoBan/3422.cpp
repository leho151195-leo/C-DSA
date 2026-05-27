#include <stdio.h>
void main()
{
	int n;
	printf("Nhap so nguyen n= ");
	scanf_s("%d", &n);
	if (n % 2 == 0)
		printf("\nn= %d", n * 2);

}