#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void taoMang2Chieu(int **A, int row, int col);
int main() {
    srand(time(NULL));
    int row, col;
    printf("Nhập số dòng row: ");
    scanf("%d", &row);
    printf("\nNhập số cột col: ");
    scanf("%d", &col);
    printf("\n---Mảng 2 chiều---\n");
    int **A = new int *[row];
    for (int i=0;i<row;i++) {
        A[i]=new int[col];
    }
    taoMang2Chieu(A,row,col);
    return 0;
}

void taoMang2Chieu(int **A, int row, int col) {
    
    for (int i=0;i<row;i++) {
        for (int j=0;j<col;j++) {
            *(*(A+i)+j)=rand()%101;

            printf("%d\t", *(*(A+i)+j));
        }
        printf("\n");
    }
}