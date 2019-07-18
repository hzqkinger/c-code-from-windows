#pragma once


void Direct_insert_sort()//ֱ�Ӳ�������
{
	//�㷨˼�룺����i�����ݲ��뵽ǰ���Ѿ��ź����i-1��������ȥ(ֻ��Ҫһ����¼���ݵĸ����ռ䣻O(N^2) )
	//       Ҫ�㣺ʹ�ø����ռ䱣�����������ݣ��Ӻ���ǰ����Ӧ�����λ�ã��������ƶ�������ͬһѭ�����

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����������,Ĭ�ϵ�0�������Ѿ��������
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		int inter = arr[i]; // �����ռ�,ʹ�ø����ռ䱣�����������ݣ�
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (inter < arr[j]){ arr[j + 1] = arr[j]; }//����������
			else { break; }
		}
		arr[j + 1] = inter;
	}
	printf("ֱ�Ӳ�������\n");
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%3d", arr[i]); printf("\n");
}
void Binary_insert_sort()
{
	//�㷨˼�룺���ڸò�����������������н��еĲ��ҺͲ��룬���������۰���ҵ�˼·���ҵ������λ��
	//(ֻ��Ҫһ����¼���ݵĸ����ռ䣻O(N^2) )

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����������,Ĭ�ϵ�0�������Ѿ��������
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		int inter = arr[i]; // �����ռ�,ʹ�ø����ռ䱣�����������ݣ�
		int first = 0, last = i; //[0,i)    //����������
		while (first < last)//�ҵ���Ҫ�����λ��
		{
			if (arr[(first + last) / 2]>inter){ last = (first + last) / 2; }
			else { first = (first + last) / 2 + 1; }
		}
		for (last = i; last >= first; --last){ arr[last] = arr[last - 1]; }//Ų������
		arr[first] = inter;//��������
	}
	printf("�۰��������\n");
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%3d", arr[i]); printf("\n");
}
void TwoPath_insert_sort()//2-·��������
{
	//�㷨˼·�����۰��������Ļ����ϸĽ���Ŀ����Ϊ�˼��������������Ų�����ݵĴ���������Ҫn�����ݵ�
	//�����ռ�����d[n](����Ԫ����Ϊarr[n]  O(N^2) )��
	//  Ҫ�㣺����d[0]=arr[0]������d[0]���������Ѿ��ź���������д����м�λ�õ����ݣ�����������key<d[0],
	//        ����뵽d[0]֮ǰ����֮���������first��lastָ��ֱ�ָ���������еĵ�һ�������һ�����ݡ�

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����������,Ĭ�ϵ�0�������Ѿ��������
	const int N = sizeof(arr) / sizeof(arr[0]);
	int d[N]; d[0] = arr[0];//������ԭ����һ����С�ĸ����ռ䣬����arr[0]��ֵ��d[0]
	int *last = d, *first = d + N;
	for (int i = 1; i < N; ++i)
	{
		int fi2, la2;
		if (arr[i] > d[0])
		{
			if (last == d){ last++; *last = arr[i]; continue; }//�ȸ�d[1]����ֵ����Ȼû���Ƚ���
			fi2 = 0; la2 = last - d + 1; last++;//[1,la2)  //����������
			while (fi2 < la2)//�ҵ���Ҫ�����λ��
			{
				if (arr[i] < d[(fi2 + la2) / 2]){ la2 = (fi2 + la2) / 2; }
				else { fi2 = (fi2 + la2) / 2 + 1; }
			}
			{for (la2 = last - d; la2 > fi2; --la2){ d[la2] = d[la2 - 1]; }}//Ų������
			d[fi2] = arr[i];//��������
		}
		else
		{
			if (d + N == first){ first--; *first = arr[i]; continue; }//�ȸ�d[N - 1]����ֵ����Ȼû���Ƚ���
			fi2 = first - d; la2 = N; first--;//[fi2,N)
			while (fi2 < la2)//�ҵ���Ҫ�����λ��
			{
				if (arr[i] < d[(fi2 + la2) / 2]){ la2 = (fi2 + la2) / 2; }
				else { fi2 = (fi2 + la2) / 2 + 1; }
			}
			{for (la2 = first - d; la2 < fi2 - 1; ++la2){ d[la2] = d[la2 + 1]; }}//Ų������
			d[--fi2] = arr[i];//��������
		}
	}
	int i, j = 0;
	for (i = first - d; i < N; ++i){ arr[j++] = d[i]; }
	for (i = 0; i <= last - d; ++i){ arr[j++] = d[i]; }
	printf("2-·��������\n");
	for (i = 0; i < N; ++i)
		printf("%3d", arr[i]); printf("\n");
}
void TwoPath2_insert_sort()//2-·��������
{
	//�㷨˼·�����۰��������Ļ����ϸĽ���Ŀ����Ϊ�˼��������������Ų�����ݵĴ���������Ҫn�����ݵ�
	//�����ռ�����d[2n](����ԭ����Ϊarr[n]  O(N^2) )��
	//  Ҫ�㣺����d[n]=arr[0]������d[0]���������Ѿ��ź���������д����м�λ�õ����ݣ�����������key<d[0],
	//        ����뵽d[0]֮ǰ����֮���뵽d[n]֮��

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����������,Ĭ�ϵ�0�������Ѿ��������
	const int N = 2 * sizeof(arr) / sizeof(arr[0]);
	int d[N]; d[N / 2] = arr[0];//����ԭ���������ĸ����ռ䣬����arr[0]��ֵ��d[len]
	int *sla = d - 1, *bla = d + N / 2;
	for (int i = 1; i < N / 2; ++i)
	{
		int first, last;  //����������
		if (arr[i] < d[N / 2])
		{
			if (sla + 1 == d){ sla++; *sla = arr[i]; continue; }//�ȸ�d[0]����ֵ����Ȼû���Ƚ���
			first = 0; last = sla - d + 1; sla++;//[0,sla)
		}
		else
		{
			if (bla == d + N / 2){ bla++; *bla = arr[i]; continue; }//�ȸ�d[N/2+1]����ֵ����Ȼû���Ƚ���
			first = N / 2 + 1; last = bla - d + 1; bla++;//[N/2+1,bla)
		}
		while (first < last)//�ҵ���Ҫ�����λ��
		{
			if (arr[i] < d[(first + last) / 2]){ last = (first + last) / 2; }
			else { first = (first + last) / 2 + 1; }
		}
		if (arr[i] < d[N / 2])
		for (last = sla - d; last > first; --last){ d[last] = d[last - 1]; }//Ų������
		else
		for (last = bla - d; last > first; --last){ d[last] = d[last - 1]; }//Ų������
		d[first] = arr[i];//��������
	}
	int i, j = 0;
	for (i = 0; i <= sla - d; ++i){ arr[j++] = d[i]; }
	for (i = N / 2; i <= bla - d; ++i){ arr[j++] = d[i]; }
	printf("2-·��������\n");
	for (i = 0; i < N / 2; ++i)
		printf("%3d", arr[i]); printf("\n");
}
void SlinkList_insert_sort()//���������
{
	//#define SIZE 100        (�����õ��Ǿ�̬�������˸о���vector<Node*>�����һЩ)
	//typedef struct data{datatype _data;int next}DataNode;//�������ݽṹ�Ľ��
	//typedef struct{DataNode arr[SIZE];int length}SlinkList;//���徲̬��������

	//�㷨˼·������������˵���ľ�̬����������Ϊ�����������еĴ洢�ṹ������Ϊ�˲��뷽�������
	//       ��SlinkList.arr[0].data = MAXINT������SlinkList.arr[0].next =1;SlinkList.arr[1].next =0;
	//    Ȼ�����ν��±�Ϊ2��n�Ľ�㰴���ݹؼ��ַǵݼ�������뵽ѭ��������  O(N^2)

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����������,Ĭ�ϵ�0�������Ѿ��������
	const int Size = sizeof(arr) / sizeof(arr[0]) + 1;  //ע�⣬���ַ���ֻ����c++�ã�
	typedef struct { int _data; int _next; }DataNode;//�������ݽṹ�Ľ��
	DataNode arr2[Size];    //���ٸ����ռ�
	arr2[0]._data = MAXINT; arr2[0]._next = 1; arr2[1]._next = 0;
	for (int i = 0; i < Size - 1; ++i)	{ arr2[i + 1]._data = arr[i]; }

	for (int i = 2; i < Size; ++i)//Ѱ�ҿ��Բ����λ�ã����޸��±�
	{
		int prev = 0, next = arr2[0]._next;
		while (arr2[i]._data > arr2[next]._data){ prev = next; next = arr2[next]._next; }
		arr2[i]._next = next; arr2[prev]._next = i;
	}
	int j = 0;
	for (int next = arr2[0]._next; j < Size - 1;)//����̬�������źõ��������θ�ֵ��ԭ����arr
	{
		arr[j++] = arr2[next]._data; next = arr2[next]._next;
	}

	printf("���������\n");
	for (j = 0; j < Size - 1; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Diminish_Increment_sort()//ϣ������
{
	//�㷨˼·������������������зֳ����ɸ���С�������У��������н���ֱ�Ӳ�������
	//      (ifȡϣ���������У�O(N^1.5) )  dlta[k] = 2^(t-k+1)-1;

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����������,Ĭ�ϵ�0�������Ѿ��������
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i, j, increment;

	for (increment = N / 2; increment > 0; increment /= 2)
	{
		for (i = increment; i < N; ++i)
		{
			int tmp = arr[i];
			for (j = i; j >= increment; j -= increment)
			{
				if (tmp < arr[j - increment]){ arr[j] = arr[j - increment]; }
				else { break; }
			}
			arr[j] = tmp;
		}
	}
	printf("ϣ������\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}

void Bubble_sort()//ð������
{
	//�㷨˼�룺�ܹ�����N-1��ð�ݣ���i��ð��ѡ������������ݷ���N-1-i���±�λ����   O(N^2)

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	for (i = 0; i < N - 1; ++i)
	{
		for (j = 0; j < N - 1 - i; ++j)
		{
			if (arr[j]>arr[j + 1]){ swap(arr[j], arr[j + 1]); }
		}
	}
	printf("ð������\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Qsort(int*arr, int low, int high)//�ݹ��������
{
	//tips��������Ϊlow��high������������λ�����λ��

	if (low >= high)return;//�ݹ�ķ�������
	int tmplow = low, tmphigh = high;
	//int pivotloc = low;//��ʼѡȡ����Ŧλ��   ��ѡ��ÿ���������еĵ�һ��Ԫ����Ϊ��Ŧ
	int tmparr[3] = { low, (low + high) / 2, high }; //��ѡȡ��������ˣ��Ҷ˺�����λ���ϵ�����Ԫ�ص���ֵ��Ϊ��Ŧ
	if (arr[tmparr[0]] > arr[tmparr[1]]){ swap(tmparr[0], tmparr[1]); }
	if (arr[tmparr[0]] > arr[tmparr[2]]){ swap(tmparr[0], tmparr[2]); }
	if (arr[tmparr[1]] > arr[tmparr[2]]){ swap(tmparr[1], tmparr[2]); }
	int pivotloc = tmparr[1];

	int pivotkey = arr[pivotloc];//��¼��Ŧλ�ö�Ӧ��ֵ
	while (low < high)
	{
		while (low < high&&arr[high] >= pivotkey){ --high; }//�ȴ�highλ��ʼ����
		swap(arr[low], arr[high]);
		while (low < high&&arr[low] <= pivotkey){ ++low; }//���lowλ����
		swap(arr[low], arr[high]);
	}

	pivotloc = low;//������Ŧλ��
	Qsort(arr, tmplow, pivotloc - 1);//�Ե��ӱ�ݹ�����
	Qsort(arr, pivotloc + 1, tmphigh);//�Ը��ӱ�ݹ�����
}
void Quick_sort()//��������(Ҳ��һ�ַ��εĵݹ��㷨)
{
	//�㷨˼�룺�Ӵ�����������ѡ��һ������Ϊ��Ŧ����Ϊk,���������k�������ƶ���k�ĺ��棬С��k���ƶ���k��ǰ��
	//        �˹��̳�Ϊһ�˿������򡣶Խ������������ֱ������ͬ�Ĳ�����ֱ���ֱ�ĳ��Ȳ�����1
	//Ҫ�㣺����ѡ����Ŧ�ķ��� ��ѡ�������еĵ�һ��Ԫ����Ϊ��Ŧ
	//                         �������������ѡ��Ԫ����Ϊ��Ŧ
	//                         ��ѡȡ��������ˣ��Ҷ˺�����λ���ϵ�����Ԫ�ص���ֵ��Ϊ��Ŧ

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	const int N = sizeof(arr) / sizeof(arr[0]);

	Qsort(arr, 0, N - 1);

	printf("��������\n");//��ƽ��ʱ����ԣ�����������Ŀǰ��Ϊ��õ�һ���ڲ����򷽷�
	for (size_t j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}

void Simple_select_sort()//��ѡ������
{
	//�㷨˼�룺�ӵ�i�����ݿ�ʼ��ͨ��n-1-i�����ݱȽϣ���n-i��������ѡ����С�Ĳ��͵�i�����ݽ���   O(N^2)

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i, j;
	for (i = 0; i < N; ++i)
	{
		for (j = i + 1; j < N; ++j)
		{
			if (arr[i]>arr[j]){ swap(arr[i], arr[j]); }
		}
	}
	printf("��ѡ������\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Tree_select_sort()//����ѡ�����ƽ���������
{
	//�㷨˼�룺���ȶ�n����¼���������Ƚϣ�Ȼ����ʤ��֮���ٽ��������Ƚϣ�����ظ�ֱ��������С�ؼ��ֵļ�¼Ϊֹ
	//          ��ѡ����С�ؼ��֣�����Ҫ��Ҷ�ӽ���е���С�ؼ��ָ�Ϊ���ֵ��Ȼ��Ӹ�Ҷ�ӽ�㿪ʼ����(��)���ֵ�
	//          �Ĺؼ��ֽ��бȽϣ��޸Ĵ�Ҷ�ӽ�㵽�� ��·���ϸ��ڵ�ؼ��֣�������Ĺؼ��ּ�Ϊ��С�ؼ���
	//  ȱ�ݣ������洢�ռ�϶࣬���ֵ���ж���ıȽ�                                   O(NlogN)

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = 0, k;
	while (pow(2, i) < N)++i;
	k = 2 * pow(2, i); int tempk = k;
	int *arr2 = (int*)malloc(k*sizeof(int));//�������ռ�
	for (i = N; i < k; ++i)arr2[i] = MAXINT;
	for (i = k / 2 - 1, j = 0;/* i < k / 2 + N - 1*/j < N; ++i){ arr2[i] = arr[j++]; }

	for (; k / 2; k /= 2)//���ó�ʼ����ȫ������
	{
		for (i = k / 2 - 1; i < k - 1; i += 2)
		{
			if (arr2[i] < arr2[i + 1]){ arr2[(i - 1) / 2] = arr2[i]; }
			else{ arr2[(i - 1) / 2] = arr2[i + 1]; }
		}
	}
	k = tempk;
	for (i = 0; i < N; ++i)
	{
		arr[i] = arr2[0];
		//������Է�װ��һ���������ú������������ҵ���ӦҶ�ӽ�㣬Ȼ�����ϵ���
		int parent = 0; int child = 0;
		while (child < k)//�ҵ���������ȵ�Ҷ�ӽ��
		{
			child = 2 * parent + 1;
			if (child<k && arr2[parent] != arr2[child]){ child++; }
			if (child < k){ parent = child; }
		}
		arr2[parent] = MAXINT;//�޸ĸ�����Ժ����µ�������
		parent = (parent - 1) / 2; child = parent * 2 + 1;
		while (child > 1)
		{
			child = parent * 2 + 1;
			if (arr2[child] < arr2[child + 1]){ arr2[parent] = arr2[child]; }
			else{ arr2[parent] = arr2[child + 1]; }

			parent = (parent - 1) / 2;
		}
	}
	printf("����ѡ������\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Adjdown_heap(int*arr, int i, int N)//���µ����㷨
{
	int parent = i, child = parent * 2 + 1;
	while (child < N)
	{
		if (child + 1 < N && arr[child + 1] > arr[child]){ child++; }//����ѵıȽ�
		if (arr[child] > arr[parent])//����ѵıȽ�
		{
			swap(arr[parent], arr[child]);
			parent = child; child = parent * 2 + 1;
		}
		else{ break; }
	}
}
void Heap_select_sort()//������   (�ֲ�������ѡ�������ȱ��)
{
	//�㷨˼�룺�������д洢�����ݿ���һ����ȫ��������������ȫ��������˫�׽��ͺ��ӽ��֮������ڹ�ϵѡ������
	//      ����ѣ�˫�׽��һ��>=���ӽ��                                O(NlogN)
	//      С���ѣ�˫�׽��һ��<=���ӽ��

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//�����򽨴��
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = (N - 1) / 2; i >= 0; --i)//��������    ������һ����ʼ�Ĵ���ѣ�
	{
		//int parent = i, child = parent * 2 + 1;
		//while (child < N)//���µ����㷨
		//{
		//	if (child + 1 < N && arr[child] < arr[child + 1]){ child++; }
		//	if (arr[parent] < arr[child])
		//	{
		//		swap(arr[parent], arr[child]);
		//		parent = child; child = parent * 2 + 1;
		//	}
		//	else{ break; }
		//}
		Adjdown_heap(arr, i, N);
	}

	for (i = N - 1; i >= 0; --i)//ÿ�ν��Ѷ�������Ų��arr[i]����Ȼ���ڵ���
	{
		swap(arr[0], arr[i]);
		//int parent = 0, child = parent * 2 + 1;
		//while (child < i)//���µ����㷨
		//{
		//	if (child + 1 < i && arr[child] < arr[child + 1]){ child++; }
		//	if (arr[parent] < arr[child])
		//	{
		//		swap(arr[parent], arr[child]);
		//		parent = child; child = parent * 2 + 1;
		//	}
		//	else{ break; }
		//}
		Adjdown_heap(arr, 0, i);

	}
	printf("������\n");
	for (i = 0; i < N; ++i)
		printf("%3d", arr[i]); printf("\n");
}

void merge_sort()//�鲢����
{
	//�㷨˼�룺���ʼ���г���Ϊn������n�����п���n������������У�Ȼ�������ϲ����õ�һ��ceil(n/2)����Ϊ2��
	//          ���������С��ڴ˻������ٶԳ���Ϊ2�����������н��иò����򣬵õ�����Ϊ4�������У�����ظ�
	//          ֱ���õ�һ������Ϊn����������Ϊֹ                   O(NlogN)
}

void Bucket_sort()//Ͱʽ����   ���кܴ�ľ����ԣ���������ͳ���ַ���ȴ�Ǻܰ���
{
	//�㷨˼�룺������һ����Ȼ���������ǵ����ֵ������100����ô�����踨������d[101]����������Ԫ��ֵ��Ϊ0
	//          Ȼ���ԭ������б�������arr[i]ֵΪ�±��d[arr[i]]����1

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int d[101], i, j = 0;//����ϣ���˼��
	for (i = 0; i < 101; ++i){ d[i] = 0; }

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){ d[arr[i]]++; }

	printf("Ͱʽ����\n");
	for (i = 0; i < 101; ++i)
	{
		while (d[i]){ printf("%3d", i);/* arr[j++] = i; */d[i]--; }
	}
	printf("\n");

}


//����ڲ����򷽷����ٲ�������ڿ��������ѡ������ܹ鲢����ݻ�������
void Test18()
{
	Direct_insert_sort();     //��ֱ�Ӳ�������            O(N^2)
	Binary_insert_sort();     //���۰��������            O(N^2)
	TwoPath2_insert_sort();   //��2-·��������            O(N^2)     //�������򷽷�Ҳ���ڢ��ϸĽ���
	TwoPath_insert_sort();    //��2-·��������(��)        O(N^2)     //�������򷽷����ڢ��ϸĽ���
	SlinkList_insert_sort();  //�ݱ��������              O(N^2)
	Diminish_Increment_sort();//��ϣ������                O(NlogN)   //���������

	Bubble_sort();            //��ð������                O(N^2)
	Quick_sort();             //�ڿ�������                O(NlogN)    //ûд�ǵݹ�д��

	Simple_select_sort();     //�ټ�ѡ������            O(N^2)
	Tree_select_sort();       //�����������ƽ���������  O(NlogN)
	Heap_select_sort();       //�۶�����                  O(NlogN)

	merge_sort();             //�ٹ鲢����                O(NlogN)   //ûд

	//�ٻ�������                           //ûд

	Bucket_sort();            //��Ͱʽ����                O(N)
}