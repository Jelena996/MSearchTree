#include <iostream> 
#include "treenode.h"
#include <string>
#include<vector>
#include<algorithm>
using namespace std;

void errorDetected(const string& msg) {
	cout << msg << endl;
	exit(true);
}

TreeNode::TreeNode(int m)
{
	num = m;
	nodes.assign(num + 1, nullptr);
}

TreeNode::TreeNode(const TreeNode& node)
{
	num = node.num;

	for (int i = 0; i < node.keys.size(); i++)
	{
		Key newkey = node.keys.at(i);
		keys.push_back(newkey);

	}
	nodes.assign(num + 1, nullptr);

}

bool TreeNode::isFull() const
{
	return keys.size() == num;
}

bool TreeNode::isEmpty() const {
	return  keys.size() == 0;
}

bool TreeNode::add(const Key& k) {
	if (keys.size() == 0)
	{
		keys.push_back(k);
		return true;
	}
	
if (keys.size()<num && !contains(k))
{

vector<Key>::iterator begin = keys.begin();
vector<Key>::iterator end = keys.end();

auto iter = keys.begin();


while (iter != end)
{

if (k<*iter)
{
keys.insert(iter, k);
return true;
}
iter++;
}

keys.push_back(k);
return true;
}

return false;
}
	
vector<Key> TreeNode::getKeys() const {
	return keys;
}

TreeNode* TreeNode::getLeftSubtree(const Key& k) const {
	for (int i = 0; i < keys.size(); i++)
		if (keys.at(i) == k) { return nodes.at(i); }
	errorDetected("Cvor ne sadrzi ovaj kljuc");

}

TreeNode* TreeNode::getRightSubtree(const Key& k) const {
	for (int i = 0; i < keys.size(); i++)
		if (keys.at(i) == k) { return nodes.at(i + 1); }
	errorDetected("cvor ne sadrzi ovaj kljuc");
}
Key TreeNode::getMaxKey() const {
	if (keys.size() == 0)  errorDetected("Kljuc je prazan.");
	return  keys.at(keys.size() - 1);
}
Key TreeNode::getMinKey() const {
	if (keys.size() == 0)  errorDetected("Kljuc je prazan.");
	return  keys.at(0);
}

bool TreeNode::contains(const Key& k) const {
	if (this == nullptr) return false;
	for (int i = 0; i < keys.size(); i++)
		if (keys.at(i) == k) return true;
	return false;
}

TreeNode* TreeNode::getSubtree(const Key& k) const {    //ne moram da mijenjam uslov, jer ako mi je list bio pun, pa sam ga ja skratila, uvijek cu moci da dodam novu vrijednost u njega, an neku poziciju
	if (keys.size() != num || contains(k)) errorDetected("Ovaj cvor stabla nije list, ili sadrzi kljuc");
	else if (k > keys.at(num-1)) return nodes.at(num);
	for (int i = 0; i < keys.size(); i++) {
		if (k < keys.at(i)) return nodes.at(i);
	}

}

bool TreeNode::setSubtree(const Key& k, TreeNode* subnode) {
	if (getSubtree(k) != nullptr) return false;
	if (keys.size() != num || contains(k)) return false;
	if (k > keys.at(num - 1)) {
		nodes.at(num) = subnode; return true;
	}
	for (int i = 0; i < keys.size(); i++) {
		if (k < keys.at(i)) {
			nodes.at(i) = subnode; return true;
		}
	}
}

bool TreeNode::remove(const Key& k) {   //brise samo ako su svi pokazivaci nullptr(samo tada ce biti pozvana) 
	if (!contains(k))
		return false;
	else {
	auto it = upper_bound(keys.begin(), keys.end(), k);
	int index = distance(keys.begin(), it) - 1;
	keys.erase(keys.begin() + index);
	/*nodes.erase(nodes.begin() + index);*/
	}
	return true;
}

ostream& operator<<(ostream& out, const TreeNode& node) {
	if (node.isEmpty())
		out << "()";
	else {
		out << "(";
		for (auto it = node.keys.begin(); it != node.keys.end() - 1; ++it)
			out << *it << ", ";
		out << *(node.keys.end() - 1) << ")";
		return out;
	}
}

TreeNode::~TreeNode() {
	keys.erase(keys.begin(), keys.end());
	nodes.erase(nodes.begin(), nodes.end());
}



