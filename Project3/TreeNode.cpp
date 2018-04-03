#include "stdafx.h"
#include "TreeNode.h"


TreeNode::TreeNode(){
}

TreeNode::TreeNode(int key, int value):key(key), value(value){	//This is a C++ initializer list
}

//The below is the same thing as above, but written in a style that doesn't use initializer lists
//TreeNode::TreeNode(int key, int value){
//	this->key = key;
//	this->value = value;
//}

int TreeNode::getKey(){
	if(!this){
		throw "Cannot get key of null";
		return NULL;
	}
	return this->key;
}

int TreeNode::getValue(){
	if(!this){
		throw "Cannot get value of null";
		return NULL;
	}
	return this->value;
}

TreeNode* TreeNode::getLeftChild(){
	if(!this){
		throw "Cannot get left child of null";
		return nullptr;
	}
	return this->leftChild;
}

TreeNode* TreeNode::getRightChild(){
	if(!this){
		throw "Cannot get right child of null";
		return nullptr;
	}
	return this->rightChild;
}


void TreeNode::setLeftChild(TreeNode* theNode){
	if(!this){
		throw "Cannot set left child of null";
		return;
	}
	this->leftChild = theNode;
}

void TreeNode::setRightChild(TreeNode* theNode){
	if(!this){
		throw "Cannot get right child of null";
		return;
	}
	this->rightChild = theNode;
}

TreeNode::~TreeNode(){}
