#pragma once
class TreeNode{
public:
	TreeNode();
	TreeNode(int key, int value);
	int getKey();
	int getValue();
	~TreeNode();

private:
	int key;
	int value;

	TreeNode* leftChild;
	TreeNode* rightChild;
};
