#include <iostream>
int main()
{
	int n;
	int snd=0;
	int temp=0;
	printf("Nhap so n: ");
	scanf("%d", &n);
	while (n>0)
	{
		temp =n%10;
		snd=snd*10+temp;
		n/=10;
	}
	printf("\n------\n%d", snd);
	return 0;
}