#include <stdio.h>
//输入：32 s 12.5
int main() {
    int i,ret;
    float f;
    char c;
    //在%c前加空格，可通过格式跳过空格这个字符
    //若不加空格则输入会出错，%c接受了空格，之后的字符无法被float接收，ret的值为2,
    ret= scanf("%d %c%f",&i,&c,&f);//scanf可以有返回值，表示配对成功的个数
    printf("ret=%d i=%d c=%c f=%f\n",ret,i,c,f);

//    ret=scanf("%f",&f);
//    printf("ret=%d f=%f\n",ret,f);
    return 0;
}
