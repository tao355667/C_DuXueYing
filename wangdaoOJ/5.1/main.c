/*Description

输入N个数（N小于等于100），输出数字2的出现次数；

解题提示：

整型数组读取5个整型数的方法如下：

int a[100];

for(int i=0;i<5;i++)

{

scanf("%d",&a[i]);

}


Input
输入的格式是两行

第一行输入要输的元素个数，比如5

第二行输入  1 2 2 3 2，那么输出结果为3，因为2出现了3次


Output
统计数字2出现的次数 */
#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int a[100];
    int sum=0;
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==2)
            sum++;
    }
    printf("%d",sum);
    return 0;
}
