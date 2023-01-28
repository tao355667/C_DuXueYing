/*
Description
输入5个数，其中2个数出现2次，1个数是出现1次，找出出现1次的那个数，例如输入的是8 5 3 5 8，输出的值为3
Input
8 5 3 5 8
Output
3
Sample Input 1
8 5 3 5 8
Sample Output 1
3
 */

#include <stdio.h>

int main() {
    int a[5];
    int result=0;
    //读取
    for(int i=0;i<5;i++)
        scanf("%d",&a[i]);
    //查找
    for(int i=0;i<5;i++)
    {//找到只出现一次的数，出现偶数次的数会为0
        result^=a[i];
    }
    printf("%d",result);
    return 0;
}