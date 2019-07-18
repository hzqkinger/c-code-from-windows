#pragma once

#include"huffman.h"

#include<string>
class FileCompress{
public:
	struct _charinfos{//内置类型
		char _ch;
		size_t _count;
		std::string _code;
		bool operator!=(_charinfos const& charin)//如果结构体中_count不相等，那么结构体不相等
		{
			return _count != charin._count;
		}
		bool operator>(_charinfos const& charin)
		{
			return _count > charin._count;
		}
		_charinfos operator+(_charinfos const& charin)
		{
			_charinfos tmp;
			tmp._count = _count + charin._count;
			return tmp;
		}
	};
	typedef Nod<_charinfos> Node;
	struct _tmpinfos{
		char _ch;
		size_t _count;
	};

	FileCompress()//默认构造函数
	{
		for (size_t i = 0; i < 256; ++i){
			charinf[i]._ch = i;
			charinf[i]._count = 0;
		}
	}

	void Compress(const char* file)//huffman.txt
	{
		//1.打开一个文件，对其字符进行统计出现的频率
		FILE *fsrc = fopen(file, "rb");
		char ch = fgetc(fsrc);
		while (!feof(fsrc)){
			++charinf[(unsigned char)ch]._count;
			ch = fgetc(fsrc);
		}

		//2.构建一棵赫夫曼树并得到huaffman code
		_charinfos invalue; invalue._count = 0;
		Huffman<_charinfos> h(charinf, 256, invalue);//数组向指针的转化
		auto root = h.GetRoot(),cur = root; string str;
		Traverse(cur, str);//遍历赫夫曼树，得到huffman code

		//3.压缩文件,把1.中统计的字符放到压缩文件中去
		string filedst(file);
		filedst += ".huffman";
		FILE *fdst = fopen(filedst.c_str(), "wb");//打开目标文件
		_tmpinfos tmpinf;
		for (size_t i = 0; i < 256; ++i){//为了尽可能方便且少的将信息压入目标文件
			if (charinf[i]._count){
				tmpinf._ch = i;tmpinf._count = charinf[i]._count;
				fwrite(&tmpinf, sizeof(_tmpinfos), 1, fdst);//将有用的信息写入目标文件
			}
		}tmpinf._count = 0;
		fwrite(&tmpinf, sizeof(_tmpinfos), 1, fdst);//多写入一个信息，用作信息结束标志

		rewind(fsrc);//将stream指向的流的文件定位符设置在文件的开始位置，等价于fseek(fsrc,0,SEEK_SET)
		char ch1 = fgetc(fsrc), ch2 = 0; size_t pos = 0;
		while (!feof(fsrc)){
				string code = charinf[(unsigned char)ch1]._code;
				for (size_t j = 0; j < code.size(); ++j){
					ch2 |= code[j] - '0' << pos++;
					if (pos == 8){
						//int test55 = ch2; cout << test55 << " ";//验证信息，查看到底压入了什么数据
						fputc(ch2, fdst);//向目标文件中写入一个每个位都被重置了的字符
						ch2 = 0; pos = 0;
					}
				}
				ch1 = fgetc(fsrc);
		}
		//还要考虑当原文件读到最后一字符个时，ch2的8个位没有被全部重置的情况
		if (pos){ /*int test55 = ch2; cout << test55 << " ";*/
			fputc(ch2, fdst);
		}
		fclose(fsrc);
		fclose(fdst);
	}

	void Uncompress(const char* file)//huffmanhzq.txt
	{
		//4.根据压缩文件重构赫夫曼树
		FILE *fout = fopen(file, "rb");
		_tmpinfos tmpinf;
		fread(&tmpinf, sizeof(_tmpinfos), 1, fout);
		while (tmpinf._count){//根据压缩文件，对其字符进行统计出现的频率
			charinf[(unsigned char)tmpinf._ch]._ch = tmpinf._ch;
			charinf[(unsigned char)tmpinf._ch]._count = tmpinf._count;
			fread(&tmpinf, sizeof(_tmpinfos), 1, fout);
		}
		_charinfos invalue; invalue._count = 0;
		Huffman<_charinfos> h(charinf, 256, invalue);//重构赫夫曼树
		//5.解压缩文件（root->_w._count记录了原文件中所有字符出现的次数）
		string filedst(file);
		filedst.erase(filedst.rfind('.')); filedst += ".unhuffman";
		FILE *fin = fopen(filedst.c_str(), "wb");//以写的方式打开文件
		auto root = h.GetRoot(), cur = root;
		char ch = fgetc(fout); size_t n = root->_w._count;
		while (!feof(fout)){
			//int test55 = ch; cout << test55 << " ";//验证信息，查看到底拿到了什么数据
			for (size_t i = 0; i < 8; ++i){
				if (ch & 1 << i){ cur = cur->_right; }
				else{ cur = cur->_left; }

				if (!cur->_left && !cur->_right){
					fputc(cur->_w._ch, fin);
					--n;//因为n记录了原文件所有字符出现的次数，所以当n==0时表示已经翻译完
					cur = root;
				}
				if (!n)break;
			}
			ch = fgetc(fout);
		}
		fclose(fout);
		fclose(fin);
	}
private:
	_charinfos charinf[256];
	void Traverse(Node* const& root, string str)//遍历赫夫曼树，得到huffman code
	{
		if (!root->_left && !root->_right){//走到叶子结点将huffman code信息写入并返回
			charinf[(unsigned char)root->_w._ch]._code = str;
			return;
		}
		Traverse(root->_left, str + '0');
		Traverse(root->_right, str + '1');
	}
};

void test_compressfile()
{
	FileCompress fc;
	fc.Compress("1.txt");      //从huffman.txt到huffmanhzq.txt
	//fc.Uncompress("mcnxse.txt.huffman"); //从huffmanhzq.txt到huffmanhzqhzq.txt

	//FileCompress fc;
	//fc.Compress("hehe.jpg");
	//fc.Uncompress("hehe.jpg.huffman");
}