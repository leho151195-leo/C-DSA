#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct NODE {
    int data;
    NODE *pLeft, *pRight;
};
typedef NODE *TREE;

void initTree (TREE& t);
NODE* createNode(int x);
int addNode(TREE& t, int x);
void LNR(TREE t);
void LRN(TREE t);
void NLR(TREE t);

//hàm nguyên mẫu
int main() {
    srand(time(NULL));
    TREE t;
    initTree(t);
    addNode(t,5);
    addNode(t,10);
    addNode(t,20);
    addNode(t,15);
    addNode(t,30);
    addNode(t,25);
    /*int n;
    do {
        printf("Nhập số lượng node muốn thêm vào: ");
        scanf("%d", &n);
    } while (!(n>0&&n<101));
    printf("Random giá trị: \n");
    for (int i=0; i<n; i++) {
        int x = rand()%100;
        printf("%5d", x);
        addNode(t, x);
    }*/
    printf("\nDuyệt Left-Node-Right: \n");
    LNR(t);
    printf("\nDuyệt Left-Right-Node: \n");
    LRN(t);
    printf("\nDuyệt Node-Left-Right: \n");
    NLR(t);
    return 0;
}

//khởi tạo tree
void initTree (TREE& t) {
    t = NULL;
}
//kiểm tra rỗng
int isEmpty(TREE t) {
    return (t == NULL);
}
//tạo node
NODE* createNode(int x) {
    NODE *p;
    p = new NODE; //cấp phát vùng nhớ cho phần tử
    if (p==NULL) {
        return NULL;
        }
    p->data = x; //gán dữ liệu cho node
    p->pLeft = p->pRight = NULL;
    return p;
}
//đưa node vào cây
int addNode(TREE& t, int x) {
    if (t!=NULL) {
        if (x==t->data) { //giá trị x đã có trên cây
            return 0;
        }
        else {
            if (x<t->data) {
                return addNode(t->pLeft, x);
            }
            else {
                return addNode(t->pRight, x);
            }
        }
    }
    else {
        NODE* p;
        p= createNode(x);
        if (p==NULL) {
            return -1; //thêm thất bại
        }
        else {
            t=p;
        }
        return 1;
    }
}
//duyệt cây
void LNR(TREE t) {
    if (t!=NULL) {
        LNR(t->pLeft);
        printf("%5d", t->data);
        LNR(t->pRight);
    }
}
void LRN(TREE t) {
    if (t!=NULL) {
        LRN(t->pLeft);
        LRN(t->pRight);
        printf("%5d", t->data);
    }
}
void NLR(TREE t) {
    if (t!=NULL) {
        printf("%5d", t->data);
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}
