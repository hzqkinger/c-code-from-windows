#include<stdio.h>

void reword(char*p1, char*p2)
{
	


}



int main()
{
	char a[] = { "hello" };
	char b[] = { "world" };
	char *p1 = a;
	char *p2 = b;
	//char*pa = p1;
	//char*pb = p2;
	printf("%s\n", p1);
	printf("%s\n", p2);
	while (*p1 != '\0')
	{
		char temp;
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
		p1++;
		p2++;
	}
	printf("%s\n",a);
	printf("%s\n",b);
	system("pause");
	return 0;
}