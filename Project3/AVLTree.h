#pragma once

#include <iostream>
#include <vector>
using namespace std;

class AVLTree{
public:
	AVLTree();
	~AVLTree();
	bool insert(int key, int value);
	int getHeight();
	int getSize();
	void print();
	bool find(int key, int & value);
	vector<int> findRange(int lowkey, int highkey);
};

