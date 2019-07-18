#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main(){
	int a = 20;
	if (1 <= a <= 10)      //居然还有这种操作
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
#if 0

int main(){
	int a = 10, b = -25;    //操作符之间优先级验算
	int c = 0, d = 3;
	int e = 20;
	printf("%d\n", (a==b==c));
	system("pause");
	return 0;
}

int main(）{          //移位操作符左右操作数               
	int a = 2;
	int b = 0;
	int c = 0;
	a >> 1;
	//c = 1 >> a;
	printf("%d\n", a);
	system("pause");
	return 0;
}
#endif

//int main(){            //0xaaaaaaaa的用法
//	int b = 11;
//	b = b&(0Xaaaaaaaa);//每一个a代表1010
//	printf("%d\n", b);
//	system("pause");
//	return 0;
//}

//int main(){     //证明a = x = y + 3中a,x不都是相同
//	char a = 1;
//	int x = 2;
//	int y = 256;
//	a = x = y + 3;
//	printf("%d  %d", a, x);
//	system("pause");
//	return 0;
//}

//其他：下表引用[],函数调用，结构成员，对象成员选择. 指针成员选择->
//单目操作符：！，~，++，--, +, -, &, *, sizeof, (类型)
//算术操作符：+，-，*，/，%                          ①取模运算化成位运算{a%(2^n)等价于a&(2^n-1)}
//移位操作符：>>，<<                                 ②取模运算中，余数与被除数符号一致（被除数/除数=商...余数）
//关系操作符：>,>=,<,<=,!=,==                        ③乘法运算化成位运算{a*(2^n)等价于a<<n}
//位操作符：& ，| ， ^                               ④除法运算化成位运算{a/(2^n)等价于a>>n}注意a是负数结果可能不同
//逻辑操作符：||,&&,                                
//条件操作符：expression1 ? expression2 : expression3
//复合赋值符：+=，-=，*=，/=，%=，<<=,>>=,&=,|=,^=
//赋值：=
//逗号操作符：，