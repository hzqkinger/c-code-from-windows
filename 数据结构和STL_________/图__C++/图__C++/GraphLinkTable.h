#pragma once
#include <vector>
#include <string>
#include <map>
#include <queue>
#include "UnionFind.h"


template<class W>
struct LinkTableNode//�߽��Ķ���
{
	W _w;//�ߵ�Ȩֵ
	LinkTableNode<W>* _next;//ָ����һ����
	size_t _srcindex;//Դ����
	size_t _dstindex;//Ŀ�궥��

	LinkTableNode(size_t srcindex, size_t dstindex, const W& w)
		:_srcindex(srcindex)
		, _dstindex(dstindex)
		, _w(w)
		, _next(NULL)
	{}
};

template<class V, class W, bool Direction = false>
class GraphLinkTable             //false��ʾ����ͼ;true��ʾ����ͼ
{
	typedef LinkTableNode<W> Edge;
public:
	GraphLinkTable(){}

	GraphLinkTable(V* v, size_t n)
	{
		_vertexs.reserve(n);
		for (size_t i = 0; i < n; ++i)
		{
			_vertexs.push_back(v[i]);
			_vertexIndexMap[v[i]] = i;
		}

		_linktable.resize(n, NULL);
	}

	~GraphLinkTable()
	{
		for (size_t i = 0; i < _linktable.size(); ++i)
		{
			Edge *cur = _linktable[i];
			while (cur)
			{
				Edge *next = cur->_next;
				del cur;
				cur = next;
			}
		}
	}

	void AddEdge(const V& src, const V& dst, const W& w)
	{
		size_t srcindex = GetVertexIndex(src);
		size_t dstindex = GetVertexIndex(dst);

		_AddEdge(srcindex, dstindex, w);
		if (Direction == false)
			_AddEdge(dstindex, srcindex, w);
	}

	void GFS(const V& src)//������ȱ���
	{
		size_t srcindex = GetVertexIndex(src);
		queue<size_t> q;
		q.push(srcindex);
		vector<bool> visit;
		visit.resize(_vertexs.size(), false);

		while (!q.empty())
		{
			size_t front = q.front();
			q.pop();
			if (visit[front] == false)
			{
				cout << front << _vertexs[front] << endl;
				visit[front] = true;
				Edge* edge = _linktable[front];
				while (edge)
				{
					if (visit[edge->_dstindex] == false)
					{
						q.push(edge->_dstindex);
					}

					edge = edge->_next;
				}
			}
		}
	}

	void DFS(const V& src)//������ȱ���
	{
		size_t srcindex = GetVertexIndex(src);
		vector<bool> visit;
		visit.resize(_vertexs.size(), false);

		_DFS(srcindex, visit);
	}

	bool Kruskal(GraphLinkTable<V, W>& mintree)
	{
		mintree._vertexs = _vertexs;
		mintree._vertexIndexMap = _vertexIndexMap;
		mintree._linktable.resize(_vertexs.size(), NULL);

		struct EdgeComapre
		{
			bool operator()(const Edge* l, const Edge* r) const
			{
				return l->_w > r->_w;
			}
		};

		UnionFindSet ufs(_vertexs.size());
		priority_queue<Edge*, vector<Edge*>, EdgeComapre> pq;
		for (size_t i = 0; i < _linktable.size(); ++i)
		{
			Edge* cur = _linktable[i];
			while (cur)
			{
				if (cur->_srcindex < cur->_dstindex)
					pq.push(cur);

				cur = cur->_next;
			}
		}


		size_t count = 0;
		while (!pq.empty())
		{
			Edge* minedge = pq.top();
			pq.pop();

			if (ufs.IsUnionSet(minedge->_srcindex, minedge->_dstindex) == false)
			{
				mintree._AddEdge(minedge->_srcindex, minedge->_dstindex, minedge->_w);
				mintree._AddEdge(minedge->_dstindex, minedge->_srcindex, minedge->_w);
				ufs.Union(minedge->_srcindex, minedge->_dstindex);
				++count;
				if (count == _vertexs.size() - 1)
				{
					return true;
				}
			}
		}

		return false;
	}

protected:
	vector<V> _vertexs;//����ļ���
	map<V, size_t> _vertexIndexMap;//���㼯�����±�Ķ�Ӧ��ϵ
	vector<Edge*> _linktable;//�ߵļ���

	size_t GetVertexIndex(const V& v)
	{
		//assert(_vertexIndexMap.count(v) == 1);
		if (_vertexIndexMap.count(v) == 0)
		{
			throw exception("invalid vertex");
		}

		return _vertexIndexMap[v];
	}
	void _AddEdge(size_t srcindex, size_t dstindex, const W& w)
	{
		Edge* edge = new Edge(srcindex, dstindex, w);
		edge->_next = _linktable[srcindex];
		_linktable[srcindex] = edge;
	}
	void _DFS(size_t srcindex, vector<bool>& visit)
	{
		cout << srcindex << _vertexs[srcindex] << endl;
		visit[srcindex] = true;

		Edge* edge = _linktable[srcindex];
		while (edge)
		{
			if (visit[edge->_dstindex] == false)
			{
				_DFS(edge->_dstindex, visit);
			}

			edge = edge->_next;
		}
		//cout<<"����"<<endl;
	}
};

void TestGraphLinkTable()
{
	string strs[] = { "cp3", "�ղ���", "����", "����", "���", "������", "����", "Τ��" };
	GraphLinkTable<string, int> glt(strs, sizeof(strs) / sizeof(string));
	glt.AddEdge("cp3", "�ղ���", 100);
	glt.AddEdge("cp3", "Τ��", 100);
	glt.AddEdge("cp3", "���", 100);
	glt.AddEdge("cp3", "����", 90);
	glt.AddEdge("����", "������", 70);
	glt.AddEdge("����", "������", 99);
	glt.AddEdge("����", "������", 59);

	glt.GFS("�ղ���");
	cout << "==============================" << endl;
	glt.DFS("�ղ���");

	GraphLinkTable<string, int> mintree;
	cout << glt.Kruskal(mintree) << endl;
};