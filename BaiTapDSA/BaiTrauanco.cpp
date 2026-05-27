#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
int main()
{
    int dung, nam, gia;
    int total=100;
    /*for (dung=0;dung<=100;dung++)
        for(nam=0;nam<=100;nam++)
            for(gia=0;gia<=100;gia++)
            {
                if(gia%3==0&&(5*dung)+(3*nam)+(gia/3)==100&&(dung+nam+gia)==100)
                printf("\n%dung, %dnam, %dgia", dung,nam,gia);
            }*/

            /*for (dung=0;dung<=100;dung++)
                for(nam=0;nam<=100;nam++)                   
            {
                gia=100-dung-nam;
                if(gia%3==0&&(5*dung)+(3*nam)+(gia/3)==100&&(dung+nam+gia)==100)
                printf("\n%ddung, %dnam, %dgia", dung,nam,gia);
            }*/
        for (dung=0;dung<=100;dung++)
        {
           int temp=100-7*dung;
           if(temp%4==0&&temp>=0)
           {
           nam=temp/4;
           gia=100-dung-nam;
           if (gia>=0&&gia%3==0&&(5*dung)+(3*nam)+(gia/3)==total&&(dung+nam+gia)==total)
           printf("\n%ddung, %dnam, %dgia", dung,nam,gia);
           }
        }
    return 0;
}