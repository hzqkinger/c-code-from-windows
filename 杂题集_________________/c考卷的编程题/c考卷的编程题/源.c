#define _CRT_SERECURE_NO_WARNINGS
#include<stdio.h>
//1��	�����ʵ�����¹��ܵĺ���
//���ܣ�ʵ�ֶ�һ��8 bit���ݣ�unsigned char���ͣ���ָ��λ�������nλ������0������1����������������λ���䡣
//����ԭ�ͣ�
//void bit_set(unsigned char *p_data, unsigned char position, int flag)
//��������˵����
//p_data ��ָ����Դ���ݣ�position��ָ��λ��ȡֵ��Χ1~8����flag��ʾ����0������1����
//
//2��	��ʵ���ַ�����ѭ����λ���������磺��abcdefghi��ѭ������2λ���ǡ�hiabcdefg��.
//����ԭ�ͣ�void RightLoopMove(char *pStr, unsigned short steps)
//��������˵����
//pStr : Point to a ��\0�� terminated string
//   steps : The rotate shift numbers
//
//		   3. ���д����ʵ���ַ�����������ת�������������ַ�����12345�����������12345
void bit_set(unsigned char *p_data, unsigned char position, int flag)
{
	unsigned int flag1 = 1;
	//while (position > 1)
	//{
	//	flag1 <<= 1;
	//	position--;
	//}
	flag1 <<= position - 1;
	if (flag == 0)
		*p_data = *p_data & (~flag1);
	else
		*p_data = *p_data | flag1;
}
void RightLoopMove(char *pStr, unsigned short steps)
{

}
//��һ��͵ڶ���
int main()
{
	unsigned char uc = 0;//0000 0000
	bit_set(&uc, 4, 1);
	printf("%u\n", uc);
	system("pause");
	return 0;
}
//��������
//int main()
//{
//	char *pint = "12345";
//	int sum = 0;
//	while (*pint)
//	{
//		sum = 10 * sum + (*pint - '0');
//		pint++;
//	}
//	printf("%d\n", sum);
//	system("pause");
//	return 0;
//}