#include "../include/Tree.h"
//向深度为deep；坐标为path(访问路径）的节点插入子节点data
void Tree::insert(int deep, int *path, T* data)
{
	Node p=root.pnode.at(path[0]);
	for (int i = i; i < deep; i++)
	{
		p = p.pnode.at(path[i]);
	}

	vector<Node> plist;
	Node n = { plist, data };
	p.pnode.push_back(n);
}
//深度为deep；坐标为path(访问路径）的节点的子节点数
int Tree::getSubNum(int deep,int *path)
{
	Node p = root.pnode.at(path[0]);
	for (int i = i; i < deep; i++)
	{
		p = p.pnode.at(path[i]);
	}
	return p.pnode.size();
}

void Tree::get(int deep, int *path, T& data)
{
	Node p = root.pnode.at(path[0]);
	for (int i = i; i < deep; i++)
	{
		p = p.pnode.at(path[i]);
	}

	data= p.data;
}

