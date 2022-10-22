/*Description

输入一个学生的学号，姓名，性别，用结构体存储，通过scanf读取后，然后再通过printf打印输出


Input
学号，姓名，性别，例如输入 101 xiongda m


Output
输出和输入的内容一致，如果输入的是101 xiongda m，那么输出也是101 xiongda m*/
#include <stdio.h>
struct {
    int num;
    char name[100];
    char sex;
}stu1;
int main() {

    scanf("%d %s %c",&stu1.num,stu1.name,&stu1.sex);
    printf("%d %s %c",stu1.num,stu1.name,stu1.sex);

    return 0;
}
