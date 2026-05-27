#include <iostream>
#include <stdlib.h>
#include <time.h>

//Khai báo cấu trúc node có trong DSLK
struct NODE
{
    int data;
    NODE* pnext;
};

//Khai báo cấu trúc để quản lý DSLK
struct LIST
{
    NODE* phead;
    NODE* ptail;
};

void khoiTaoList(LIST &L);
bool isEmpty(LIST L);
NODE* tao1Node(int x);
void chenVaoDauDSLK(LIST& L, int x);
void taoDSLK(LIST& L);
void xuatDSLK(LIST& L);
void xuatDSLKchan(LIST& L);
void Sum(LIST& L);
bool isPrime(int n);
void xuatDSLKisPrime(LIST& L);
bool isPerfectSquare(int n);
void xuatDSLKisPerfectSquare(LIST& L);
bool isLocPhat(int n);
void xuatDSLKisLocPhat(LIST& L);
void xFirst(LIST& L);
void xLast(LIST& L);
void findMAX(LIST& L);
void chenVaoCuoiDSLK(LIST& L, int x);
void chenTaiViTri(LIST& L);

//Khai báo nguyên mẫu hàm
int main()
{
    srand(time(NULL));
    printf("========================\n");
    LIST L;
    int x;
    khoiTaoList(L);
    taoDSLK(L);
    xuatDSLK(L);
    xuatDSLKchan(L);
    Sum(L);
    xuatDSLKisPrime(L);
    xuatDSLKisPerfectSquare(L);
    xuatDSLKisLocPhat(L);
    xFirst(L);
    xLast(L);
    findMAX(L);
    chenVaoCuoiDSLK(L,x);
    chenTaiViTri(L);
    return 0;
}

//--------CÁC HÀM CON--------
void khoiTaoList(LIST &L)
{
    L.phead = L.ptail = NULL;
}
bool isEmpty(LIST L)
{
    return L.phead == NULL;
}
NODE* tao1Node(int x)
{
    NODE* p = new NODE;
    if (p==NULL)
    {
        printf("Không thể cấp vùng nhớ cho NODE");
    }
    else
    {
        p -> data = x;
        p -> pnext = NULL;
    }
    return p;
}
void chenVaoDauDSLK(LIST& L, int x)
{
    NODE* p = tao1Node(x);
    if (p != NULL)
    {
        if (L.phead==NULL) //DSLK rỗng thì phead và ptail cùng chỉ vào p
            {
                L.ptail = p;
            }
        p -> pnext = L.phead;
        L.phead = p;
    }
}
void taoDSLK(LIST& L)
{
    //Nhập vào số node có trong DS
    int n,x;
    printf("Nhập số NODE cần tạo cho DSLK: ");
    scanf("%d", &n);
    //Tạo n node cho DSLK
    for (int i=0; i<n; i++)
    {
        x=rand()%101;
        chenVaoDauDSLK(L,x);
    }
}
void xuatDSLK(LIST& L)
{
    NODE* p = L.phead;
    printf("Các giá trị có trong DSLK: ");
    while (p != NULL)
    {
        printf("%d -> ", p -> data);
        p = p -> pnext;
    }
    printf("NULL\n");
}
void xuatDSLKchan(LIST& L)
{
    NODE* p = L.phead;
    printf("Các giá trị chẵn có trong DSLK: ");
    while (p != NULL)
    {
        if(p -> data % 2 == 0)
        {
            printf("%d -> ", p -> data);
        }
        p = p -> pnext;
    }
    printf("NULL\n");
}
void Sum(LIST& L)
{
    NODE* p = L.phead;
    int tong=0;
    while (p != NULL)
    {
        tong=tong+ p -> data;
        p = p -> pnext;
    }
    printf("Tổng của các gía trị trong DSLK: %d\n", tong);
}
bool isPrime(int n)
{
    if (n<2)
    {
        return false;
    }
    for(int i=2; i<n; i++)
    {
        if (n%i==0)
        {
            return false;
        }
    }
    return true;
}
void xuatDSLKisPrime(LIST& L)
{
    NODE* p = L.phead;
    printf("Các giá trị nguyên tố trong DSLK: ");
    while (p != NULL)
    {
        if (isPrime(p->data))
        {
            printf("%d -> ", p -> data);
        }
        p = p -> pnext;
    }
    printf("NULL\n");
}
bool isPerfectSquare(int n)
{
    int x = sqrt(n);
    if (x*x==n)
    {
        return true;
    }
    return false;
}
void xuatDSLKisPerfectSquare(LIST& L)
{
    NODE* p = L.phead;
    printf("Các giá trị chính phương trong DSLK: ");
    while (p != NULL)
    {
        if (isPerfectSquare(p->data))
        {
            printf("%d -> ", p -> data);
        }
        p = p -> pnext;
    }
    printf("NULL\n");
}
bool isLocPhat(int n)
{
    if (n==0)
    {
        return false;
    }
    n=abs(n);
    while (n>0)
    {
        int temp=n%10;
        if(temp!=6&&temp!=8)
        {
            return false;
        }
        n/=10;
    }
    return true;
}
void xuatDSLKisLocPhat(LIST& L)
{
    NODE* p = L.phead;
    printf("Các giá trị lộc phát (chỉ chứa 6 và 8) trong DSLK: ");
    while (p != NULL)
    {
        if (isLocPhat(p->data))
        {
            printf("%d -> ", p -> data);
        }
        p = p -> pnext;
    }
    printf("NULL\n");
}
void xFirst(LIST& L)
{
    NODE* p=L.phead;
    int x;
    int i=0;
    printf("Nhập giá trị x cần tìm: ");
    scanf("%d", &x);
    bool found = false;
    while (p != NULL)
    {
        if (x==p->data)
        {
            printf("Đã tìm thấy giá trị %d đầu tiên tại vị trí index %d", x,i);
            found = true;
            break;
        }
        p=p->pnext;
        i++;
    }
    if (found==false)
    {
        printf("Không tìm đc giá trị %d trong DSLK", x);
    }
    printf("\n");
}
void xLast(LIST& L)
{
    NODE* p=L.phead;
    int x;
    int i=0;
    printf("Nhập giá trị x cần tìm: ");
    scanf("%d", &x);
    bool found = false;
    int temp = 0;
    while (p != NULL)
    {
        if (x==p->data)
        {
            found=true;
            temp=i;
        }
        p=p->pnext;
        i++;
    }
    if (found==false)
    {
        printf("Không tìm đc giá trị %d trong DSLK", x);
    }
    else
    {
        printf("Đã tìm thấy giá trị %d cuối cùng tại vị trí index %d", x,temp);
    }
    printf("\n");
}
void findMAX(LIST& L)
{
    NODE* p = L.phead;
    int MAX=0;
    while (p != NULL)
    {
        if(MAX<=p->data)
        {
            MAX=p->data;
        }
        p = p -> pnext;
    }
    printf("Giá trị lớn nhất trong DSLK: %d", MAX);
    printf("\n");
}
void chenVaoCuoiDSLK(LIST& L, int x)
{
        printf("Nhập giá trị x node mới:");
        scanf("%d", &x);
    NODE* p = tao1Node(x);
    if (p != NULL)
    {
        if (L.phead==NULL) //DSLK rỗng thì phead và ptail cùng chỉ vào p
            {
                L.phead=L.ptail = p;
            }
        else
            {
                L.ptail -> pnext = p;
                L.ptail = p;
            }
    }
    NODE* b = L.phead;
    printf("Các giá trị có trong DSLK: ");
    while (b != NULL)
    {
        printf("%d -> ", b -> data);
        b = b -> pnext;
    }
    printf("NULL\n");
}
void chenTaiViTri(LIST& L)
{
    int x, k;
    printf("Nhập giá trị x cần chèn: ");
    scanf("%d", &x);
    printf("Nhập vị trí k cần chèn: ");
    scanf("%d", &k);
    if (k < 0)
    {
        printf("Vị trí không hợp lệ\n");
        return;
    }
    if (k == 0)
    {
        chenVaoDauDSLK(L, x);
        return;
    }
    NODE* p = tao1Node(x);
    if (p == NULL)
    {
        return;
    }
    NODE* b = L.phead;
    int i = 0;
    while (b != NULL && i < k - 1)
    {
        b = b->pnext;
        i++;
    }
    if (b == NULL)
    {
        printf("Vị trí vượt quá số node đang có\n");
        delete p;
        return;
    }
    p->pnext = b->pnext;
    b->pnext = p;
    if (p->pnext == NULL)
    {
        L.ptail = p;
    }
}