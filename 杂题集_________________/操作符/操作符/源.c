#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
int main(){
	int a = 20;
	if (1 <= a <= 10)      //��Ȼ�������ֲ���
		printf("yes\n");
	else
		printf("no\n");
	system("pause");
	return 0;
}
#if 0

int main(){
	int a = 10, b = -25;    //������֮�����ȼ�����
	int c = 0, d = 3;
	int e = 20;
	printf("%d\n", (a==b==c));
	system("pause");
	return 0;
}

int main(��{          //��λ���������Ҳ�����               
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

//int main(){            //0xaaaaaaaa���÷�
//	int b = 11;
//	b = b&(0Xaaaaaaaa);//ÿһ��a����1010
//	printf("%d\n", b);
//	system("pause");
//	return 0;
//}

//int main(){     //֤��a = x = y + 3��a,x��������ͬ
//	char a = 1;
//	int x = 2;
//	int y = 256;
//	a = x = y + 3;
//	printf("%d  %d", a, x);
//	system("pause");
//	return 0;
//}

//�������±�����[],�������ã��ṹ��Ա�������Աѡ��. ָ���Աѡ��->
//��Ŀ������������~��++��--, +, -, &, *, sizeof, (����)
//������������+��-��*��/��%                          ��ȡģ���㻯��λ����{a%(2^n)�ȼ���a&(2^n-1)}
//��λ��������>>��<<                                 ��ȡģ�����У������뱻��������һ�£�������/����=��...������
//��ϵ��������>,>=,<,<=,!=,==                        �۳˷����㻯��λ����{a*(2^n)�ȼ���a<<n}
//λ��������& ��| �� ^                               �ܳ������㻯��λ����{a/(2^n)�ȼ���a>>n}ע��a�Ǹ���������ܲ�ͬ
//�߼���������||,&&,                                
//������������expression1 ? expression2 : expression3
//���ϸ�ֵ����+=��-=��*=��/=��%=��<<=,>>=,&=,|=,^=
//��ֵ��=
//���Ų���������