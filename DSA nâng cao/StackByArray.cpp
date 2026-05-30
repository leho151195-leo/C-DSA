#include <iostream>
#include <stdlib.h>
#include <time.h>

//giả sử stack chứa các pt kiểu nguyên (int)
struct STACK { 
    int* StkArray; //mảng chứa các pt
    int StkCapacity; //số pt (sức chứa) tối đa
    int StkCount; //vị trí đỉnh stack
};

bool init(STACK& s, int n);
bool isEmpty(STACK s);
bool isFull(STACK s);
bool Push(STACK& s, int x);
bool Pop(STACK& s, int& x);
void printStack(STACK& s);
void convertBase(STACK& s, int number, int base);
void printConvertStack(STACK& s);

//Khai báo hàm nguyên mẫu
int main() {
    srand(time(NULL));
    STACK s;
    int n;
    printf("--------------------------\n");
    do {
        printf("Nhập kích thước stack (n>=32): ");
        scanf("%d", &n);
    } while (!(n>=32));
    if (!init(s,n)) {
        printf("Không đủ bộ nhớ\n");
        return 0;
    }
    for(int i=0; i<s.StkCapacity;i++) {
        int x = rand()%100;
        Push(s,x);
    }
    printStack(s);
    int number, base;
    do {
        printf("Nhập số cần chuyển đổi (number>0):  ");
        scanf("%d", &number);
    } while (!(number>0));
    do {
        printf("Nhập cơ số muốn chuyển đổi (2/8/16): ");
        scanf("%d", &base);
    } while (!(base==2||base==8||base==16));
    convertBase(s,number,base);
    printConvertStack(s);
    delete[]s.StkArray;
    return 0;
}

//----------------CÁC HÀM CON--------------------
//khởi tạo stack
bool init(STACK& s, int n) {
    s.StkArray=new int[n];
    if (s.StkArray==NULL) {
        return false;
    }
    s.StkCapacity=n;
    s.StkCount=0;
    return true;
}
//kiểm tra stack rỗng
bool isEmpty(STACK s) {
    return(s.StkCount==0);
}
//kiểm tra stack đầy
bool isFull(STACK s) {
    return(s.StkCount>=s.StkCapacity);
}
//thêm giá trị vào stack
bool Push(STACK& s, int x) {
    if (isFull(s)) {
        return false;
    }
    s.StkArray[s.StkCount]=x;
    s.StkCount++;
    return true;
}
//lấy giá trị khỏi stack
bool Pop(STACK& s, int& x) {
    if (isEmpty(s)) {
        return false;
    }
    s.StkCount--;
    x=s.StkArray[s.StkCount];
    return true;
}
//xuất dữ liệu stack bằng pop
void printStack(STACK& s) {
    int x;
    printf("-------In dữ liệu trong Stack-------\n");
    while (!isEmpty(s)) {
        Pop(s,x);
        printf("%d\t", x);
    }
    printf("\n");
}
//chuyển đổi cơ số
void convertBase(STACK& s, int number, int base) {
    int temp=number;
    while (number>0) {
        Push(s,number%base);
        number/=base;
    }
    printf("Số %d chuyển đổi sang cơ số %d là: ", temp, base);
}
//in dữ liệu chuyển đổi cơ số (khác in thường vì còn có chữ cái hệ 16)
void printConvertStack(STACK& s) {
    int x;
    while (!isEmpty(s)) {
        Pop(s,x);
        if (x>=10) {
            printf("%c", 'A'+(x-10));
        }
        else {
            printf("%d", x);
        }
    }
    printf("\n");
}