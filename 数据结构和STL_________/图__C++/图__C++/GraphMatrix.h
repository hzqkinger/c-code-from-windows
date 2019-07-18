#pragma once

#include<vector>
#include<map>
#include<string>

// vertex
template<class V, class W, bool Direction = false>
class GraphMatrix               //false表示无向图;true表示有向图
{
public:
	GraphMatrix(V* v, size_t n)
	{
		_vertexs.reserve(n);//先开出足够的空间，免得以后扩容
		for (size_t i = 0; i < n; ++i)
		{
			_vertexs.push_back(v[i]);//给顶点数组赋值
			_vertexIndexMap[v[i]] = i;//顶点信息与下标建立对应关系  map<k,v>模型
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
	vector<V> _vertexs;//顶点集合
	map<V, int> _vertexIndexMap;//顶点集合与下标的对应关系
	vector<vector<W>> _matrix;//矩阵
};

void TestGraphMartex()
{
	string strs[] = { "cp3", "勒布朗", "威少", "哈登", "甜瓜", "杜兰特", "库里", "韦德" };
	GraphMatrix<string, int> gm(strs, sizeof(strs) / sizeof(string));
	gm.AddEdge("cp3", "勒布朗", 100);
	gm.AddEdge("cp3", "韦德", 100);
	gm.AddEdge("cp3", "甜瓜", 100);
	gm.AddEdge("cp3", "哈登", 90);
	gm.AddEdge("威少", "杜兰特", 70);
	gm.AddEdge("库里", "杜兰特", 99);
};