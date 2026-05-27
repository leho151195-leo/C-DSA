#include <cstdio>
#include <cstdlib>
#include <ctime>

struct NODE {
    int data;
    NODE* pNext;
};

struct QUEUE {
    NODE* qFront;
    NODE* qRear;
};
bool initQueue(QUEUE& q);
bool isEmpty(QUEUE q);
NODE* taoNode(int x);
bool enQueue(QUEUE& q, int x);
void addOne(QUEUE &q);
void addMulti(QUEUE& q);
void printQueue(QUEUE q);
bool deQueue(QUEUE& q, int& outItem);
int countQueue(QUEUE q);
bool deQueueMulti(QUEUE& q);
void clearQueue(QUEUE& q);

int main() {
    srand(time(NULL));
    QUEUE q;
    if (!initQueue(q)) {
        return 0;
    }
    int outItem, chon;
    do {
        printf("---Chương trình minh hoạ QUEUE bằng Linked List---\n");
        printf("\t1.Thêm 1 lần nhiều giá trị vào Queue\n");
        printf("\t2.Thêm 1 lần 1 giá trị vào Queue\n");
        printf("\t3.Xem tình trạng hiện tại của Queue\n");
        printf("\t4.Lấy 1 phần tử ra khỏi Queue\n");
        printf("\t5.Lấy k phần tử ra khỏi Queue\n");
        printf("\t6.Kết thúc chương trình\n");
        printf("Chọn chức năng cần thực hiện (1-6): ");
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
                    printf("Queue rỗng, không có phần tử để lấy\n");
                }
                break;
            }
            case 5: {
                deQueueMulti(q);
                break;
            }
            case 6: {
                printf("----------Tạm biệt----------");
                break;
            }
            default: {
                printf("Chỉ được nhập từ 1 -> 6: ");
            }
        } 
    } while (chon!=6);
    clearQueue(q);
    return 0;
}

//khởi tạo Queue
bool initQueue(QUEUE& q) {
    q.qFront=q.qRear=NULL;
    return true;
}

//kiểm tra queue rỗng
bool isEmpty(QUEUE q) {
    return q.qFront == NULL;
}

//tạo Node
NODE* taoNode(int x) {
    NODE* p= new NODE;
    p->data=x;
    p->pNext=NULL;
    return p;
}

//Thêm giá trị vào Queue
bool enQueue(QUEUE& q, int x) {
    NODE* p= taoNode(x);
    if (p==NULL) {
        return false;
    }
    if (isEmpty(q)) {
        q.qFront=q.qRear=p;
    }
    else {
        q.qRear->pNext=p;
        q.qRear=p;
    }
    return true;
}

//thêm 1 node vào queue
void addOne(QUEUE &q) {
    int k;
    printf("Nhập số cần thêm vào queue: ");
    scanf("%d", &k);
    enQueue(q,k);
}

//Thêm nhiều Node vào queue
void addMulti(QUEUE& q) {
    int n, x;
    do {
        printf("Nhập số lượng phần tử muốn thêm vào Queue: ");
        scanf("%d", &n);
    } while (!(n>0));
    for(int i=0;i<n;i++) {
        x=rand()%100;
        if (!enQueue(q,x)) {
            printf("-------Không đủ bộ nhớ-------\n");
            break;
        }
    }
}

//lấy ra 1 node
bool deQueue(QUEUE& q, int& outItem) {
    if (isEmpty(q)) {
        return false;
    }
    NODE* p=q.qFront;
    outItem=p->data;
    q.qFront=q.qFront->pNext;
    if (q.qFront == NULL) {
        q.qRear=NULL;
    }
    delete p;
    return true;
}

//đếm số lượng node
int countQueue(QUEUE q) {
    int dem=0;
    for (NODE* p=q.qFront; p!=NULL; p=p->pNext) {
        dem++;
    }
    return dem;
}
//lấy ra nhiều node
bool deQueueMulti(QUEUE& q) {
    int k;
    do {
        printf("Nhập số lượng node cần lấy (k>0): ");
        scanf("%d", &k);
    } while (!(k>0));
    if (countQueue(q)<k) {
        printf("Queue ko đủ %d node để lấy\n", k);
        return false;
    }
    int outItem;
    for (int i=0;i<k;i++) {
        deQueue(q,outItem);
        printf("Giá trị vừa lấy ra: %d\n", outItem);
    }
    return true;
}

//in Queue ra màn hình
void printQueue(QUEUE q) {
    if (isEmpty(q)) {
        printf("Queue rỗng\n");
        return;
    }
    printf("Queue hiện tại: \n");
    for (NODE* p=q.qFront; p!=NULL; p= p->pNext) {
        printf("%d\t", p->data);
    }
    printf("\n");
}

//Xoá queue
void clearQueue(QUEUE& q) {
    int x;
    while (deQueue(q,x));
}

