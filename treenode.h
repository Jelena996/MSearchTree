#ifndef _TREENODE_H_
#define _TREENODE_H_	
#include "key.h"
#include <vector>

#include<iostream>
using namespace std;



class TreeNode {
	int num;
	vector<Key>keys;
	vector<TreeNode*> nodes;



public:

	TreeNode(int m);
	TreeNode(const TreeNode& node);
	bool add(const Key& k);
	bool isFull() const;
	bool isEmpty() const;
	vector<Key> getKeys() const;
	TreeNode* getLeftSubtree(const Key&) const;
	TreeNode* getRightSubtree(const Key&) const;
	Key getMaxKey() const;
	Key getMinKey() const;
	bool contains(const Key& k) const;
	TreeNode* getSubtree(const Key& k) const;
	bool setSubtree(const Key& k, TreeNode* subnode);
	bool remove(const Key& k);
	friend ostream& operator<< (ostream& out, const TreeNode& node);
	~TreeNode();
	friend class MSearchTree;

};



#endif
