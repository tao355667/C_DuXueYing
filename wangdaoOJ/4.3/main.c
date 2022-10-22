/*Description

某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。要求换正好40张，且每种票子至少一张。问：有几种换法？


Input
无输入


Output
一个数，表示共有多少种换法*/
#include <stdio.h>

int main() {
    int sum=0;
    int i,j,k,l;
    for(i=1;i<=10;i++)
    {
        for(j=1;j<=20;j++)
        {
            for(k=1;k<=40;k++)
            {
                for(l=1;l<=40;l++)
                {
//                    printf("i=%d,j=%d,k=%d,l=%d\n",i,j,k,l);
                    if(i+j+k+l!=40)
                    {
                        continue;
                    }
                    if(i*10+j*5+k*2+l==100)
                    {
                        sum++;
                    }
                }
            }
        }
    }

    printf("%d",sum);

    return 0;
}
