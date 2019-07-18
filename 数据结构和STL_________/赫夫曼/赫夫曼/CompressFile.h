#pragma once 

#include<iostream>
#include<assert.h>
#include<algorithm>
#include<string>
#include"HuffmanTree.h" 

struct CharInfo
{
	unsigned char _ch;  // 字符 
	long long _count; // 文件中出现的次数 
	string _code;   // huffman code
	CharInfo(unsigned char ch = 0)
		:_ch(ch)
		, _count(0)
	{}
	bool operator!=(const CharInfo& info)
	{
		return _count != info._count;
	}
	bool operator<(const CharInfo& info)
	{
		return _count<info._count;
	}

	CharInfo operator+(const CharInfo& info)
	{
		CharInfo tmp;
		tmp._count = _count + info._count;
		return tmp;
	}

};

class FileCompress
{
	typedef HuffmanTreeNode<CharInfo> Node;
	struct ConfigInfo
	{
		unsigned char _ch;
		long long _count;
	};
public:
	//无构造函数的话就是随机值
	FileCompress()
	{
		for (int i = 0; i < 256; ++i)
		{
			_infos[i]._ch = i;
			_infos[i]._count = 0;
		}
	}

	void GetHuffmantree(Node* root, string code)
	{
		if (root == NULL)
		{
			return;
		}

		if (root->_left == NULL && root->_right == NULL)
		{
			_infos[(unsigned char)root->_w._ch]._code = code;
			return;
		}
		GetHuffmantree(root->_left, code + '0');
		GetHuffmantree(root->_right, code + '1');
	}

	void GetHuffmanCode(Node* root)
	{
		if (root == NULL)
		{
			return;
		}
		if (root->_left == NULL&&root->_right == NULL)
		{
			string &code = _infos[(unsigned char)root->_w._ch]._code;
			Node* cur = root;
			Node* parent = cur->_parent;
			while (parent)
			{
				if (cur == parent->_left)
				{
					code.push_back('0');
				}
				else if (cur == parent->_right)
				{
					code.push_back('1');
				}
				else
				{
					break;
				}
				cur = parent;
				parent = cur->_parent;
			}

			reverse(code.begin(), code.end());
			return;
		}
		GetHuffmanCode(root->_left);
		GetHuffmanCode(root->_right);

	}
	// Input.txt->Input.txt.huffman 压缩
	void Compress(const char* file)
	{
		assert(file);

		//1,统计字符出现的次数
		FILE* fout = fopen(file, "rb");
		assert(fout);
		char ch = fgetc(fout);
		while (!feof(fout))
		{
			_infos[(unsigned char)ch]._count++; //这个字符的哪个位置的个数加一
			ch = fgetc(fout);
		}
		//2,构建哈夫曼树
		CharInfo invalid;
		invalid._count = 0;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);
		Node* root = tree.GetRoot();
		//3，生成哈夫曼编码 
		string code;
		GetHuffmantree(root, code);
		//4，压缩文件
		// Input.txt->Input.txt.huffman 
		string compressfile = file;
		compressfile += ".huffman";
		FILE* fin = fopen(compressfile.c_str(), "wb");

		for (size_t i = 0; i<256; i++)
		{
			ConfigInfo info;
			if (_infos[i]._count)
			{
				info._ch = _infos[i]._ch;
				info._count = _infos[i]._count;
				fwrite(&info, sizeof(ConfigInfo), 1, fin);
			}
		}

		ConfigInfo info;
		info._count = 0;
		fwrite(&info, sizeof(ConfigInfo), 1, fin);
		fseek(fout, 0, SEEK_SET);
		ch = fgetc(fout);
		char value = 0;
		char pos = 0;
		while (!feof(fout))
		{
			string& code = _infos[(unsigned char)ch]._code;
			for (size_t i = 0; i<code.size(); ++i)
			{
				//将编码变成二进制
				if (code[i] == '1')
				{
					value |= (1 << pos);
				}
				else if (code[i] == '0')
				{
					value &= (~(1 << pos));
				}
				else
				{
					assert(false);
				}
				++pos;
				if (pos == 8)
				{
					fputc(value, fin);
					value = 0;
					pos = 0;
				}
			}
			ch = fgetc(fout);
		}
		if (pos)//补位
		{
			//value <<= (8-pos);
			fputc(value, fin);
		}
		fclose(fout);
		fclose(fin);
	}

	//Input.txt.huffman -> Input.txt.unhuffman 
	void Uncompress(const char* file)
	{
		assert(file);
		string uncompressfile = file;
		size_t pos = uncompressfile.rfind('.');
		assert(pos != string::npos);
		uncompressfile.erase(pos, uncompressfile.size() - pos);
		uncompressfile += ".unhuffman";
		FILE* fin = fopen(uncompressfile.c_str(), "wb");
		assert(fin);
		FILE* fout = fopen(file, "rb");
		assert(fout);

		//读配置信息
		while (!feof(fout))
		{
			ConfigInfo info;
			info._count = 0;
			fread(&info, sizeof(ConfigInfo), 1, fout);

			if (info._count)
			{
				_infos[info._ch]._count = info._count;
			}
			else
			{
				break;
			}
		}
		CharInfo invalid;
		invalid._count = 0;
		HuffmanTree<CharInfo> tree(_infos, 256, invalid);
		Node* root = tree.GetRoot();
		Node* cur = root;
		long long charcount = 0;
		charcount = tree.GetRoot()->_w._count;
		pos = 0;
		char value = fgetc(fout);
		while (!feof(fout))
		{
			if (value & (1 << pos))
				cur = cur->_right;
			else
				cur = cur->_left;
			if (cur->_left == NULL && cur->_right == NULL)
			{
				fputc(cur->_w._ch, fin);
				cur = root;

				if (--charcount == 0)
				{
					break;
				}
			}
			++pos;
			if (pos == 8)
			{
				value = fgetc(fout);
				pos = 0;
			}
		}


		fclose(fout);
		fclose(fin);
	}
protected:
	CharInfo _infos[256];
};
