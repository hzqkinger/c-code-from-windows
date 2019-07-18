#include<iostream>
using namespace std;

int main()
{
	int sum = 0;
	int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i)
	{
		static int cnt = arr[i];

		sum = cnt + sum;
	}
	cout << sum << endl;

	getchar();
	return 0;
}