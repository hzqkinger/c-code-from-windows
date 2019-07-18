#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include"CompressFile.h"
using namespace std;

void testHuffmanTree()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int size = sizeof(a) / sizeof(a[0]);
	HuffmanTree<int> ht(a, size, 0);
}

void testFileCompress()
{
	FileCompress fc;
	fc.Compress("hehe.jpg");
	fc.Uncompress("hehe.jpg.huffman");

}

int main()
{
	//testHuffmanTree();
	testFileCompress();
	return 0;
}