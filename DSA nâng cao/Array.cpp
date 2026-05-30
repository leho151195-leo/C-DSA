#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
void taoMang(int A[], int n) {
    printf("-----Mảng A: ");
    for (int i=0; i<n; i++) {
        A[i]=rand()%100;
        printf("%d\t", A[i]);
    }
}
void xuatNguoc(int A[], int n) {
    printf("-----Mảng ngược: ");
for (int i=n-1; i>=0; i--) {
        printf("%d\t", A[i]);
    }
}
void xuatLe(int A[], int n) {
    printf("\n-----Mảng lẻ: ");
    for (int i=0; i<n; i++) {
        if (A[i]%2!=0) {
        printf("%d\t", A[i]);
        }
        else {
            printf("x\t");
        }
    }
}
int tong(int A[], int n) {
    int tong=0;
    for (int i=0; i<n; i++) {
        tong=tong+A[i];
    }
    return tong;
}
int demLe(int A[], int n) {
    int dem=0;
    for (int i=0; i<n; i++) {
        if (A[i]%2!=0) {
            dem++;
        }
    }
    return dem;
}
int demX(int A[],int n, int x) {
    printf("\nNhập x: ");
    scanf("%d", &x);
    int dem=0;
    for (int i=0; i<n; i++) {
        if (A[i]==x) {
            dem++;
        }
    }
    return dem;
}
int timChan(int A[], int n) {
    for (int i=0; i<n; i++) {
        if (A[i]%2==0) {
            printf("\nSố chẵn đầu tiên: ");
            return A[i];
        }
    }
    return -1;
}
bool timX(int A[], int n) {
    int x;
    printf("\nNhập X: ");
    scanf("%d",&x);
    for (int i=0;i<n;i++) {
        if (A[i]==x) {
            return true;
        }
    }
    return false;
}
float tb(int A[], int n) {
    int tong=0;
    int dem=0;
    for (int i=0; i<n; i++) {
        tong=tong+A[i];
        dem++;
    }
    return (float)tong/dem;
}
int main() {
    srand(time(NULL));
    int A[100], n, x;
    printf("Nhập n: ");
    scanf("%d", &n);
    taoMang(A,n);
    printf("\n");
    xuatNguoc(A,n);
    xuatLe(A,n);
    printf("\n-----Tổng mảng: %d", tong(A, n));
    printf("\n-----Đếm lẻ: %d", demLe(A, n));
    printf("-----Đếm x: %d", demX(A,n,x));
    printf("\n-----Tìm chẵn: %d", timChan(A,n));
    if (timX(A,n)) {
        printf("có tìm thấy");
    }
    else printf("ko tìm thấy");
    printf("\n-----tb: %0.2f", tb(A,n));
    return 0;
}