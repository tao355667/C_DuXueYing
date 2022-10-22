#include <stdio.h>
//强制类型转换
int main() {
    int i=5;
    float f=i/2;
    printf("%f\n",f);//f=2.0
    //强制类型转换后
    float f1=(float)i/2;
    printf("%f\n",f1);//f1=2.5

    return 0;
}
