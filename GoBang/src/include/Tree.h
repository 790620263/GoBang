#ifndef _TREE_H_
#define _TREE_H_
#include "STD.h"

template <class DataType>
class Tree
{
public:
	Tree<DataType>() {};
	//向深度为deep；坐标为path(访问路径）的节点插入data
	void insert(int deep,int *path, DataType data);
	//深度为deep；坐标为path(访问路径）的节点的子节点数
	int getSubNum(int deep, int* path);
	DataType get(int deep, int* path);
private :
	struct  Node{
		vector<Node> pnode;//存放子节点
		DataType data;
	};

	Node root;
};

//向深度为deep；坐标为path(访问路径）的节点插入子节点data
template<class DataType>
void Tree<DataType>::insert(int deep, int* path, DataType data)
{
	if (deep == 0) {
		vector<Node> plist;
		Node n = { plist, data };
		root.pnode.push_back(n);
		return;
	}
	Node p=root.pnode.at(path[0]);
	for (int i = 1; i < deep; i++)
	{
		p = p.pnode.at(path[i]);
	}

	vector<Node> plist;
	Node n = { plist, data };
	p.pnode.push_back(n);
}
//深度为deep；坐标为path(访问路径）的节点的子节点数
template<class DataType>
int Tree<DataType>::getSubNum(int deep, int* path)
{
	if (deep == 0) {
		return root.pnode.size();
	}
	Node p = root.pnode.at(path[0]);
	for (int i = 1; i < deep; i++)
	{
		p = p.pnode.at(path[i]);
	}
	return p.pnode.size();
}
template<class DataType>
DataType Tree<DataType>::get(int deep, int* path)
{
	if (deep == 0) {
		return root.data;
	}
	Node p = root.pnode.at(path[0]);
	for (int i = 1; i < deep; i++)
	{
		p = p.pnode.at(path[i]);
	}

	return p.data;
}

#endif
