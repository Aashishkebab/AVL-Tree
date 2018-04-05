#pragma once

#include <iostream>
#include <vector>
#include "TreeNode.h"
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
	bool exists(int key, TreeNode* start);

private:
	unsigned long size;
	TreeNode* root;
};

