#include <stdio.h>
//逻辑运算符
int main() {
    int year,i,j=2;
    while (scanf("%d",&year))
    {
        //判断year是否是闰年
        if(year%4==0&&year%100!=0||year%400==0)
        {
            printf("%d is leap year\n",year);
        }
        else
        {
            printf("%d is not leap year\n",year);
        }
    }
    i=!!j;
    printf("i value=%d",i);
    return 0;
}
