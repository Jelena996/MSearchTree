#include "treenode.h"
#include "msearch.h"
#include "traversal.h"
#include <iostream>
#include<algorithm>
using namespace std;


MSearchTree::MSearchTree(int m) : num(m), root(nullptr) {}

TreeNode* MSearchTree::hCopyNodes(const TreeNode* node) {
	if (node == nullptr) return nullptr;
	TreeNode* nodeCopy = new TreeNode(*node);      //ovaj radi dobro
	for (int i = 0; i <node->nodes.size(); i++) {
		nodeCopy->nodes.at(i) = hCopyNodes(node->nodes.at(i));
	}
	return nodeCopy;
}

void MSearchTree::hClearNodes(TreeNode*& node) {
	if (node == nullptr) return;
	for (int i = 0; i < node->nodes.size(); i++)
		if (node->nodes.at(i) != nullptr) hClearNodes(node->nodes.at(i));
	node->keys.clear();
	node = nullptr;
}


MSearchTree::MSearchTree(const MSearchTree& tree) {
	root = hCopyNodes(tree.root);
}

MSearchTree& MSearchTree::operator=(const MSearchTree& tree) {
	if (this != &tree) {
		hClearNodes(this->root);
		root = hCopyNodes(tree.root);

	}
	return *this;
}

MSearchTree& MSearchTree::operator=(MSearchTree&& tree) {
	if (this != &tree) {
		hClearNodes(root);
		root = tree.root;
		tree.root = nullptr;
	}
	return *this;
}


void MSearchTree::traverse(Traversal& t) {
	t.visit(root);
}

bool MSearchTree::isLeaf(const TreeNode* node) const {
	if (node == nullptr) return false;
	for (int i = 0; i < node->nodes.size(); i++)
		if (node->nodes.at(i) != nullptr)
			return false;
	return true;
}

TreeNode* MSearchTree::searchNode(TreeNode* node, const Key& key) {  //vraca node u koji se ubacuje novi kljuc (nepopunjen ili with hetsubtree==nullptr
	if (!node->isFull() || ((node->isFull() && node->getSubtree(key) == nullptr)))
		return node;

	searchNode(node->getSubtree(key), key); //nece pozvati getsubtree ako cvor nije pun
}  //vraca pokazivac na node u koji se moze staviti key, ili na ciji se pokazivac privezati

int MSearchTree::searchKeyPositioninNode(TreeNode* node, const Key& key) {        //bice pozvana samo ako kljuc postoji u cvoru
	for (int i = 0; i < node->keys.size(); i++) 
		if (node->keys.at(i) == key) return i;
}

bool MSearchTree::lookup(const Key& k) const {

	return searchKey(root, k);
}

bool MSearchTree::searchKey(const TreeNode* node, const Key& k) const {
	if (node == nullptr) return false;
	if (node->contains(k)) return true;
	if (!node->isFull()) return false;
	if (!node->contains(k)) {

		if (node->getSubtree(k) == nullptr) return false;
		else searchKey(node->getSubtree(k), k);
	}
}

bool MSearchTree::insert(const Key& k) {
	if (lookup(k))
		return false;

	if (root == nullptr) {
		root = new TreeNode(num);
		root->keys.assign(1, k);
		return true;
	}
	
	TreeNode* nodeptr = searchNode(root, k);
	if (!nodeptr->isFull()) return nodeptr->add(k);
	else if (nodeptr->getSubtree(k) == nullptr) {
		TreeNode* newNode = new TreeNode(num);
		newNode->keys.assign(1, k);
		return nodeptr->setSubtree(k, newNode);
	}
}

TreeNode* MSearchTree::searchForNodeWithKey(TreeNode* node, const Key& key) { //bice proslijedjen node* koji sigurno sadrzi key
	if (node->contains(key)) return node;
	else searchForNodeWithKey(node->getSubtree(key), key);
}

TreeNode* MSearchTree::maxLeftNode(TreeNode*& node) {
	if (node->nodes.at(node->nodes.size()) == nullptr) {
		if (node->keys.size() == 1) { TreeNode* helpptr = new TreeNode(*node); node = nullptr; return helpptr; }
		else return node;
	}
	else   maxLeftNode(node->nodes.at(node->nodes.size()));
}

TreeNode* MSearchTree::minRightNode(TreeNode*& node) {
	if (node->nodes.at(0) == nullptr) {
		if (node->keys.size() == 1) { TreeNode* helpptr = new TreeNode(*node); node = nullptr; return helpptr; }
		else return node;		
	}
     else  minRightNode(node->nodes.at(0));

}



bool MSearchTree::remove(const Key& key) {

	if (!lookup(key)) return false;
	TreeNode* node = searchForNodeWithKey(root, key);
	if (node->getRightSubtree(key) != nullptr) {
		TreeNode* help = minRightNode(node->nodes.at(searchKeyPositioninNode(node, key) +1));//search position return indx
		Key help1 = node->keys.at(searchKeyPositioninNode(node, key));
		node->keys.at(searchKeyPositioninNode(node, key)) = help->keys.at(0);
		help->keys.at(0) = help1;
		if (help->keys.size() == 1) return true;

		if (isLeaf(help)) { help->remove(key); return true; }   //krajnji kljuc ce otici iz nekog lista
		remove(key);

	}

	else if (node->getLeftSubtree(key) != nullptr) {
		TreeNode* help = maxLeftNode(node->nodes.at(searchKeyPositioninNode(node,key)));
		Key help1 = node->keys.at(searchKeyPositioninNode(node, key));
		node->keys.at(searchKeyPositioninNode(node, key)) = help->keys.at(help->keys.size() - 1);
		help->keys.at(help->keys.size() - 1) = help1;
		if (isLeaf(help)) {
			help->remove(key); return true;
		}
		this->remove(help->keys.at(help->keys.size() - 1));
	}

	else if (node->getLeftSubtree(key) == nullptr && node->getRightSubtree(key) == nullptr) {
		node->nodes.erase(node->nodes.begin() + searchKey(node, key)+1);
		node->keys.erase(node->keys.begin() + searchKey(node, key)+1);
		/*if (node->nodes.size() == 0)  delete
	return true;*/
	}
}


void MSearchTree::iterateThroughLeaves(TreeNode* node) const {
	if (node == nullptr)
		return;
	if (isLeaf(node)) {
		cout << *node;
		return;
	}
	else {
		for (int i = 0; i <= node->keys.size(); i++) {
			if (i == 0)
				cout << "(";
			iterateThroughLeaves(node->nodes.at(i));
			if (i < node->keys.size()) {
				cout << node->keys.at(i) << ", ";
			}
			if (i == node->keys.size())
				cout << ")";
		}
	}
}




ostream& operator<< (ostream& out, const MSearchTree& tree) {

	if (tree.root == nullptr)
		out << "()";
	else {
		tree.iterateThroughLeaves(tree.root);
	}
	return out;
}






