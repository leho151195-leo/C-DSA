#include <stdio.h>
void main()
{
	float x, y;
	printf("Nhap x= ");
	scanf_s("%f", &x);
	printf("\nNhap y= ");
	scanf_s("%f", &y);
	printf("\n%0.2f + %0.2f = %0.2f", x, y, x + y);
	printf("\n%0.2f - %0.2f = %0.2f", x, y, x - y);
	printf("\n%0.2f x %0.2f = %0.2f", x, y, x * y);
	if (y == 0)
		printf("\n%0.2f : 0 khong hop le", x);
	else printf("\n%0.2f : %0.2f = %0.2f", x, y, x / y);

}