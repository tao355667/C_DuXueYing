/*Description

读取一个65到122之间的整型数，然后以字符形式输出它，比如读取了97，输出字符a


Input
读取一个整型数，整型数 大于等于65，小于等于122


Output
输出整型数 在ASCII表中对应的字符*/
#include <stdio.h>

int main() {
    int a;
    scanf("%d",&a);
    printf("%c\n",a);
    return 0;
}
