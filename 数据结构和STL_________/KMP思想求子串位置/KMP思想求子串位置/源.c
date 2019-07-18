#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<CoreWindow.h>//��BF�㷨 ��KMP   ��BM  ��Sundy

//��һ����Ӵ������㷨��BF�㷨��
char *my_strstr(const char *s1, const char *s2)//ȷ���ַ���s2���ַ���s1�е�һ�γ��ֵ�λ��
{
	while (*s1 != '\0')
	{
		const char *tmp1 = s1;
		const char *tmp2 = s2;
		while (*s2 != '\0'&&*tmp1++ == *s2)
		{
			s2++;
		}
		if (*s2 == '\0')
			return s1;
		else
		{
			s2 = tmp2;
			s1++;
		}
	}
	return NULL;
}

//��KMP�㷨
static int next[15] = { 99 };
//δ�Ľ���KMP�㷨��������Ƶ�next[]����һ��ȱ�ݣ��Ǿ���next[0]��֮���ã������ַ���t������ַ����ܲ���Ƚϡ�
void Get_next(char *t, int next[])//��next[]�ĺ���
{
	size_t i = 1, j = 0;
	next[1] = 0;
	while (i <= strlen(t))
	{
		if (j == 0 || t[i] == t[j])//ÿ���Ƚ϶��ǻ���ǰ��ıȽϣ������Ӵ�abaabc��next[]={X,0,1,1,2,2,3}��
		{                //next[0]��֮���ã�next[1]=0Ĭ��
			++i, ++j;    //next[2]��Ҫ�Ƚ�next[1]���ַ���ƥ���Ͼ�+1������
			next[i] = j; //next[3]��Ҫ�Ƚ�next[2]���ַ���ƥ���Ͼ�+1������������ǰ��һλ���Ƚ�next[1]���ַ���ƥ���Ͼ�+1��������������
		}                //next[4]��Ҫ�Ƚ�next[3]���ַ���ƥ���Ͼ�+1������������ǰ��һλ���Ƚ�next[2]���ַ���ƥ���Ͼ�+1��������������
		else             //next[5]��Ҫ�Ƚ�next[4]���ַ���ƥ���Ͼ�+1������������ǰ��һλ���Ƚ�next[3]���ַ���ƥ���Ͼ�+1��������������
			j = next[j];
	}
}
int index_kmp(char *s,char *t)
{
	Get_next(t, next);//��next[]��
	int i = 0, j = 1;
	while (i <= strlen(s) && j < strlen(t))
	{
		if (j == 0 || s[i] == t[j])++i, ++j;//�ַ���t�Ǵӵ�һλ��ʼ�Ƚϵģ�����λ��֮���á�
		else j = next[j];
	}
	if (j >= strlen(t)) return i - strlen(t) + 1;
	else return 0;
}

//�Ľ���KMP�㷨��������Ƶ�next[]�洢�����Ǵ�next[0]��ʼ�ģ��ַ���t������ַ����ԲμӱȽϡ�
void Get_next2(char *t, int next[])//��next[]�ĺ���
{
	size_t i = 1, j = 0;//��ԭʼ��next�������һ��
	next[1] = 0;
	while (i <= strlen(t))
	{
		if (j == 0 || t[i] == t[j])
		{
			++i, ++j;
			next[i] = j;
		}
		else
			j = next[j];
	}
	for (i = 0; i < sizeof(next) / sizeof(next[0]); ++i)//��next�����ֵ�����ǰŲһλ��Ȼ��ÿ��ֵ��1.
		next[i] = next[i + 1] - 1;
}
int index_kmp2(char *s, char *t)
{
	Get_next2(t, next);//��next2[]��
	int i = 0, j = 0;
	while (i <= (int)strlen(s) && j < (int)strlen(t))//strlen()����ֵ��size_t���ͣ�����Ҫǿת��
	{
		if (j == -1 || s[i] == t[j])++i, ++j;
		else j = next[j];
	}
	if (j >= strlen(t)) return i - j;
	else return 0;
}

//������
void Get_next3(char *str, int *next, int length)
{
	next[0] = -1;
	int k = -1;
	for (int q = 0; q < length - 1;)
	{
		if (k == -1 || str[k] == str[q])
			next[++q] = ++k;
		else k = next[k];

		//if (k == -1 || str[k] == str[q]){
		//	if (next[++q] = ++k)
		//		next[q] = next[k];
		//	else
		//		next[q] = k;
		//}
		//else k = next[k];
	}
}
int index_kmp3(char *s, char *t)
{
	Get_next3(t, next,strlen(t));//��next3[]��
	int i = 0, j = 0;
	while (i <= (int)strlen(s) && j < (int)strlen(t))//strlen()����ֵ��size_t���ͣ�����Ҫǿת��
	{
		//if (j == -1)++j;
		//else if (j == 0 && s[i] != t[j])++i;

		//else if (s[i] == t[j])++i, ++j;
		//else j = next[j - 1];
		if (j == -1 || s[i] == t[j])++i, ++j;
		else j = next[j];
	}
	if (j >= strlen(t)) return i - j;
	else return 0;
}

void test_next()
{
	char *t = "abcab";
	Get_next(t, next);
	for (int i = 0; i < sizeof(next) / sizeof(next[0]); ++i)
		printf("%d ", next[i]); printf("\n");

	//memset(next, 0, sizeof(next));
	Get_next2(t, next);
	for (int i = 0; i <sizeof(next) / sizeof(next[0]); ++i)
		printf("%d ", next[i]); printf("\n");

	memset(next, 0, sizeof(next));
	Get_next3(t, next,strlen(t));
	for (int i = 0; i <sizeof(next) / sizeof(next[0]); ++i)
		printf("%d ", next[i]); printf("\n");
}

//��.1���Ӵ�λ�õ�Sundy�㷨��˼·�����ģʽ��,��ǰ����ȣ�Ȼ�����i��ֵ��
int strStr(char *haystack, char *needle) {
	int len1 = strlen(haystack);
	int len2 = strlen(needle);

	int charStep[256];
	for (int i = 0; i < 256; ++i)
		charStep[i] = -1;
	for (int i = 0; i < len2; ++i)//���ģʽ���е��ַ�������¼��ͬ�ַ������ұ��ַ�����ģʽ���е��±�
		charStep[(int)needle[i]] = i;

	for (int i = 0; i <= len1 - len2;)
	{
		int j = 0;
		while (j < len2) {
			if (haystack[i] == needle[j]) {
				++i;
				++j;
			}
			else {
				char* p = haystack + i + len2 - j;
				if (charStep[(int)*p] == -1) {//��ʾģʽ����û�������и��ַ�
					i = p - haystack + 1;
				}
				else {//��
					i = p - charStep[(int)*p] - haystack;
				}
				break;
			}
		}
		if (j == len2) {
			return i - len2;
		}
	}
	return -1;
}

//��.2αSundy�㷨(˼·���Ȱ��Ӵ�������ճ������Ȼ��ʼ�Ӻ���ǰ�Ƚϣ�Ȼ�����i��ֵ)
int index_Sundy(char *s, char *t)
{
	int ns = strlen(s);//��������
	int nt = strlen(t);//�Ӵ�����
	int i, j, cns;
	i = j = cns = nt - 1;
	while (i<ns&&j>=0)
	{
		j = nt - 1;
		cns = i;
		while (s[cns] == t[j])
		{
			cns--;
			if (j == 0)
				return i - nt + 1;
			j--;
		}
		j = nt - 1;
		while (s[i + 1] != t[j])--j;
		if (j < 0)i = i + nt + 1;
		else i = i + nt - j;
	}
	return -1;
}

//Sundy�Ĳ�������ƥ��ʧ��ʱ��ֻ��ע�ı����� �μ�ƥ�� ����ĩ�ַ�����һλ�ַ���
//������ַ�û����ģʽ���г��֣���ֱ���������ƶ�λ��= ƥ�䴮 ����+1��
//�����ƶ�λ�� = ģʽ�������Ҷ˸��ַ���ĩβ�ľ���+1.

//��.3Sundy�㷨���ϸ��������˼·����
int index_sundy2(char *s, char *t)
{
	int ns = strlen(s);//��������
	int nt = strlen(t);//�Ӵ�����
	int i = 0, j = 0;
	while (i <= ns - nt)
	{
		while (j < nt &&s[i] == t[j])++i, ++j;//����һ��Ҫ����j<nt����Ȼ�Ӵ��е�'\0'Ҳ�����Ƚϣ��Ӵ���ĩβʱ�����
		if (j == nt)return i - j;
		else
		{
			int tmp = i - j;
			j = nt - 1;
			while (j>=-1&&s[tmp + nt] != t[j])--j;//����ĩ�ַ���ģʽ�����ַ�ƥ����
			if (j == -1)//��ƥ�����
			{
				i = tmp + nt + 1;
				j = 0;
			}
			else//ƥ��
			{
				i = tmp + nt - j;
				j = 0;
			}
		}
	}
	return -1;
}

int main()
{
	test_next();

	int i;
	char *s = "ababbcacabcabcd";
	char *t = "abcabcd";
	//char *s = "abacaabacabacabaabb";
	//char *t = "abaca";
	i = index_kmp3(s, t);
	printf("%d\n", i);

	//int i;
	//char *s = "ababbcacabcacbb";
	//char *t = "xabcac";//����KMP�㷨��ȱ�ݣ������Ӵ��е����λ�ò�����ƥ��
	//i = index_kmp(s, t);
	//printf("%d\n", i);

	//int i;
	////char *s = "ababbcacabcacbb";
	////char *t = "abcac";
	//char *s = "aaabaaaab";
	//char *t = "aaaab";
	//i = index_sundy2(s, t);
	//printf("%d\n", i);

	system("pause");
	return 0;
}