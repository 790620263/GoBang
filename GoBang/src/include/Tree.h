#ifndef _TREE_H_
#define _TREE_H_

class Tree
{
public:
	//�����Ϊdeep������Ϊindex�Ľڵ����data
	void insert(int deep, int index, T data);
	int getNun(int deep);
	void get(int deep, int index, T& data);
private :
	struct  Node{
		int size=0;
		Node* p=nullptr;
	};

	Node root;
};


#endif
