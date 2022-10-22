/*Description

利用while或者for循环计算n！的值。

提示：n！＝1*2*3…*n


Input
一个正整数n，1≤n≤10。


Output
n！的值。*/
#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int sum=1;
    while(n)
    {
        sum *= n;
        n--;
    }
    printf("%d\n",sum);
    return 0;
}
