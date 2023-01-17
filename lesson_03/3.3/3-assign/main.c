#include <stdio.h>
//赋值，左值，右值
int main() {
    int a=1,b=2;
//    a+25=b;//报错，a+25不是左值
    a*=b;
    b=a+25;
    printf("a=%d,b=%d\n",a,b);
    return 0;
}
