#ifndef _KEY_H_
#define _KEY_H_
#include <iostream>
using namespace std;

class Key {
	int value;

public:
	Key(int m) : value(m) {}

	friend bool operator< (const Key& key1, const Key& key2) {
		if (key1.value < key2.value) return true;
		else return false;
	}

	friend bool operator<= (const Key& key1, const Key& key2) {
		if (key1.value <= key2.value) return true;
		else return false;
	}

	friend bool operator> (const Key& key1, const Key& key2) {
		if (key1.value > key2.value) return true;
		else return false;
	}

	friend bool operator>= (const Key& key1, const Key& key2) {
		if (key1.value <= key2.value) return true;
		else return false;
	}

	friend bool operator== (const Key& key1, const Key& key2) {
		if (key1.value == key2.value) return true;
		else return false;
	}

	friend bool operator != (const Key& key1, const Key& key2) {
		if (key1.value != key2.value) return true;
		else return false;
	}

	friend ostream& operator << (ostream& out, const Key& key) {
		return out << key.value;
	}
};

#endif