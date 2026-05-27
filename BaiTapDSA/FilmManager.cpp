#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#define MAX 100
using namespace std;

struct Movie 
{
    char name[MAX]; //Kiểu ký tự, giới hạn 100 ký tự
    float revenue; //Doanh thu kiểu số thực
    int type; //Thể loại 0:hình sự, 1:tình cảm, 2:hài
    int date; //Năm sản xuất
    bool vietnam; //Kiểu true: Việt Nam - false: Nước Ngoài
};

void addMovie(Movie &m) //a. Nhập dữ liệu 1 bộ phim
{ 
    printf("Ten phim: ");
    scanf(" %[^\n]", m.name);//" %[^\n]" lấy toàn bộ chuỗi kí tự cho đến khi ấn Enter
    //" %c" sẽ chỉ lấy 1 kí tự đầu
    //"%s" sẽ chỉ lấy 1 chuỗi kí tự cho tới khoảng trắng
    //trước %c hoặc %[^\n] phải để " " vì 2 kiểu dữ liệu đó ko hiểu và sẽ tính luôn dấu \n từ phím Enter của lần nhập trước
    printf("Doanh thu: ");
    scanf("%f", &m.revenue);
    //các kiểu dữ liệu %f,d,c nếu dùng scanf phải có &, để gán giá trị đúng địa chỉ
    printf("The loai (0:hinh su; 1: tinh cam; 2: hai): ");
    scanf("%d", &m.type);
    printf("Nam san xuat: ");
    scanf("%d", &m.date);
    printf("La phim Viet Nam (Y/N): ");
    char ch;
    scanf(" %c", &ch);
    if ((ch == 'N') || (ch == 'n'))
        m.vietnam = false;
    else
        m.vietnam = true;
}

void addNMovie(Movie A[], int x) //b. Nhập danh sách x phim
{
    for (int i = 0; i < x; i++) 
        addMovie(A[i]);
}

void printMovieDetails(Movie m) //c. In dữ liệu 1 bộ phim
{ 
    printf("\n----------------------\n");
    printf("Ten phim: %s\n",m.name);
    printf("Doanh thu: %.2f\n", m.revenue);
    printf("The loai: ");
    switch (m.type) 
    {
    case 0:
        printf("Type: Hinh su\n");
        break;
    case 1:
        printf("Type: Tinh cam\n");
        break;
    case 2:
       printf("Type: Hai\n");
        break;
    }
    printf("Nam san xuat: %d\n", m.date);
    if (m.vietnam==true)
        printf("Phim Viet Nam");
    else
        printf("Phim Nuoc Ngoai");
}

void printAllMovie(Movie A[], int n) //d. In danh sách n phim đã nhập
{ 
    for (int i = 0; i < n; i++) 
        printMovieDetails(A[i]);
}

void typeMovie(Movie A[], int n) //e. Nhập vào thể loại phim và in ra danh sách phim có thể loại đó
{
    int targetType;
    printf("\n-------\nLoc The loai (0:hinh su; 1: tinh cam; 2: hai): ");
    scanf("%d", &targetType);
    printf("\n----Danh sach phim da loc----\n");
    for (int i = 0; i < n; i++) 
    {
        if (A[i].type==targetType)
        {
            printMovieDetails(A[i]);
        }
    }
}

void revenueMovie(Movie A[], int n) //f. Tính tổng doanh thu phim VN
{
    int total;
    printf("\n----Danh sach phim Viet Nam----");
    for (int i = 0; i < n; i++) 
    {
        if(A[i].vietnam==true)
        {
            printMovieDetails(A[i]);
            total+=A[i].revenue;
        }
    }
    printf("\nTong doanh thu phim VN= %d", total);
}

void revenueintime(Movie A[], int n, int fromyear, int toyear) //g. Doanh thu các phim trong khoảng thời gian từ ... đến ...
{
    printf("\n---------------");
    printf("\nNhap nam bat dau:");
    scanf("%d", &fromyear);
    printf("\nNhap nam ket thuc:");
    scanf("%d", &toyear);
    int dem=0;
    int total=0;
    for (int i = 0; i < n; i++)
    {
        if (fromyear<=A[i].date&&A[i].date<=toyear)
        {
            dem++;
            total+=A[i].revenue;
        }
    }
    if (dem==0)
    printf("\nKo co doanh thu trong thoi gian nay");
    else
    printf("\nDoanh thu trong thoi gian tu %d den %d la: %d", fromyear, toyear, total);
    printf("\n---------------");
}

void revenueinrange(Movie A[], int n, int lower, int upper)  //h. So phim co doanh thu nam trong khoang
{
    printf("\n---------------");
    printf("\nNhap doanh thu thap nhat:");
    scanf("%d", &lower);
    printf("\nNhap doanh thu cao nhat:");
    scanf("%d", &upper);
    int dem=0;
    for (int i=0; i<n;i++)
    {
        if(lower<=A[i].revenue&&A[i].revenue<=upper)
        {
            dem++;
        }
    }
    printf("\nCo %d phim co doanh thu tu %d den %d", dem, lower, upper);
    printf("\n---------------");
}

int main()
{
    Movie A[100];
    int n = 0;
    int fromyear, toyear, lower, upper;
    printf("Nhap so luong film:"); //Nhập số lượng phim
    scanf("%d", &n);
    addNMovie(A, n);
    printf("Danh sach film:");
    printAllMovie(A, n);
    //typeMovie(A,n);
    //revenueMovie(A,n);
    //revenueintime(A,n,fromyear,toyear);
    //revenueinrange(A,n,lower,upper);
}