#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
#define MAX(a,b) ((a)>(b))?(a):(b)
#define AQUARE(x) x*x  //Ԥ�����#define�����ʶ����#define�����ۺ�ͺ���������ܴ������õĺ����
#define DOUBLE(x) x+x  //��#undef���������롢Ƕ��ָ��
int main(){
	int x = 2, y = 3, z = 3;
	y = AQUARE(x);
	z = AQUARE(x + 6);
	//z = MAX(5 * DOUBLE(x), ++y);
	//x = MAX(y, z);
	//x = MAX(++y, ++z);
	printf("%d\n%d\n%d\n", x, y, z);
	system("pause");
	return 0;
}

#if 0
int main()        //Ԥ����׶ε���Ҫ�������ɾ��ע�͡����뱻#defineָ��������ļ����ݡ����塢��
{                 //�滻��#defineָ���ķ����Լ�ȷ������Ĳ��������Ƿ�Ӧ�ø���һЩ��������ָ��
	char a = -1;   //�������
	unsigned char b = -1;
	printf("%s\n%d\n%d\n%d\n", __FILE__, __LINE__, a, b);
	//short num = 32767;
	//short int a = num + 2;
	//printf("%d\n", a);
	system("pause");
	return 0;
}
#endif