#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>     
#include<string.h>    
#include<math.h>
#include<time.h>
#include<Windows.h>
#define MAX(a,b) ((a)>(b))?(a):(b)
#define AQUARE(x) x*x  //预处理①#define定义标识符②#define定义宏③宏和函数的区别④带副作用的宏参数
#define DOUBLE(x) x+x  //⑤#undef⑥条件编译、嵌套指令
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
int main()        //预处理阶段的主要任务包括删除注释、插入被#define指令包含的文件内容、定义、和
{                 //替换由#define指令定义的符号以及确定代码的部分内容是否应该根据一些条件编译指令
	char a = -1;   //编译进行
	unsigned char b = -1;
	printf("%s\n%d\n%d\n%d\n", __FILE__, __LINE__, a, b);
	//short num = 32767;
	//short int a = num + 2;
	//printf("%d\n", a);
	system("pause");
	return 0;
}
#endif