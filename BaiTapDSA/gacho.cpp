#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main()
{
    int ga,cho;
    for (cho=0;cho<=36;cho++)
    {
        ga=36-cho;
        if(2*ga+4*cho==100)
        printf("%dga, %dcho", ga,cho);
    }
return 0;
}

