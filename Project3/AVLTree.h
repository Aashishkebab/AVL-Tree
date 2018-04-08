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
	void print(TreeNode* node, unsigned short height);
	bool find(int key, int& value);
	bool find(TreeNode* root, int key, int& value);
	vector<int> findRange(int lowkey, int highkey);
	vector<int>* findRange(TreeNode* node, int lowkey, int highkey, vector<int>* theRange);
	bool exists(int key, TreeNode* start);

private:
	unsigned long size;
	TreeNode* root;
};

