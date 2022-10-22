/*Description

判断某个年份是不是闰年，如果是闰年，请输出“yes”，否则请输出“no”


Input
输入一行，只有一个整数x (0<=x <=10000)


Output
输出只有一行字符*/
#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    if(a%100!=0)
    {
        if(a%4==0)
            printf("yes");
        else
            printf("no");
    }else
    {
        if(a%400==0)
            printf("yes");
        else
            printf("no");
    }
    return 0;
}
