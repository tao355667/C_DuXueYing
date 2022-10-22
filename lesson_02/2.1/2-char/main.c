#include <stdio.h>
//大写变小写
int main() {
    char c='A';
    printf("'A'=%c\n",c);//以字符形式输出
    printf("'A'=%d\n",c);//以数值形式输出

    printf("'a'=%c\n",c+32);//以字符形式输出
    printf("'a'=%d\n",c+32);//以数值形式输出
    return 0;
}
