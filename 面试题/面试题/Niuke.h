#pragma once

//题目描述
//给定一个十进制的正整数number，选择从里面去掉一部分数字，希望保留下来的数字组成的正整数最大。
//输入描述 :
//输入为两行内容，第一行是正整数number，1 ≤ length(number) ≤ 1000。
//第二行是希望去掉的数字数量cnt 1 ≤ cnt < length(number)。
//输出描述 :
//输出保留下来的结果。
//示例1
//输入
//325
//1
//输出
//35
#include<ctype.h>
void Nowcoder1()
{
	int k, count = 0, i = 0;
	//char arr[1000] = {0};
	//gets(arr);
	char arr[1000] = "397658615402052396230088067196473777872459360657124258499149466898622928583529132300290847686796020064662338832612223567089373853010328235871444492443790413610032775618067536022739526046090277891038055398958940729875103452786233655298554901448492674994254293130383168860358510485200856420300151692972284193672491956473334300091295382606863678681255177444058718810076728017428230295645730302933525409093876425092367265847945850759881167381645096928892929011382774830762135887717573657100695273988793977954836686043138333246841287895384499690265284101993706168641765529602696722761200098287558429137704837630699921122122870778846007015871340971865972810343111916643481737333851280976178548830116550339529354180703559116202006242343493262658624318530767901526211377722000990328133640382511858338549213920458813842848847186738244578799341008645211159239423870191927523130099136693542255531352233169051129288569817147409412852134495701567619994356971792758048583704345227638002493529155814022883621424322";//8630830642
	count = strlen(arr);
	//num = 3976586154020523962300880671964737778724593606571242584991494668986229285835291323002908476867960200646623388326122235670893738530103282358714444924437904136100327756180675360227395260460902778910380553989589407298751034527862336552985549014484926749942542931303831688603585104852008564203001516929722841936724919564733343000912953826068636786812551774440587188100767280174282302956457303029335254090938764250923672658479458507598811673816450969288929290113827748307621358877175736571006952739887939779548366860431383332468412878953844996902652841019937061686417655296026967227612000982875584291377048376306999211221228707788460070158713409718659728103431119166434817373338512809761785488301165503395293541807035591162020062423434932626586243185307679015262113777220009903281336403825118583385492139204588138428488471867382445787993410086452111592394238701919275231300991366935422555313522331690511292885698171474094128521344957015676199943569717927580485837043452276380024935291558140228836214243228630830642;
	scanf("%d", &k);
	while (k--)
	{
		int min = 0;
		for (i = 1; i<count; ++i)
		{
			if (arr[min]>arr[i])
				min = i;
		}
		arr[min] = 'a';
	}
	for (i = 0; i < count; ++i)
	{
		if (isdigit(arr[i]))
			printf("%c", arr[i]);
	}
	printf("\n%d\n", count);

}

//现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
//输入描述 :
//输入的第一行表示节点的个数n（1 ≤ n ≤ 1000，节点的编号为0到n - 1）组成，
//下面是n - 1行，每行有两个整数，第一个数表示父节点的编号，第二个数表示子节点的编号
//输出描述 :
//输出树的高度，为一个整数
//示例1
//输入
//5
//0 1
//0 2
//1 3
//1 4
//输出
//3
#include<queue>//当遇到一层一层的问题时，可以考虑用两个队列来解决问题
void Nowcoder2()//Oj不通过，调用堆栈过多
{         //以后做OJ，尽量用vector来代替stack或者queue，尤其是有点跟下标有关系的
	int n, high = 1; cin >> n;
	if (n <= 0){ cout << --high << endl; return; }
	queue<int> q1, q2; q1.push(0);
	int front = q1.front();
	while (--n)
	{
		int parent, child;
		cin >> parent >> child;

		while (front != parent)
		{
			q1.pop();
			if (q1.empty()){ swap(q1, q2); high++; }//交换两个队列,树的高度加1
			front = q1.front();
		}
		if (front == parent){ q2.push(child); }
	}
	if (!q2.empty()){ high++; }

	cout << high << endl;
}
#include <vector>
void Nowcoder21()//通过代码，看别人的（感觉是填写不确定的递增数列）
{
	int n, H = 1;
	int i = 0;
	int f, c, h;
	vector<int> nodes(1000, 0);    //有效节点的高度
	nodes[0] = 1; // 题目说了至少有一个节点，高度只是是1
	vector<int> childnum(1000, 0); //记录节点的孩子数量
	cin >> n;
	while (--n){
		cin >> f >> c;
		//父节点不存在 或者 父节点已有两个子节点 就跳过
		if (nodes[f] == 0 || childnum[f] == 2) //该语句是为了防止错误输入
			continue;
		childnum[f] += 1;
		h = nodes[f] + 1;
		nodes[c] = h;
		if (h > H) H = h;
	}
	cout << H;
}

//题目描述
//一只袋鼠要从河这边跳到河对岸，河很宽，但是河中间打了很多桩子，每隔一米就有一个，每个桩子上都有一个弹簧，
//袋鼠跳到弹簧上就可以跳的更远。每个弹簧力量不同，用一个数字代表它的力量，如果弹簧力量为5，就代表袋鼠下一
//跳最多能够跳5米，如果为0，就会陷进去无法继续跳跃。河流一共N米宽，袋鼠初始位置就在第一个弹簧上面，要跳到
//最后一个弹簧之后就算过河了，给定每个弹簧的力量，求袋鼠最少需要多少跳能够到达对岸。如果无法到达输出 - 1
//输入描述:
//输入分两行，第一行是数组长度N(1 ≤ N ≤ 10000)，第二行是每一项的值，用空格分隔。
//输出描述 :
//输出最少的跳数，无法到达输出 - 1
//示例1
//输入
//5
//2 0 1 1 1
//输出
//4
#include<vector>//还没OJ
void Kangaroo_Through_River()//感觉是轧马路式的递增数列
{
	int n, power;
	cin >> n;
	vector<int> v2(1006, 0);//记录从开始到每个桩子的最小步数
	v2[0] = 0;
	for (size_t i = 0; i < n; ++i)
	{
		if (i != 0 && v2[i] == 0)//假如v2[i]==0,那么说明从前面哪一步都走不到这以及其后面的桩子
		{
			cout << -1 << endl;
			return;
		}
		cin >> power;
		for (size_t j = i + 1; j <= i + power; ++j)
		{
			if (v2[j] == 0)//假如这里不是0，那么说明从前面的桩子就可以到达这里，不需要更新其值
				v2[j] = v2[i] + 1;
		}
	}
	if (v2[n])
		cout << v2[n] << endl;
	else
		cout << -1 << endl;
}


//题目描述
//请设计一个算法能够完成两个用字符串存储的整数进行相加操作，对非法的输入则返回error
//输入描述 :
//输入为一行，包含两个字符串，字符串的长度在[1, 100]。
//输出描述 :
//输出为一行。合法情况输出相加结果，非法情况输出error
//示例1
//输入
//123 123
//abd 123
//输出
//246
//Error
#include<string>
#include<ctype.h>
void Add_digit()
{
	string str1; string str2;
	cin >> str1 >> str2;
	if (str1.size()<1 || str1.size() > 100 || str2.size()<1 || str2.size() > 100)//检查字符串长度合法性
	{
		cout << "Error" << endl; return;
	}
	for (size_t i = 0; i < str1.size(); ++i)//检查字符串输入字符的合法性
	{
		if (!isdigit(str1[i])){ cout << "Error" << endl; return; }
	}
	for (size_t i = 0; i < str2.size(); ++i)
	{
		if (!isdigit(str2[i])){ cout << "Error" << endl; return; }
	}

	if (str1.size() < str2.size()){ swap(str1, str2); }//保证str1是最长的字符串
	int i = str1.size(), j = str2.size();
	int inter = 0;
	while (i-- && j--)
	{
		if (str1[i] + str2[j] - 2 * '0'>9)
		{
			str1[i] += str2[j] - 1 - '9' + inter;
			inter = 1;
		}
		else
		{
			str1[i] += str2[j] - '0' + inter;
			inter = 0;
		}
	}
	if (inter == 1)
	{
		if (i >= 0)
		{

			while (i >= 0 && str1[i] + inter > '9'){ str1[i--] = '0'; }
			if (i < 0){ str1.insert(0, 1, '1'); }
		}
		else
		{
			str1.insert(0, 1, '1');
		}
	}
	cout << str1 << endl;
}

//题目描述：一个无限长的数字序列 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5...(数字k在序列中正好出现k次)，
//         那么问序列中第n项是多少？
void Jdnum()
{
	size_t n, k; scanf("%d", &n);
	k = sqrt(2 * n + 0.25) + 0.5;
	if (k*(k - 1) >= 2 * n){ --k; }
	printf("%2d", k);
}

//打印折痕问题 二叉树中序遍历思想
void PrintTrack5(size_t n, bool b)
{
	if (!n)return;
	PrintTrack5(n - 1, b);
	if (b == false){ printf("下 "); b = true; }
	else{ printf("上 "); b = false; }
	PrintTrack5(n - 1, b);
}
void Print_Track()
{
	size_t n; cin >> n;
	bool b = false;
	PrintTrack5(n, b);
}

//一个整型数组任意划分为两个连续的子序列，求|left_max -right_max|的最大值
#include<vector>
void GetMax1()//辅助数组方法
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int num;
	for (size_t i = 0; i < n; ++i){ cin >> num; v[i] = num; }
	vector<int> v1(n), v2(n); v1[0] = v[0]; v2[n - 1] = v[n - 1];
	for (size_t i = 1; i < n; ++i){
		if (v[i] >= v1[i - 1])v1[i] = v[i];
		else v1[i] = v1[i - 1];
	}
	for (int i = n - 2; i >= 0; --i){
		if (v[i] >= v2[i + 1])v2[i] = v[i];
		else v2[i] = v2[i + 1];
	}
	int max = abs(v1[0] - v2[0]);
	for (size_t i = 1; i < n; ++i){
		if (max < (num = abs(v1[i] - v2[i])))max = num;
	}
	cout << max;
}
void GetMax2()//两头指针方法
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int num;
	for (size_t i = 0; i < n; ++i){ cin >> num; v[i] = num; }
	int max = v[0];
	for (size_t i = 1; i < n; ++i){ if (max < v[i])max = v[i]; }
	max = v[0] < v[n - 1] ? max - v[0] : max - v[n - 1];
	cout << max;

}

//输入一个num，将数组中大于num的数放到数组的前部分，小于的放在数组的后面部分
#include<vector>
void ArrangArr()//两头指针方法
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int val, num;
	cin >> num;//输入num的大小
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }
	size_t i = 0, j = n - 1;
	while (i < j)
	{
		if (v[i] <= num)++i;
		else { swap(v[i], v[j]); --j; }
	}
	for (size_t i = 0; i < n; ++i){ cout << v[i] << " "; }
}

//寻找一个局部最小值     0-1二分思想 eg. 2 1 6 4 5 2 7 8 9其中1 4 2都是局部最小值，找到一个就行
void PartMin()
{
	size_t n; cin >> n;//输入数据的个数
	vector<int> v(n); int val;
	for (size_t i = 0; i < n; ++i){ cin >> val; v[i] = val; }
	size_t left = 0, right = n - 1;
	while (left < right)
	{
		if (v[left]<v[left + 1]){ printf("arr[%d] = %d", left, v[left]); return; }
		if (v[right]<v[right - 1]){ printf("arr[%d] = %d", right, v[right]); return; }

		size_t mid = left + (right - left) / 2;
		if (v[mid - 1]>v[mid] && v[mid] < v[mid + 1]){ printf("arr[%d] = %d", mid, v[mid]); return; }
		else if (v[mid - 1]>v[mid]){ left = mid + 1; }
		else { right = mid - 1; }
	}
	printf("无局部最小值");
}



//题目描述：有一个存放非负整型的数组，请找出有多少个x,符合y=kx(k>1)，其中y也是数组中的数
//          输入; 5 （数组中存在多少个数）
//                1 2 3 4 5 （数组中的数据）
//          输出：2 （存在几个符合条件的数）





void test_Niuke()
{
	//Nowcoder1();
	//Nowcoder2();
	//Nowcoder21();//这代码很6
	//Kangaroo_Through_River();
	//Add_digit();
	//Jdnum();
	//Print_Track();
	//GetMax1();
	//GetMax2();
	//ArrangArr();
	//PartMin();
}