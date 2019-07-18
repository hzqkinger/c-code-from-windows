#pragma once

#include"huffman.h"

#include<string>
class FileCompress{
public:
	struct _charinfos{//��������
		char _ch;
		size_t _count;
		std::string _code;
		bool operator!=(_charinfos const& charin)//����ṹ����_count����ȣ���ô�ṹ�岻���
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

	FileCompress()//Ĭ�Ϲ��캯��
	{
		for (size_t i = 0; i < 256; ++i){
			charinf[i]._ch = i;
			charinf[i]._count = 0;
		}
	}

	void Compress(const char* file)//huffman.txt
	{
		//1.��һ���ļ��������ַ�����ͳ�Ƴ��ֵ�Ƶ��
		FILE *fsrc = fopen(file, "rb");
		char ch = fgetc(fsrc);
		while (!feof(fsrc)){
			++charinf[(unsigned char)ch]._count;
			ch = fgetc(fsrc);
		}

		//2.����һ�úշ��������õ�huaffman code
		_charinfos invalue; invalue._count = 0;
		Huffman<_charinfos> h(charinf, 256, invalue);//������ָ���ת��
		auto root = h.GetRoot(),cur = root; string str;
		Traverse(cur, str);//�����շ��������õ�huffman code

		//3.ѹ���ļ�,��1.��ͳ�Ƶ��ַ��ŵ�ѹ���ļ���ȥ
		string filedst(file);
		filedst += ".huffman";
		FILE *fdst = fopen(filedst.c_str(), "wb");//��Ŀ���ļ�
		_tmpinfos tmpinf;
		for (size_t i = 0; i < 256; ++i){//Ϊ�˾����ܷ������ٵĽ���Ϣѹ��Ŀ���ļ�
			if (charinf[i]._count){
				tmpinf._ch = i;tmpinf._count = charinf[i]._count;
				fwrite(&tmpinf, sizeof(_tmpinfos), 1, fdst);//�����õ���Ϣд��Ŀ���ļ�
			}
		}tmpinf._count = 0;
		fwrite(&tmpinf, sizeof(_tmpinfos), 1, fdst);//��д��һ����Ϣ��������Ϣ������־

		rewind(fsrc);//��streamָ��������ļ���λ���������ļ��Ŀ�ʼλ�ã��ȼ���fseek(fsrc,0,SEEK_SET)
		char ch1 = fgetc(fsrc), ch2 = 0; size_t pos = 0;
		while (!feof(fsrc)){
				string code = charinf[(unsigned char)ch1]._code;
				for (size_t j = 0; j < code.size(); ++j){
					ch2 |= code[j] - '0' << pos++;
					if (pos == 8){
						//int test55 = ch2; cout << test55 << " ";//��֤��Ϣ���鿴����ѹ����ʲô����
						fputc(ch2, fdst);//��Ŀ���ļ���д��һ��ÿ��λ���������˵��ַ�
						ch2 = 0; pos = 0;
					}
				}
				ch1 = fgetc(fsrc);
		}
		//��Ҫ���ǵ�ԭ�ļ��������һ�ַ���ʱ��ch2��8��λû�б�ȫ�����õ����
		if (pos){ /*int test55 = ch2; cout << test55 << " ";*/
			fputc(ch2, fdst);
		}
		fclose(fsrc);
		fclose(fdst);
	}

	void Uncompress(const char* file)//huffmanhzq.txt
	{
		//4.����ѹ���ļ��ع��շ�����
		FILE *fout = fopen(file, "rb");
		_tmpinfos tmpinf;
		fread(&tmpinf, sizeof(_tmpinfos), 1, fout);
		while (tmpinf._count){//����ѹ���ļ��������ַ�����ͳ�Ƴ��ֵ�Ƶ��
			charinf[(unsigned char)tmpinf._ch]._ch = tmpinf._ch;
			charinf[(unsigned char)tmpinf._ch]._count = tmpinf._count;
			fread(&tmpinf, sizeof(_tmpinfos), 1, fout);
		}
		_charinfos invalue; invalue._count = 0;
		Huffman<_charinfos> h(charinf, 256, invalue);//�ع��շ�����
		//5.��ѹ���ļ���root->_w._count��¼��ԭ�ļ��������ַ����ֵĴ�����
		string filedst(file);
		filedst.erase(filedst.rfind('.')); filedst += ".unhuffman";
		FILE *fin = fopen(filedst.c_str(), "wb");//��д�ķ�ʽ���ļ�
		auto root = h.GetRoot(), cur = root;
		char ch = fgetc(fout); size_t n = root->_w._count;
		while (!feof(fout)){
			//int test55 = ch; cout << test55 << " ";//��֤��Ϣ���鿴�����õ���ʲô����
			for (size_t i = 0; i < 8; ++i){
				if (ch & 1 << i){ cur = cur->_right; }
				else{ cur = cur->_left; }

				if (!cur->_left && !cur->_right){
					fputc(cur->_w._ch, fin);
					--n;//��Ϊn��¼��ԭ�ļ������ַ����ֵĴ��������Ե�n==0ʱ��ʾ�Ѿ�������
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
	void Traverse(Node* const& root, string str)//�����շ��������õ�huffman code
	{
		if (!root->_left && !root->_right){//�ߵ�Ҷ�ӽ�㽫huffman code��Ϣд�벢����
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
	fc.Compress("1.txt");      //��huffman.txt��huffmanhzq.txt
	//fc.Uncompress("mcnxse.txt.huffman"); //��huffmanhzq.txt��huffmanhzqhzq.txt

	//FileCompress fc;
	//fc.Compress("hehe.jpg");
	//fc.Uncompress("hehe.jpg.huffman");
}