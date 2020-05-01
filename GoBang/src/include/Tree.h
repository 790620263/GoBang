#ifndef _TREE_H_
#define _TREE_H_
#include "STD.h"
typedef T;
class Tree
{
public:
	//向深度为deep；坐标为path(访问路径）的节点插入data
	void insert(int deep,int *path, T* data);
	//深度为deep；坐标为path(访问路径）的节点的子节点数
	int getSubNum(int deep, int* path);
	void get(int deep, int* path, T& data);
private :
	struct  Node{
		vector<Node> pnode;//存放指向子节点的指针
		T* data;
	};

	Node root;
};


#endif
