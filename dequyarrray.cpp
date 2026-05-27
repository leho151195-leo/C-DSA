#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void taoMangLtoR(int A[], int n) {
    if (n<=0) return;
    taoMangLtoR(A,n-1);
    A[n-1]=rand()%10;
    printf("%d\t", A[n-1]);
}
void taoMangRtoL(int A[], int n) {
    if (n<=0) return;
    printf("A[%d]= ", n-1);
    scanf("%d", &A[n-1]);
    taoMangRtoL(A,n-1);
    printf("%d\t", A[n-1]);
}
void xuatLe(int A[], int n) {
    if (n<=0) return;
    xuatLe(A,n-1);
    if (A[n-1]%2!=0) {
        printf("%d\t", A[n-1]);
    }
    else printf("X\t");
}
int tong(int A[], int n) {
    if (n<=0) return 0;
    return tong(A,n-1)+A[n-1];
}
int demLe(int A[], int n) {
    if (n<=0) return 0;
    if (A[n-1]%2!=0) {
        return demLe(A,n-1)+1;
    }
    return demLe(A,n-1);
}
int demX(int A[], int n,int x) {
    if (n<=0) return 0;
    if (A[n-1]==x) {
        return demX(A,n-1,x)+1;
    }
    return demX(A,n-1,x);
}
int chanDau(int A[], int n) {
    if (n<0) return -1;
    if (A[n]%2==0) {
        return A[n];
    }
    return chanDau(A,n-1);
}
int chanCuoi(int A[], int n) {
    if (n<=0) return -1;
    if (A[n-1]%2==0) {
        return A[n-1];
    }
    return chanCuoi(A,n-1);
}
int main() {
    srand(time(NULL));
    int A[100];
    int n,x;
    printf("Nhập n: ");
    scanf("%d", &n);
    printf("Mảng random: \n");
    taoMangLtoR(A,n);
    printf("\nMảng lẻ: \n");
    //taoMangRtoL(A,n);
    xuatLe(A,n);
    printf("\nTổng: %d\n", tong(A,n));
    printf("Số lần xuất hiện của số lẻ: %d\n", demLe(A,n));
    printf("Nhập x: ");
    scanf("%d", &x);
    printf("Số lần xuất hiện của số %d: %d\n",x, demX(A,n,x));
    printf("Số chẵn đầu tiên: %d\n", chanDau(A,n));
    printf("Số chẵn cuối cùng: %d\n", chanCuoi(A,n));
}