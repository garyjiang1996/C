#include <stdio.h>

int add(int x, int y) {
    return x + y;
}

int substract(int x, int y) {
    return x - y;
}

int two_num_op(int (*pf)(int,int),int x,int y) {
	return (*pf)(x,y);
}

int main() {
	int (*pfadd1)()=add;	//add��Ϊ��������������������ĵ�ַ��������ʽ��ת��Ϊһ������ָ��
	int (*pfadd2)()=*add;	//�ڷ����������ַ�ĺ���,�ͺ�����һ��֮����ʽ��ת��Ϊһ������ָ��
	int (*pfadd3)()=&add;	//ֱ�ӷ�����������ĵ�ַ��֮���ֵõ�һ������ָ��
	printf("%d %d %d\n",(*pfadd1)(1,2),(*pfadd2)(1,2),(*pfadd3)(1,2));	//output pfadd1~3
	
	int a,b;
	a=3; b=4;
	printf("two_num_op(%d,%d)=%d\n",a,b,two_num_op(add,a,b));
	printf("two_num_op(%d,%d)=%d\n",a,b,two_num_op(substract,a,b));
}


