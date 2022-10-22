#include <stdio.h>
//scanf缓冲区为空-->阻塞
int main() {
    int i=10;
    char c;
    float f;
    scanf("%d",&i);//读取一个整数，此时缓冲区(大小4096字节)还有个'\n'
    printf("i=%d\n",i);
    fflush(stdin);//清空标准输入缓冲区，若不清空则会将'\n'读入，赋给c
    scanf("%c",&c);
    printf("c=%c\n",c);
    //scanf读取整型、浮点型、字符串时，会忽略'\n'，空格等
    scanf("%f",&f);//此时缓冲区还有个'\n'，但忽略了
    printf("f=%f\n",f);
    return 0;
}
