#pragma once


void Direct_insert_sort()//直接插入排序
{
	//算法思想：将第i个数据插入到前面已经排好序的i-1个数据中去(只需要一个记录数据的辅助空间；O(N^2) )
	//       要点：使用辅助空间保存待插入的数据，从后往前查找应插入的位置，查找与移动数据用同一循环完成

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//待排序的数据,默认第0个数据已经是有序的
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		int inter = arr[i]; // 辅助空间,使用辅助空间保存待插入的数据，
		int j = i - 1;
		for (; j >= 0; --j)
		{
			if (inter < arr[j]){ arr[j + 1] = arr[j]; }//假设排升序
			else { break; }
		}
		arr[j + 1] = inter;
	}
	printf("直接插入排序：\n");
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%3d", arr[i]); printf("\n");
}
void Binary_insert_sort()
{
	//算法思想：由于该插入排序是在有序表中进行的查找和插入，可以利用折半查找的思路来找到插入的位置
	//(只需要一个记录数据的辅助空间；O(N^2) )

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//待排序的数据,默认第0个数据已经是有序的
	for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		int inter = arr[i]; // 辅助空间,使用辅助空间保存待插入的数据，
		int first = 0, last = i; //[0,i)    //假设排升序
		while (first < last)//找到需要插入的位置
		{
			if (arr[(first + last) / 2]>inter){ last = (first + last) / 2; }
			else { first = (first + last) / 2 + 1; }
		}
		for (last = i; last >= first; --last){ arr[last] = arr[last - 1]; }//挪动数据
		arr[first] = inter;//插入数据
	}
	printf("折半插入排序：\n");
	for (size_t i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
		printf("%3d", arr[i]); printf("\n");
}
void TwoPath_insert_sort()//2-路插入排序
{
	//算法思路：在折半插入排序的基础上改进，目的是为了减少在排序过程中挪动数据的次数，但需要n个数据的
	//辅助空间数组d[n](假设元数组为arr[n]  O(N^2) )。
	//  要点：首先d[0]=arr[0]，并将d[0]看成是在已经排好序的序列中处于中间位置的数据；待插入数据key<d[0],
	//        则插入到d[0]之前，反之；最后在设first和last指针分别指向有序序列的第一个和最好一个数据。

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//待排序的数据,默认第0个数据已经是有序的
	const int N = sizeof(arr) / sizeof(arr[0]);
	int d[N]; d[0] = arr[0];//开辟与原数组一样大小的辅助空间，并将arr[0]赋值给d[0]
	int *last = d, *first = d + N;
	for (int i = 1; i < N; ++i)
	{
		int fi2, la2;
		if (arr[i] > d[0])
		{
			if (last == d){ last++; *last = arr[i]; continue; }//先给d[1]赋初值，不然没法比较了
			fi2 = 0; la2 = last - d + 1; last++;//[1,la2)  //假设排升序
			while (fi2 < la2)//找到需要插入的位置
			{
				if (arr[i] < d[(fi2 + la2) / 2]){ la2 = (fi2 + la2) / 2; }
				else { fi2 = (fi2 + la2) / 2 + 1; }
			}
			{for (la2 = last - d; la2 > fi2; --la2){ d[la2] = d[la2 - 1]; }}//挪动数据
			d[fi2] = arr[i];//插入数据
		}
		else
		{
			if (d + N == first){ first--; *first = arr[i]; continue; }//先给d[N - 1]赋初值，不然没法比较了
			fi2 = first - d; la2 = N; first--;//[fi2,N)
			while (fi2 < la2)//找到需要插入的位置
			{
				if (arr[i] < d[(fi2 + la2) / 2]){ la2 = (fi2 + la2) / 2; }
				else { fi2 = (fi2 + la2) / 2 + 1; }
			}
			{for (la2 = first - d; la2 < fi2 - 1; ++la2){ d[la2] = d[la2 + 1]; }}//挪动数据
			d[--fi2] = arr[i];//插入数据
		}
	}
	int i, j = 0;
	for (i = first - d; i < N; ++i){ arr[j++] = d[i]; }
	for (i = 0; i <= last - d; ++i){ arr[j++] = d[i]; }
	printf("2-路插入排序：\n");
	for (i = 0; i < N; ++i)
		printf("%3d", arr[i]); printf("\n");
}
void TwoPath2_insert_sort()//2-路插入排序
{
	//算法思路：在折半插入排序的基础上改进，目的是为了减少在排序过程中挪动数据的次数，但需要n个数据的
	//辅助空间数组d[2n](假设原数组为arr[n]  O(N^2) )。
	//  要点：首先d[n]=arr[0]，并将d[0]看成是在已经排好序的序列中处于中间位置的数据；待插入数据key<d[0],
	//        则插入到d[0]之前，反之插入到d[n]之后

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//待排序的数据,默认第0个数据已经是有序的
	const int N = 2 * sizeof(arr) / sizeof(arr[0]);
	int d[N]; d[N / 2] = arr[0];//开辟原数组两倍的辅助空间，并将arr[0]赋值给d[len]
	int *sla = d - 1, *bla = d + N / 2;
	for (int i = 1; i < N / 2; ++i)
	{
		int first, last;  //假设排升序
		if (arr[i] < d[N / 2])
		{
			if (sla + 1 == d){ sla++; *sla = arr[i]; continue; }//先给d[0]赋初值，不然没法比较了
			first = 0; last = sla - d + 1; sla++;//[0,sla)
		}
		else
		{
			if (bla == d + N / 2){ bla++; *bla = arr[i]; continue; }//先给d[N/2+1]赋初值，不然没法比较了
			first = N / 2 + 1; last = bla - d + 1; bla++;//[N/2+1,bla)
		}
		while (first < last)//找到需要插入的位置
		{
			if (arr[i] < d[(first + last) / 2]){ last = (first + last) / 2; }
			else { first = (first + last) / 2 + 1; }
		}
		if (arr[i] < d[N / 2])
		for (last = sla - d; last > first; --last){ d[last] = d[last - 1]; }//挪动数据
		else
		for (last = bla - d; last > first; --last){ d[last] = d[last - 1]; }//挪动数据
		d[first] = arr[i];//插入数据
	}
	int i, j = 0;
	for (i = 0; i <= sla - d; ++i){ arr[j++] = d[i]; }
	for (i = N / 2; i <= bla - d; ++i){ arr[j++] = d[i]; }
	printf("2-路插入排序：\n");
	for (i = 0; i < N / 2; ++i)
		printf("%3d", arr[i]); printf("\n");
}
void SlinkList_insert_sort()//表插入排序
{
	//#define SIZE 100        (书上用的是静态链表，个人感觉用vector<Node*>会更好一些)
	//typedef struct data{datatype _data;int next}DataNode;//定义数据结构的结点
	//typedef struct{DataNode arr[SIZE];int length}SlinkList;//定义静态链表类型

	//算法思路：假设以上述说明的静态链表类型作为待排数据序列的存储结构，并且为了插入方便起见，
	//       设SlinkList.arr[0].data = MAXINT；首先SlinkList.arr[0].next =1;SlinkList.arr[1].next =0;
	//    然后依次将下标为2至n的结点按数据关键字非递减有序插入到循环链表中  O(N^2)

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//待排序的数据,默认第0个数据已经是有序的
	const int Size = sizeof(arr) / sizeof(arr[0]) + 1;  //注意，这种方法只能在c++用，
	typedef struct { int _data; int _next; }DataNode;//定义数据结构的结点
	DataNode arr2[Size];    //开辟辅助空间
	arr2[0]._data = MAXINT; arr2[0]._next = 1; arr2[1]._next = 0;
	for (int i = 0; i < Size - 1; ++i)	{ arr2[i + 1]._data = arr[i]; }

	for (int i = 2; i < Size; ++i)//寻找可以插入的位置，并修改下标
	{
		int prev = 0, next = arr2[0]._next;
		while (arr2[i]._data > arr2[next]._data){ prev = next; next = arr2[next]._next; }
		arr2[i]._next = next; arr2[prev]._next = i;
	}
	int j = 0;
	for (int next = arr2[0]._next; j < Size - 1;)//将静态链表中排好的序列依次赋值给原数组arr
	{
		arr[j++] = arr2[next]._data; next = arr2[next]._next;
	}

	printf("表插入排序：\n");
	for (j = 0; j < Size - 1; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Diminish_Increment_sort()//希尔排序
{
	//算法思路：将待排序的数据序列分成若干个较小的子序列，对子序列进行直接插入排序，
	//      (if取希尔增量序列，O(N^1.5) )  dlta[k] = 2^(t-k+1)-1;

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//待排序的数据,默认第0个数据已经是有序的
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
	printf("希尔排序：\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}

void Bubble_sort()//冒泡排序
{
	//算法思想：总共进行N-1趟冒泡，第i趟冒泡选出来的最大数据放在N-1-i的下标位置上   O(N^2)

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
	printf("冒泡排序：\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Qsort(int*arr, int low, int high)//递归快速排序
{
	//tips：可以认为low和high是子数组的最低位和最高位，

	if (low >= high)return;//递归的返回条件
	int tmplow = low, tmphigh = high;
	//int pivotloc = low;//初始选取的枢纽位置   ①选择每个子数组中的第一个元素作为枢纽
	int tmparr[3] = { low, (low + high) / 2, high }; //③选取数组中左端，右端和中心位置上的三个元素的中值作为枢纽
	if (arr[tmparr[0]] > arr[tmparr[1]]){ swap(tmparr[0], tmparr[1]); }
	if (arr[tmparr[0]] > arr[tmparr[2]]){ swap(tmparr[0], tmparr[2]); }
	if (arr[tmparr[1]] > arr[tmparr[2]]){ swap(tmparr[1], tmparr[2]); }
	int pivotloc = tmparr[1];

	int pivotkey = arr[pivotloc];//记录枢纽位置对应的值
	while (low < high)
	{
		while (low < high&&arr[high] >= pivotkey){ --high; }//先从high位开始搜索
		swap(arr[low], arr[high]);
		while (low < high&&arr[low] <= pivotkey){ ++low; }//后从low位搜索
		swap(arr[low], arr[high]);
	}

	pivotloc = low;//更新枢纽位置
	Qsort(arr, tmplow, pivotloc - 1);//对底子表递归排序
	Qsort(arr, pivotloc + 1, tmphigh);//对高子表递归排序
}
void Quick_sort()//快速排序(也是一种分治的递归算法)
{
	//算法思想：从待排序数据中选择一个数据为枢纽，设为k,将其余大于k的数据移动至k的后面，小于k的移动至k的前面
	//        此过程称为一趟快速排序。对接下来的两个字表进行相同的操作，直到字表的长度不超过1
	//要点：三种选择枢纽的方法 ①选择数组中的第一个元素作为枢纽
	//                         ②在数组中随机选择元素作为枢纽
	//                         ③选取数组中左端，右端和中心位置上的三个元素的中值作为枢纽

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	const int N = sizeof(arr) / sizeof(arr[0]);

	Qsort(arr, 0, N - 1);

	printf("快速排序：\n");//就平均时间而言，快速排序是目前认为最好的一种内部排序方法
	for (size_t j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}

void Simple_select_sort()//简单选择排序
{
	//算法思想：从第i个数据开始，通过n-1-i次数据比较，从n-i个数据中选出最小的并和第i个数据交换   O(N^2)

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
	printf("简单选择排序：\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Tree_select_sort()//树形选排序或称锦标赛排序
{
	//算法思想：首先对n个记录进行两两比较，然后优胜者之间再进行两两比较，如此重复直到出现最小关键字的记录为止
	//          欲选出次小关键字，仅需要将叶子结点中的最小关键字改为最大值，然后从该叶子结点开始，和(左)右兄弟
	//          的关键字进行比较，修改从叶子结点到根 的路径上各节点关键字，则根结点的关键字即为次小关键字
	//  缺陷：辅助存储空间较多，最大值进行多余的比较                                   O(NlogN)

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i = 0, j = 0, k;
	while (pow(2, i) < N)++i;
	k = 2 * pow(2, i); int tempk = k;
	int *arr2 = (int*)malloc(k*sizeof(int));//开辅助空间
	for (i = N; i < k; ++i)arr2[i] = MAXINT;
	for (i = k / 2 - 1, j = 0;/* i < k / 2 + N - 1*/j < N; ++i){ arr2[i] = arr[j++]; }

	for (; k / 2; k /= 2)//建好初始的完全二叉树
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
		//下面可以封装成一个函数，该函数的作用是找到对应叶子结点，然后向上调整
		int parent = 0; int child = 0;
		while (child < k)//找到与根结点相等的叶子结点
		{
			child = 2 * parent + 1;
			if (child<k && arr2[parent] != arr2[child]){ child++; }
			if (child < k){ parent = child; }
		}
		arr2[parent] = MAXINT;//修改根结点以后，重新调整该树
		parent = (parent - 1) / 2; child = parent * 2 + 1;
		while (child > 1)
		{
			child = parent * 2 + 1;
			if (arr2[child] < arr2[child + 1]){ arr2[parent] = arr2[child]; }
			else{ arr2[parent] = arr2[child + 1]; }

			parent = (parent - 1) / 2;
		}
	}
	printf("树形选择排序：\n");
	for (j = 0; j < N; ++j)
		printf("%3d", arr[j]); printf("\n");
}
void Adjdown_heap(int*arr, int i, int N)//向下调整算法
{
	int parent = i, child = parent * 2 + 1;
	while (child < N)
	{
		if (child + 1 < N && arr[child + 1] > arr[child]){ child++; }//建大堆的比较
		if (arr[child] > arr[parent])//建大堆的比较
		{
			swap(arr[parent], arr[child]);
			parent = child; child = parent * 2 + 1;
		}
		else{ break; }
	}
}
void Heap_select_sort()//堆排序   (弥补了树形选择排序的缺陷)
{
	//算法思想：将数组中存储的数据看成一棵完全二叉树，利用完全二叉树中双亲结点和孩子结点之间的内在关系选择数据
	//      大根堆：双亲结点一定>=孩子结点                                O(NlogN)
	//      小根堆：双亲结点一定<=孩子结点

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };//排升序建大堆
	const int N = sizeof(arr) / sizeof(arr[0]);
	int i;
	for (i = (N - 1) / 2; i >= 0; --i)//排序趟数    （建好一个初始的大根堆）
	{
		//int parent = i, child = parent * 2 + 1;
		//while (child < N)//向下调整算法
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

	for (i = N - 1; i >= 0; --i)//每次将堆顶的数据挪到arr[i]处，然后在调整
	{
		swap(arr[0], arr[i]);
		//int parent = 0, child = parent * 2 + 1;
		//while (child < i)//向下调整算法
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
	printf("堆排序：\n");
	for (i = 0; i < N; ++i)
		printf("%3d", arr[i]); printf("\n");
}

void merge_sort()//归并排序
{
	//算法思想：设初始序列长度为n，将这n个序列看成n个有序的子序列，然后两两合并，得到一个ceil(n/2)长度为2的
	//          有序子序列。在此基础上再对长度为2的有序子序列进行该病排序，得到长度为4的子序列，如此重复
	//          直到得到一个长度为n的有序序列为止                   O(NlogN)
}

void Bucket_sort()//桶式排序   它有很大的局限性，但是用来统计字符串却是很棒的
{
	//算法思想：假设有一组自然数，且他们的最大值不超过100，那么可以设辅助数组d[101]，辅助数组元素值都为0
	//          然后对原数组进行遍历，以arr[i]值为下标的d[arr[i]]自增1

	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	int d[101], i, j = 0;//建哈希表的思想
	for (i = 0; i < 101; ++i){ d[i] = 0; }

	for (i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i){ d[arr[i]]++; }

	printf("桶式排序：\n");
	for (i = 0; i < 101; ++i)
	{
		while (d[i]){ printf("%3d", i);/* arr[j++] = i; */d[i]--; }
	}
	printf("\n");

}


//五大内部排序方法：①插入排序②快速排序③选择排序④归并排序⑤基数排序
void Test18()
{
	Direct_insert_sort();     //①直接插入排序            O(N^2)
	Binary_insert_sort();     //②折半插入排序            O(N^2)
	TwoPath2_insert_sort();   //③2-路插入排序            O(N^2)     //这种排序方法也是在②上改进的
	TwoPath_insert_sort();    //④2-路插入排序(优)        O(N^2)     //这种排序方法是在②上改进的
	SlinkList_insert_sort();  //⑤表插入排序              O(N^2)
	Diminish_Increment_sort();//⑥希尔排序                O(NlogN)   //待深入理解

	Bubble_sort();            //①冒泡排序                O(N^2)
	Quick_sort();             //②快速排序                O(NlogN)    //没写非递归写法

	Simple_select_sort();     //①简单选择排序            O(N^2)
	Tree_select_sort();       //②树形排序或称锦标赛排序  O(NlogN)
	Heap_select_sort();       //③堆排序                  O(NlogN)

	merge_sort();             //①归并排序                O(NlogN)   //没写

	//①基数排序                           //没写

	Bucket_sort();            //①桶式排序                O(N)
}