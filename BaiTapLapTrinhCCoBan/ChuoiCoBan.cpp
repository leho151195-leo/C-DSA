#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define MAX 100
void main()
{
	char s1[MAX] = "Trung Tam Tin Hoc";//Khai báo chuỗi
	char s2[MAX] = "Cam On Cac Ban";//Khai báo chuỗi
	char s3[MAX] = "H";
	char s4[MAX] = "h";

	printf("\n s1 = \"%s\" ", s1);   //In chuỗi
	printf("\n s2 = \"%s\" ", s2);   //In chuỗi

	//printf("\n strlen = %d ", strlen(s1)); //Số kí tự trong chuỗi
	//printf("\n strcat = \"%s\" ", strcat(s1, s2)); //Ghép 2 chuỗi
	//printf("\n strcpy = \"%s\" ", strcpy(s1, s3)); //Chuỗi 3 đè lên chuỗi 1
	//printf("\n strcmp = %d ", strcmp(s1,s2)); //So sánh 2 chuỗi lớn hay nhỏ
	printf("\n _stricmp = %d ", _stricmp(s1, s2));
}