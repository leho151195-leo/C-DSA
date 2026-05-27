#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#define QUEUESIZE 100

//khai báo cấu trúc
struct QUEUE {
    int* Array;
    int qCapacity;
    int qFront;
    int qRear;
};
bool initQueue(QUEUE& q);
bool isEmpty(QUEUE q);
bool isFull(QUEUE q);
void printQueue(QUEUE q);
bool enQueue(QUEUE& q, int x);
void addMulti(QUEUE& q);
void addOne(QUEUE &q);
bool deQueue(QUEUE& q, int &outItem);

//khai báo hàm nguyên mẫu
int main() {
    srand(time(NULL));
    QUEUE q;
    if (!initQueue(q)) {
        return 0;
    }
    int n, k, outItem, chon;
    do {
        printf("---Chương trình minh hoạ QUEUE bằng Array---\n");
        printf("\t1.Thêm 1 lần nhiều giá trị vào Queue\n");
        printf("\t2.Thêm 1 lần 1 giá trị vào Queue\n");
        printf("\t3.Xem tình trạng hiện tại của Queue\n");
        printf("\t4.Lấy 1 phần tử ra khỏi Queue\n");
        printf("\t5.Kết thúc chương trình\n");
        printf("Chọn chức năng cần thực hiện (1-5): ");
        scanf("%d", &chon);
        switch(chon) {
            case 1: {
                addMulti(q);
                break;
            }
            case 2: {
                addOne(q);
                break;
            }
            case 3: {
                printQueue(q);
                break;
            }
            case 4: {
                if(deQueue(q,outItem)==true) {
                    printf("Giá trị vừa lấy ra khỏi Queue là: %d\n", outItem);
                }
                else {
                    printf("Queue rỗng, không có phần tử để lấy");
                }
                break;
            }
            case 5: {
                printf("----------Tạm biệt----------");
                break;
            }
            default: {
                printf("Chỉ được nhập từ 1 -> 5: ");
            }
        } 
    } while (chon!=5);
    delete[]q.Array;
    return 0;
}

//khởi tạo queue
bool initQueue(QUEUE& q) {
    int MAX;
    do {
        printf("Nhập kích thước Queue (q<=%d): ", QUEUESIZE);
        scanf("%d", &MAX);
    } while(!(MAX>0&&MAX<=QUEUESIZE));
    q.Array=new int[MAX];
    if(q.Array==NULL) {
        return false;
    }
    q.qCapacity=MAX;
    q.qFront=q.qRear=-1;
    for(int i=0; i<MAX; i++) {
        q.Array[i]= INT_MIN;
    }
    return true;
}

//kiểm tra queue rỗng
bool isEmpty(QUEUE q) {
    return q.qFront==-1;
}

//kiểm tra queue đầy
bool isFull(QUEUE q) {
    return ((q.qRear-q.qFront==q.qCapacity-1)||(q.qFront-q.qRear)==1);
}

//in queue ra màn hình
void printQueue(QUEUE q) {
    for(int i=0; i<q.qCapacity;i++) {
        if(q.Array[i]==INT_MIN) {
            printf("     X");
        }
        else {
            printf("%5d", q.Array[i]);
        }
    }
    printf("\n");
}

//add gía trị vào queue
bool enQueue(QUEUE& q, int inItem) {
    if (isFull(q)) {
        return false;
    }
    if (isEmpty(q)) {
        q.qFront=q.qRear=0;
    }
    else {
        q.qRear=(q.qRear+1)%q.qCapacity;
    }
    q.Array[q.qRear]=inItem;
    return true;
}

//add vào số lượng phần tử k
void addMulti(QUEUE& q) {
    int n, k;
    printf("Nhập số lượng phần tử muốn thêm vào Queue (n<=%d): ", QUEUESIZE);
    scanf("%d", &n);
    for(int i=0; i<n;i++) {
        k = rand()%100;
        if (!enQueue(q,k)) {
            printf("-------Queue is FULL-------\n");
            break;
        }
    }
}

//add vào 1 phần tử
void addOne(QUEUE &q) {
    int k;
    printf("Nhập số cần thêm vào queue: ");
    scanf("%d", &k);
    if (!enQueue(q,k)) {
            printf("-------Queue is FULL-------\n");
    }
}

//lấy phần tử ra khỏi queue
bool deQueue(QUEUE& q, int &outItem) {
    if (isEmpty(q)) {
        return false;
    }
    outItem = q.Array[q.qFront];
    q.Array[q.qFront]=INT_MIN;
    if(q.qFront==q.qRear) {
        q.qFront=q.qRear=-1;
    }
    else {
        q.qFront=(q.qFront+1)%q.qCapacity;
    }
    return true;
}