#ifndef _MSEARCH_H_
#define _MSEARCH_H_	
#include "key.h"
#include "treenode.h"
#include "traversal.h"
#include <iostream>
#include <vector>
using namespace std;

class TreeNode;
class MSearchTree {
	int num;
	TreeNode* root;
	TreeNode* hCopyNodes(const TreeNode* node);
	void hClearNodes(TreeNode*& node);
	bool isLeaf(const TreeNode* node) const;
	bool searchKey(const TreeNode* node, const Key& k) const;
	TreeNode* maxLeftNode(TreeNode*& node);
	TreeNode* minRightNode( TreeNode*& node);
	int searchKeyPositioninNode(TreeNode* node, const Key& key);
	TreeNode* searchNode(TreeNode* node, const Key& key);
	TreeNode* MSearchTree::searchForNodeWithKey(TreeNode* node, const Key& key);


public:
	MSearchTree(int m);
	MSearchTree(const MSearchTree& tree);
	MSearchTree& operator=(const MSearchTree& tree);
	MSearchTree& operator=(MSearchTree&&);
	bool insert(const Key& k);
	bool lookup(const Key&) const;
	void traverse(Traversal& t);
	~MSearchTree() { hClearNodes(root); }
	bool remove(const Key& key);
	friend class Traversal;
	friend ostream& operator<< (ostream& out, const MSearchTree& tree);
	void MSearchTree::iterateThroughLeaves(TreeNode* node) const;


};


#endif
