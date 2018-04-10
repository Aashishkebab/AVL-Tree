#pragma once
class TreeNode{
public:
	TreeNode();
	TreeNode(int key, int value);
	int getKey();
	int getValue();
	void setValue(int& value);
	TreeNode* getLeftChild();
	TreeNode* getRightChild();
	void setLeftChild(TreeNode * theNode);
	void setRightChild(TreeNode * theNode);
	//void incrementLeftDepth();
	//void incrementRightDepth();
	//unsigned short getLeftDepth();
	//unsigned short getRightDepth();
	//void setLeftDepth(unsigned short number);
	//void setRightDepth(unsigned short number);
	void setHeight(unsigned short height);
	unsigned short getHeight();
	short getBalance();
	~TreeNode();

private:
	int key;
	int value;
	unsigned short height;

	TreeNode* leftChild;
	TreeNode* rightChild;
};
