#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<CoreWindow.h>
int main()
{
	srand(time(NULL));
	char arr[] = "aaaabbbbcc";
	int i = 0, j = 0;
	char *arr2 = (char*)malloc(sizeof(arr));
	char *p = arr2;
	*arr2 = arr[0];
	while (arr[i++])
	{
		if (*arr2 != arr[i])
		{
			arr2++;
			*arr2 = arr[i];
		}
	}
	//printf("%s\n", p);
	i = strlen(p);
	char *head = (char*)malloc(sizeof(p));
	memset(head, 0, sizeof(p));
	char*tmp2 = head, *tail = head+sizeof(p);
	while (i--)
	{
		tmp2 = head;
		j = rand() % strlen(p);
		while(p[j] != tmp2&&*tmp2 != '\0')
			tmp2++;
		if (*tmp2 == '\0')
			*tmp2 = p[j];
	}
	printf("%s\n", head);
	free(p);
	free(tmp2);
	system("pause");
	return 0;
}