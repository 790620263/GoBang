#include "../include/Tree.h"
//�����Ϊdeep������Ϊpath(����·�����Ľڵ�����ӽڵ�data
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
//���Ϊdeep������Ϊpath(����·�����Ľڵ���ӽڵ���
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

