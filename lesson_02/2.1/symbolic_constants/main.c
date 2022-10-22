#include<stdio.h>

#define PI 3+2

void main()
{
//    PI=20;//报错，符号常量不能被赋值
    int i=PI*2; //等价于int i=3+2*2，执行后i为7
	printf("%d\n",i);
    printf("i size=%d\n",sizeof(i));
    //浮点型常量：前面必须有数字，后面必须有整数
    printf("%f\n",1.25e-5);
    printf("%f\n",.e-5);
}
