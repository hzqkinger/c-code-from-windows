#pragma once

#include<vector>
#include<map>
#include<string>

// vertex
template<class V, class W, bool Direction = false>
class GraphMatrix               //false��ʾ����ͼ;true��ʾ����ͼ
{
public:
	GraphMatrix(V* v, size_t n)
	{
		_vertexs.reserve(n);//�ȿ����㹻�Ŀռ䣬����Ժ�����
		for (size_t i = 0; i < n; ++i)
		{
			_vertexs.push_back(v[i]);//���������鸳ֵ
			_vertexIndexMap[v[i]] = i;//������Ϣ���±꽨����Ӧ��ϵ  map<k,v>ģ��
		}

		_matrix.resize(n);
		for (size_t i = 0; i < n; ++i)
			_matrix[i].resize(n);
	}

	int GetVertexIndex(const V& src)
	{
		if (_vertexIndexMap.count(src) != 1)
		{
			throw exception("invalid vertex");
		}

		return _vertexIndexMap[src];
	}

	void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcIndex = GetVertexIndex(src);
		size_t dstIndex = GetVertexIndex(dst);

		_matrix[srcIndex][dstIndex] = w;
		if (Direction == false)
			_matrix[dstIndex][srcIndex] = w;
	}

protected:
	vector<V> _vertexs;//���㼯��
	map<V, int> _vertexIndexMap;//���㼯�����±�Ķ�Ӧ��ϵ
	vector<vector<W>> _matrix;//����
};

void TestGraphMartex()
{
	string strs[] = { "cp3", "�ղ���", "����", "����", "���", "������", "����", "Τ��" };
	GraphMatrix<string, int> gm(strs, sizeof(strs) / sizeof(string));
	gm.AddEdge("cp3", "�ղ���", 100);
	gm.AddEdge("cp3", "Τ��", 100);
	gm.AddEdge("cp3", "���", 100);
	gm.AddEdge("cp3", "����", 90);
	gm.AddEdge("����", "������", 70);
	gm.AddEdge("����", "������", 99);
};