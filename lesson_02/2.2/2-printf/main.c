#include <stdio.h>
//练习printf
int main() {
    int age=81;

    printf("Hello %s,you are %d years old\n","Bob",age);
    int i=10;
    float f=96.3;
    printf("student number=%3d,score=%5.2f\n",i,f);//默认右对齐，加负号代表左对齐
    i=100;
    f=98.21;
    printf("student number=%3d,score=%5.2f\n",i,f);
    return 0;
}
