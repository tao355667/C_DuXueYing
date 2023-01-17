#include <stdio.h>
//关系运算符关系小于算数运算符
int main() {
    int  a;
    while(scanf("%d",&a))
    {
//        if(3<a<10)
        if(3<a&&a<10)
        {
            printf("a is between 3 and 10\n");
        }
        else
        {
            printf("a is not between 3 and 10\n");
        }
    }

    return 0;
}
