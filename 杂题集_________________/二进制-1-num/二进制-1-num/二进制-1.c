#include<stdio.h>
#include<Windows.h>
int main()
{
	int num = 0;
	int count = 0;
	printf("������һ��ʮ������: \n");//����������ܼ��㸺�������Ʋ����е�1�ĸ�����
	scanf_s("%d", &num);               //��Ϊ��������λʱ��������Զ���1���롣  

	while (num != 0)//���Ҫ���������Ʋ����е�1�ĸ�����whileѭ���е�����Ӧ�øĳ�ֻѭ��32��.
	{
		//num = num &(num - 1);//���Ƿ����������ַ�����˼���ǽ�num�ӵ�λ����λ��1�������
		//count++;
		if ((num & 1) == 1)
			count++;
		num = num >> 1;

	}
	printf("%d\n", count);
	system("pause");
	return 0;
}