#pragma once


typedef struct
{
	unsigned int _weight;
	unsigned int _parent, _lchild, _rchild;
}HTNode,*HuffmanTree;

typedef int datatype;
typedef char ** HuffmanCode;


void Select(const HuffmanTree &ht, const size_t iht, size_t &s1, size_t &s2)
{
	//��HT[1~i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1,s2

	HuffmanTree h = ht + 1;//��ht�������ҵ���С��������ֵ��s1��Ȼ�������Ԫ�ص�_parent��ֵΪ1
	while (h->_parent != 0)
		h++;
	size_t off = h - ht;
	s1 = off;

	h += 1;
	while (h < ht + iht)
	{
		if (h->_parent == 0)
		{
			if (ht[s1]._weight > h->_weight)
			{
				s1 = h - ht;
			}
		}
		++h;
	}
	ht[s1]._parent = 1;

	h = ht + 1;//��ht�������ҵ���С��������ֵ��s2��Ȼ�������Ԫ�ص�_parent��ֵΪ1
	while (h->_parent != 0)
		h++;
	off = h - ht;
	s2 = off;

	h += 1;
	while (h < ht + iht)
	{
		if (h->_parent == 0)
		{
			if (ht[s2]._weight > h->_weight)
			{
				s2 = h - ht;
			}
		}
		++h;
	}
	ht[s2]._parent = 1;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, datatype *w, size_t n)
{                                                     //w�����飬n�������С
	if (n <= 1)return;

	//����һ��˳��ṹ�ĺշ���������
	size_t m = 2 * n - 1;
	HT = (HuffmanTree)malloc((m + 1)*sizeof(HTNode));
	HuffmanTree p = NULL; size_t i = 0;
	for (p = HT + 1, i = 1; i <= n; ++i, ++p, ++w)
	{
		p->_weight = *w;p->_parent = 0;p->_lchild = 0;p->_rchild = 0;
	}
	for (; i <= m; ++i,++p)
	{
		p->_weight = 0;p->_parent = 0;p->_lchild = 0;p->_rchild = 0;
	}
	for (i = n + 1; i <= m; ++i)
	{
		size_t s1, s2;
		Select(HT, i - 1, s1, s2);//��HT[1~i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1,s2
		HT[s1]._parent = i; HT[s2]._parent = i;
		HT[i]._lchild = s1;HT[i]._rchild = s2;
		HT[i]._weight = HT[s1]._weight + HT[s2]._weight;
	}

	//��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	HC = (HuffmanCode)malloc((n + 1)*sizeof(char*));
	char *cd = (char*)malloc(n*sizeof(char));//�������Ҫ�����������Ĺ����ռ䣨��һ��û���ף�Ϊʲô����n���ռ䣩
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		size_t start = n - 1;
		size_t c, f;
		for (c = i, f = HT[i]._parent; f != 0; c = f, f = HT[f]._parent)
		{
			if (HT[f]._lchild == c)cd[--start] = '0';
			else cd[--start] = '1';
		}
		HC[i] = (char*)malloc((n - start)*sizeof(char));
		strcpy(HC[i], &cd[start]);
	}
	free(cd);
}


void test()
{
	datatype w[] = { 5, 29, 7, 8, 14, 23, 3, 11 };
	size_t n = sizeof(w) / sizeof(w[0]);
	HuffmanTree HT = NULL; HuffmanCode HC = NULL;

	HuffmanCoding(HT, HC, w, n);

	for (size_t i = 1; i <= n; ++i)
	{
		printf("HC[%d] = %s\n", i, HC[i]);
	}
}