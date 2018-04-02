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

TreeNode::~TreeNode(){}
