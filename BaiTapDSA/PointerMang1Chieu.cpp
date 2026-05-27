#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int nhapN();
void taoMang(int A[],int n);
void inMang(int A[], int n);
void lietKe(int A[], int n);
bool checkSoDoiXung(int n);
void inSoDoiXung(int A[],int n);
bool isPrime(int n);
void inSoNguyenTo(int A[], int n, int x);

int main()
{   
    int n;
    n= nhapN();
    if (n==99) {
        printf("\nChương trình kết thúc");
        return 0;
    }
    int A[n];
    taoMang(A,n);
    inMang(A,n);
    lietKe(A,n);
    inSoDoiXung(A,n);
    int x;
    printf("Nhập X: ");
    scanf("%d" ,&x);
    inSoNguyenTo(A,n,x);
    return 0;
}

//===================CÁC HÀM NHỎ====================== 
//Hàm nhập N với 5 <= N <= 100
int nhapN() {
    int n;
    do {
        printf("\nNhập số nguyên n (5<n<100): ");
        scanf("%d", &n); 
        if (n==99) {
        return 99;
        }
    } while (n<5||n>100);
    return n;
    }
//Hàm tạo mảng với value random từ -100 -> 1000   
void taoMang(int A[], int n) {
    srand(time(NULL));
    for (int i=0;i<n;i++) {
        A[i]=rand()%1101-100;
    }
}   
//Hàm in mảng
void inMang(int A[], int n) {
    printf("\n----Mảng Random----\n");
    for (int i=0;i<n;i++) {
        printf("%d\t", A[i]);
    }
}
//Hàm liệt kê giá trị các phần tử có vị trí (index) ko là bội của 3
void lietKe(int A[], int n) {
    printf("\n--Giá trị các phần tử có vị trí (index) ko là bội của 3--\n");
    for (int i=0; i<n;i++) {
        if ((i%3)!=0)
        {
            printf("%d\t", A[i]);
        }
    }
}
//Check giá trị các số đối xứng
bool checkSoDoiXung(int n) {
        int temp =n;
        int daoNguoc=0;
        int digit=0;
    while (temp>0) {
        digit=temp%10;
        temp/=10;
        daoNguoc=daoNguoc*10+digit;
    }
    if(n==daoNguoc)
    {
       return true;
    }
    else return false;
}
//In mảng giá trị các số đối xứng
void inSoDoiXung(int A[],int n) {
printf("\n--Các value đối xứng trong mảng--\n");
    for (int i=0; i<n;i++) {
        if (checkSoDoiXung(A[i])) {
            printf("%d\t",A[i]);
        }
    }
}

//Check số nguyên tố
bool isPrime(int n) {
    if (n<2) {
        return false;
    }
    for(int i=2;i<n;i++) {
            if (n%i==0) {
                return false;
            }
        }
    return true;
}
//Đếm giá trị + X sẽ là số nguyên tố
void inSoNguyenTo(int A[],int n, int x) {
    printf("\n--In giá trị A[] + X là SNT--\n");
    for (int i=0;i<n;i++) {
        int temp = x+A[i];
        if (isPrime(temp)) {
            printf("%d\t", A[i]);
        }
    }

}