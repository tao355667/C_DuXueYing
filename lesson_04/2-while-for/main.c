#include <stdio.h>
//while for
int main() {
    //求1-100的和
    int i;
    int total=0;

    for(i=1;i<=100;i++) {
        total += i;
    }
    printf("sum of 1-100 = %d\n",total);

    i=1;total=0;
    while(i<=100000)
    {
        total+=i;
        if(i>=100)break;
        i++;
    }
    printf("sum of 1-100 = %d\n",total);
    //求1-100的奇数和
    i=1;total=0;
    for(i=1;i<=100;i++) {
        if(i%2==0)continue;
        total += i;
    }
    printf("sum of 1,3,5,7...97,99 = %d\n",total);

    return 0;
}
