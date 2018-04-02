#include "stdafx.h"
#include "TreeNode.h"


TreeNode::TreeNode(){
}

TreeNode::TreeNode(int key, int value):key(key), value(value){	//This is a C++ initializer list
}

int TreeNode::getKey(){
	return this->key;
}

int TreeNode::getValue(){
	return this->value;
}

TreeNode* TreeNode::getLeftChild(){
	return this->leftChild;
}

TreeNode* TreeNode::getRightChild(){
	return this->rightChild;
}


void TreeNode::setLeftChild(TreeNode* theNode){
	this->leftChild = theNode;
}

void TreeNode::setRightChild(TreeNode* theNode){
	this->rightChild = theNode;
}

//The below is the same thing as above, but written in a style that doesn't use initializer lists
//TreeNode::TreeNode(int key, int value){
//	this->key = key;
//	this->value = value;
//}

TreeNode::~TreeNode(){}
