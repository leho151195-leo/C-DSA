#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct Movie {
    string name;
    float revenue;
    int type;
    int date;
    bool vietnam;
};
// Khai bao nguyen mau ham
void addMovie(Movie& m);
void addNMovie(Movie A[], int x);
void Xuat1Film(Movie m);
void printAllMovie(Movie A[], int n);
void printMovieType(Movie A[], int n);
void CauG(Movie m[], int n, int fromyear, int toyear) ;
int main()
{
    Movie A[1000];
    int n = 0;
    printf("Nhap so luong film:");
    scanf("%d", &n);
    addNMovie(A, n);
    printf("Danh sach film hien co:");
    printAllMovie(A, n);
    printf("Nhap so luong film:");
    scanf("%d", &n);
    int fromyear, toyear;
    printf("Nhap tu nam:");
    scanf("%d", &fromyear);
    printf("Nhap den nam:");
    scanf("%d", &toyear);
    CauG(A, n, fromyear, toyear);

    int lower, upper;
    printf("Nhap doanh thu tu:");
    scanf("%d", &lower);
    printf("Nhap doanh thu den:");
    scanf("%d", &upper);
    CauG(A, n, lower, upper);
}
void addMovie(Movie &m) {
    printf("Ten phim: ");
    scanf("%s", m.name);
    printf("Doanh thu: ");
    scanf("%f", m.revenue);
    printf("The loai (0:hinh su; 1: tinh cam; 2: hai): ");
    scanf("%d", m.type);
    printf("Nam san xuat: ");
    scanf("%d", m.date);
    printf("La phim Viet Nam (Y/N): ");
    char ch;
    ch=getchar();
    if ((ch == 'N') || (ch == 'n'))
        m.vietnam = false;
    else
        m.vietnam = true;

}

void addNMovie(Movie A[], int x) { // b
    for (int i = 0; i < x; i++)
        addMovie(A[i]);
}

void Xuat1Film(Movie m) { // c
    printf("Ten phim: %s",m.name);
    printf("Doanh thu: %f", m.revenue);
    printf("The loai: ");
    switch (m.type) {
    case 0:
        cout << "Type: Hinh su\n";
        break;
    case 1:
        cout << "Type: Tinh cam\n";
        break;
    case 2:
        cout << "Type: Hai\n";
        break;
    }
    printf("Nam san xuat: %d", m.date);
    if (m.vietnam==true)
        printf("Phim do Viet Nam san xuat");
    else
        printf("Phim do nuoc ngoai san xuat");
}

void printAllMovie(Movie A[], int n) { // d
    for (int i = 0; i < n; i++)
        Xuat1Film(A[i]);
}
/////////////////////
void CauE(Movie m[], int n){
    int mtype;
    printf("Nhap the loai can xem (0:hinh su; 1: tinh cam; 2: hai): ");
    scanf("%d", &mtype);
    printf("Nhung film thuoc the loai %s: ",
            mtype==0?"hinh su":mtype==1?"tinh cam":"hai");
    for(int i = 0; i < n; i++){
        if(mtype == m[i].type)
            Xuat1Film(m[i]);
    }
}
void CauF(Movie m[], int n){
    long double total;
    for(int i = 0; i < n; i++){
        if(m[i].vietnam)
            total += m[i].revenue;
    }
    printf("Tong doanh thu cac phim do VN san xuat %d: ", total);
}

void CauG(Movie m[], int n, int fromyear, int toyear){
    int dem = 0;
    long double total = 0;
    for(int i = 0 ; i < n; i++){
        if(fromyear <= m[i].date && m[i].date<= toyear){
            dem++;
            total += m[i].revenue;
        }
    }
    if (dem==0)
        printf("0");
    else
        printf("%d", dem);
}
void CauH(Movie m[], int n, int lower, int upper){
    int dem = 0;
    for(int i = 0 ; i < n; i++){
        if(lower <= m[i].revenue && m[i].revenue <= upper){
            dem++;
        }
    }
    printf("Co %d film thoa dieu kien", dem);
}