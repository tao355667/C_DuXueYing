/*Description

输入一个整型数，判断是否是对称数，如果是，输出yes，否则输出no，不用考虑这个整型数过大，int类型存不下，不用考虑负值；

例如 12321是对称数，输出yes，124421是对称数，输出yes，1231不是对称数，输出no


Input
一个整型数


Output
输出是yes，或者no*/
#include <stdio.h>

int main() {
    int a;
    int num=0;
    scanf("%d",&a);
    int newa=a;
    while(a)
    {
        num=num*10+a%10;
        a=a/10;
    }
    if(num==newa)
        printf("yes");
    else
        printf("no");
    return 0;
}
