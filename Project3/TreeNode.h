#pragma once
class TreeNode{
public:
	TreeNode();
	TreeNode(int key, int value);
	int getKey();
	int getValue();
	TreeNode * getLeftChild();
	TreeNode * getRightChild();
	void setLeftChild(TreeNode * theNode);
	void setRightChild(TreeNode * theNode);
	~TreeNode();

private:
	int key;
	int value;

	TreeNode* leftChild;
	TreeNode* rightChild;
};
