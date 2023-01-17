#include <stdio.h>
//逻辑与与逻辑或短路运算
int main() {
    int i=0;
    i&&printf("you can't see me!\n");
    i=1;
    i||printf("you can't see me!\n");
    return 0;
}
