#include "key.h"
#include "treenode.h"
#include <algorithm>
#include <iostream>
#include <vector>
#include"msearch.h"
using namespace std;

void test() {

	cout << "----- Pozvana test() funkcija -----" << endl;
	Key k1(8), k2(5);
	cout << k1 << endl;
	if (k1 < k2)
		cout << "Manji" << endl;
	else
		cout << "Veci" << endl;

	/*vector<Key> nizKljuceva;
	for (int i = 0; i < 4; i++) {
	nizKljuceva.push_back(i + 10);
	}
	cout << "----" << endl;
	vector<Key> drugiNizKljuceva = nizKljuceva;
	cout << nizKljuceva.at(2) << endl;
	cout << drugiNizKljuceva.at(2) << endl;
	nizKljuceva.at(2) = 5;
	cout << nizKljuceva.at(2) << endl;
	cout << drugiNizKljuceva.at(2) << endl;
	cout << "---" << endl;
	for (int i = 0; i < nizKljuceva.size(); i++)
	cout << nizKljuceva.at(i) << " ";
	std::sort(nizKljuceva.begin(), nizKljuceva.end());
	cout << endl;
	for (int i = 0; i < nizKljuceva.size(); i++)
	cout << nizKljuceva.at(i) << " ";
	auto it = std::upper_bound(nizKljuceva.begin(), nizKljuceva.end(), 20);
	nizKljuceva.insert(it, 20);
	cout << endl;
	for (int i = 0; i < nizKljuceva.size(); i++)
	cout << nizKljuceva.at(i) << " ";

	cout << "------------" << endl;
	auto iter = find(nizKljuceva.begin(), nizKljuceva.end(), 13);		//ova i naredna linija nalaze poziciju datog elementa
	int index = distance(nizKljuceva.begin(), iter);
	cout << index << endl;
	cout << endl;
	nizKljuceva.at(2) = 25;
	auto iblah = max_element(nizKljuceva.begin(), nizKljuceva.end());
	int indexxx = distance(nizKljuceva.begin(), iblah);
	cout << indexxx << endl;

	cout << endl;
	for (int i = 0; i < nizKljuceva.size(); i++)
	cout << nizKljuceva.at(i) << " ";
	nizKljuceva.erase(nizKljuceva.begin() + 2, nizKljuceva.end());
	cout << endl;
	for (int i = 0; i < nizKljuceva.size(); i++)
	cout << nizKljuceva.at(i) << " ";*/

	/*TreeNode t1(3), t2(3);
	Key k11(6), k12(8), k21(1), k3(5), k22(2), k23(3), k4(4);
	t1.add(k11);
	t1.add(k12);
	t1.add(k3);

	t2.add(k21);
	t2.add(k22);
	t2.add(k23);

	t1.setSubtree(k4, &t2);
	//t1.remove(k11);

	cout << t1 << endl;*/


	TreeNode t11(4), t12(3), t22(3), t32(3), t13(3), t0(0);
	cout << t0 << endl;
	t11.add(30);
	t11.add(60);
	t11.add(90);
	t11.add(78);
	cout << t11 << endl;
	MSearchTree m11(3);

	m11.insert(3);
	m11.insert(55);
	m11.insert(27);
	m11.insert(17);
	m11.insert(60);
	m11.insert(48);
	m11.insert(101);
	m11.insert(24);
	m11.insert(68);
	m11.insert(15);
	m11.remove(27);
	m11.remove(101);
	m11.insert(19);
	m11.insert(27);
	m11.insert(29);
	m11.insert(38);
	m11.insert(50);
	m11.insert(52);
	m11.insert(51);
	m11.insert(49);
	m11.remove(48);
	m11.insert(54);
	m11.insert(65);

	MSearchTree m22(m11);
	cout << m11 << endl;
	m11.remove(3);
	cout << m11 << endl;
	
	
/*	cout << m11 << endl;
	m11.remove(50);
	cout << m22 << endl;*/





}