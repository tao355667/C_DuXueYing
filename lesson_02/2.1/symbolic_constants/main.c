#include<stdio.h>

#define PI 3+2

void main()
{
//    PI=20;//�������ų������ܱ���ֵ
    int i=PI*2; //�ȼ���int i=3+2*2��ִ�к�iΪ7
	printf("%d\n",i);
    printf("i size=%d\n",sizeof(i));
    //�����ͳ�����ǰ����������֣��������������
    printf("%f\n",1.25e-5);
    printf("%f\n",.e-5);
}
