#include <iostream>
using namespace std;

void probA(int x, int n){
    long double total = x;
    int temp = x;
    int under = 1;
    for(int i = 1; i < n; i++){
        temp = temp*x;
        under = under + i + 1;
        total += (double(temp)/(under));
    }
    printf("Cau A: %0.2f \n",total);
    return;
}

void probB(int n){
    long long total = 0;
    int current = 0;
    for(int i = 1 ; i < n + 1; i++){
        current += i;
        total += current;
    }
    printf("Cau B: %0.2f \n",total);
}

void probC(int n){
    long long total = 0;
    int current = 1;
    for(int i = 1; i < n + 1; i++){
        current *= i;
        total += current;
    }
    printf("Cau C: %0.2f \n",total);
}

int main(){
    probA(5,3);
    probB(3);
    probC(3);
}