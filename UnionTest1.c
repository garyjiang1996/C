#include <stdio.h>

typedef union{
	int i;
	char ch[sizeof(int)];
}CHI;

struct Matrix3_3{
	union{
		struct{
			float _m11,_m12,_m13,_m21,_m22,_m23,_m31,_m32,_m33;
		}
		float m3_3[3][3];
	}matrix3_3;
};

int main(){
	CHI chi; //chi 可以被看作i同时也可看作ch
	int i;
	chi.i=1234; //hex:00 00 04 D2
	for(i=0;i<sizeof(int);i++){
		printf("%02hhX",chi.ch[i]); //D2 04 00 00
		//而x86系列则采用little endian方式存储数据
		//其实big endian是指低地址存放最高有效字节（MSB），
		//而little endian则是低地址存放最低有效字节（LSB）
		//low--->high,java,所有网络协议中采用big endian也称为网络字节序
	}
	//
	struct Matrix3_3 m;
//在需要整体用矩阵的时候可以用
//m._matrix.f （比如说传参，或者是整体赋值等）；需要用其中的几个元素的时候可以用
//m._matrix._f11那样可以避免用m.f[0][0]（这样不大直观，而且容易出错）

	return 0;
}