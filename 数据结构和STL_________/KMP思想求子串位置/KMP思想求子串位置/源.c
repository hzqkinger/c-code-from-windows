#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<CoreWindow.h>//①BF算法 ②KMP   ③BM  ④Sundy

//①一般的子串查找算法（BF算法）
char *my_strstr(const char *s1, const char *s2)//确定字符串s2在字符串s1中第一次出现的位置
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

//②KMP算法
static int next[15] = { 99 };
//未改进的KMP算法：这里设计的next[]就有一个缺陷，那就是next[0]弃之不用，导致字符串t第零个字符不能参与比较。
void Get_next(char *t, int next[])//求next[]的函数
{
	size_t i = 1, j = 0;
	next[1] = 0;
	while (i <= strlen(t))
	{
		if (j == 0 || t[i] == t[j])//每步比较都是基于前面的比较（比如子串abaabc的next[]={X,0,1,1,2,2,3}）
		{                //next[0]弃之不用，next[1]=0默认
			++i, ++j;    //next[2]需要比较next[1]个字符，匹配上就+1结束，
			next[i] = j; //next[3]需要比较next[2]个字符，匹配上就+1结束，否则向前推一位，比较next[1]个字符，匹配上就+1结束，依次类推
		}                //next[4]需要比较next[3]个字符，匹配上就+1结束，否则向前推一位，比较next[2]个字符，匹配上就+1结束，依次类推
		else             //next[5]需要比较next[4]个字符，匹配上就+1结束，否则向前推一位，比较next[3]个字符，匹配上就+1结束，依次类推
			j = next[j];
	}
}
int index_kmp(char *s,char *t)
{
	Get_next(t, next);//求next[]，
	int i = 0, j = 1;
	while (i <= strlen(s) && j < strlen(t))
	{
		if (j == 0 || s[i] == t[j])++i, ++j;//字符串t是从第一位开始比较的，第零位弃之不用。
		else j = next[j];
	}
	if (j >= strlen(t)) return i - strlen(t) + 1;
	else return 0;
}

//改进的KMP算法：这里设计的next[]存储数据是从next[0]开始的，字符串t第零个字符可以参加比较。
void Get_next2(char *t, int next[])//求next[]的函数
{
	size_t i = 1, j = 0;//跟原始求next数组操作一样
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
	for (i = 0; i < sizeof(next) / sizeof(next[0]); ++i)//将next数组的值逐个往前挪一位，然后每个值减1.
		next[i] = next[i + 1] - 1;
}
int index_kmp2(char *s, char *t)
{
	Get_next2(t, next);//求next2[]，
	int i = 0, j = 0;
	while (i <= (int)strlen(s) && j < (int)strlen(t))//strlen()返回值是size_t类型，所以要强转。
	{
		if (j == -1 || s[i] == t[j])++i, ++j;
		else j = next[j];
	}
	if (j >= strlen(t)) return i - j;
	else return 0;
}

//有问题
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
	Get_next3(t, next,strlen(t));//求next3[]，
	int i = 0, j = 0;
	while (i <= (int)strlen(s) && j < (int)strlen(t))//strlen()返回值是size_t类型，所以要强转。
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

//④.1求子串位置的Sundy算法（思路，标记模式串,从前往后比，然后更新i的值）
int strStr(char *haystack, char *needle) {
	int len1 = strlen(haystack);
	int len2 = strlen(needle);

	int charStep[256];
	for (int i = 0; i < 256; ++i)
		charStep[i] = -1;
	for (int i = 0; i < len2; ++i)//标记模式串中的字符，并记录相同字符的最右边字符的在模式串中的下标
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
				if (charStep[(int)*p] == -1) {//表示模式串中没有主串中该字符
					i = p - haystack + 1;
				}
				else {//有
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

//④.2伪Sundy算法(思路，先把子串和主串粘起来，然后开始从后往前比较，然后更新i的值)
int index_Sundy(char *s, char *t)
{
	int ns = strlen(s);//主串长度
	int nt = strlen(t);//子串长度
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

//Sundy的操作：在匹配失败时，只关注文本串中 参加匹配 的最末字符的下一位字符，
//如果该字符没有在模式串中出现，则直接跳过的移动位数= 匹配串 长度+1；
//否则移动位数 = 模式串中最右端该字符到末尾的距离+1.

//④.3Sundy算法，严格按照上面的思路在走
int index_sundy2(char *s, char *t)
{
	int ns = strlen(s);//主串长度
	int nt = strlen(t);//子串长度
	int i = 0, j = 0;
	while (i <= ns - nt)
	{
		while (j < nt &&s[i] == t[j])++i, ++j;//这里一定要控制j<nt，不然子串中的'\0'也会参与比较（子串在末尾时会出错）
		if (j == nt)return i - j;
		else
		{
			int tmp = i - j;
			j = nt - 1;
			while (j>=-1&&s[tmp + nt] != t[j])--j;//看最末字符与模式串中字符匹配吗
			if (j == -1)//不匹配情况
			{
				i = tmp + nt + 1;
				j = 0;
			}
			else//匹配
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
	//char *t = "xabcac";//由于KMP算法的缺陷，所以子串中第零个位置不参与匹配
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