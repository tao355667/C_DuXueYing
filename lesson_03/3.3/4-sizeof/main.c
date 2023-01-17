#include <stdio.h>
//sizeof()是一个运算符，用于求常量或变量所占用的空间大小
int main() {
    int a=10;
    int b=3;
    char c='o';
    double d=32.5;

    printf("a=%d,b=%d,c=%d,d=%d\n",sizeof (a),sizeof (b),sizeof (c),sizeof (d));
    return 0;
}
