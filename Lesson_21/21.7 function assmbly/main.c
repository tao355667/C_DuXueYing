/*
选择，循环-汇编

#生成汇编文件main.s，带注释
gcc -S -fverbose-asm main.c
#生成汇编文件main.s，32位，英特尔，带注释
gcc -m32 -masm=intel -S -fverbose-asm main.c
#需要有机器码时
#第一条 （Mac一致）
gcc -m32 -g -o main main.c
#第二条 (Mac去掉.exe后缀，写为main即可）
objdump --source main.exe >main.dump
 */
#include <stdio.h>

int add(int a, int b) {
    int ret;
    ret = a + b;
    return ret;
}

int main() {
    int a, b, ret;
    int *p;
    a = 5;
    p = &a;
    b = *p + 2;
    ret = add(a, b);
    printf("add result=%d\n", ret);
    return 0;
}