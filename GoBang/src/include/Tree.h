#ifndef _TREE_H_
#define _TREE_H_
#include "STD.h"
typedef T;
class Tree
{
public:
	//�����Ϊdeep������Ϊpath(����·�����Ľڵ����data
	void insert(int deep,int *path, T* data);
	//���Ϊdeep������Ϊpath(����·�����Ľڵ���ӽڵ���
	int getSubNum(int deep, int* path);
	void get(int deep, int* path, T& data);
private :
	struct  Node{
		vector<Node> pnode;//���ָ���ӽڵ��ָ��
		T* data;
	};

	Node root;
};


#endif
