/*
 * 生成汇编文件main.s
 * gcc -S -fverbose-asm main.c
 */
#include <stdio.h>

int main() {
    int i=10;
    printf("%d",i);
    return 0;
}
