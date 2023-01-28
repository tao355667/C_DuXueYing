/*
Description
读取一个有符号数，对其进行左移，输出结果，对其进行右移，输出结果，例如，输入数值5，左移得到的结果是10，右移得到的结果是2。（不考虑左移后正值变为负值，负值变为正值的情况），每个输出占用2个字符位置，采用（%2d）
Input
输入的值为5
Output
输出左移1位后的值，为10，换行，再输出右移后的值为2。
Sample Input 1
5
Sample Output 1
10
 2
 */
#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    printf("%2d\n",a<<1);
    printf("%2d",a>>1);
    return 0;
}
