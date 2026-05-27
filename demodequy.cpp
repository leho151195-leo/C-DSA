#include <stdio.h>
 
int Tong(int n) {
    int S=0;
    while (n>0) {
        S=S+n%10;
        n/=10;
    }
    return S;
}
int TongDQ(int n) {
    if (n<10) {
        return n;
    }
    return TongDQ(n/10) + n%10;
}
int Dem(int n) {
    int dem=0;
    while (n>0) {
        dem++;
        n/=10;
    }
    return dem;
}
int DemDQ(int n) {
    if (n<10) {
        return 1;
    }
    return DemDQ(n/10)+1;
}
int Max(int n) {
    int Max=0;
    while (n>0) {
        if (Max<=(n%10)) {
            Max=n%10;
        }
        n/=10;
    }
    return Max;
}
int MaxDQ(int n) {
    if (n<10) {
        return n;
    }
    int Max1 = n%10;
    int Max2 = MaxDQ(n/10);
    if (Max1>Max2) {
        return Max1;
    }
    return Max2;
}
int MaxDq(int n) {
    if (n==0) {
        return 0;
    }
    int k = MaxDq(n/10);
    return (k<n%10) ? n%10 :k;
}
void xuatNguoc(int n) {
    while (n>0) {
        printf("%d", n%10);
        n/=10;
    }
}
void xuatNguocDQ(int n) {
    if (n<=0) {
        return;
    }
    printf("%d", n%10);
    xuatNguocDQ(n/10);
}
int daoNguoc(int n) {
    int sdn = 0;
    while (n>0) {
        sdn=sdn*10+n%10;
        n/=10;
    }
    return sdn;
}
int daoNguocDQ(int n, int sdn=0) {
    if (n<=0) {
        return sdn;
    }
    sdn=sdn*10+n%10;
    return daoNguocDQ(n/10,sdn);
}
int DQ1(int &nguoc, int n) {
    if (n==0) {
        return n;
    }
    else {
        nguoc=(nguoc*10)+n%10;
        DQ1(nguoc,n/10);
        return nguoc;
    }
}
int main() {
    int n=2019; int nguoc=0;
    /*printf("Tổng: %d\n", Tong(n));
    printf("Tổng đệ quy: %d\n", TongDQ(n));
    printf("Đếm: %d\n", Dem(n));
    printf("Đếm đệ quy: %d\n", DemDQ(n));
    printf("Max: %d\n", Max(n));
    printf("Max đệ quy 1: %d\n", MaxDQ(n));
    printf("Max đệ quy 2: %d\n", MaxDq(n));
    printf("Số xuất ngược: ");
    xuatNguoc(n);
    printf("\nSố xuất ngược đệ quy: ");
    xuatNguocDQ(n);
    printf("\nSố đảo ngược: %d\n", daoNguoc(n));
    printf("\nSố đảo ngược đệ quy: %d\n", daoNguocDQ(n));*/
    printf("%d", DQ1(nguoc,n));
    return 0;
}