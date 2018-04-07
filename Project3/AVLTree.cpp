#include "stdafx.h"
#include "AVLTree.h"
#include <vector>
#include "TreeNode.h"
using namespace std;	//This is bad style


AVLTree::AVLTree(){
	this->size = 0;
}

AVLTree::~AVLTree(){}



bool AVLTree::insert(int key, int value){
	if(exists(key, this->root)){
		cout << "\n\nCannot add key that already exists!";
		return false;
	}

	if(!this->root){
		this->root = new TreeNode(key, value);
		return true;
	}

	TreeNode* temp = this->root;

	while(temp){
		if(key < temp->getKey()){
			if(temp->getLeftChild()){
				temp = temp->getLeftChild();
			}
			else{
				temp->setLeftChild(new TreeNode(key, value));
				return true;
			}
		}
		else{
			if(temp->getRightChild()){
				temp = temp->getRightChild();
			}
			else{
				temp->setRightChild(new TreeNode(key, value));
				return true;
			}
		}
	}
	return false;
}


int AVLTree::getHeight(){
	return 0;	//TODO - remove
}

int AVLTree::getSize(){
	return this->size;
}

void AVLTree::print(){
	print(this->root);
}

void AVLTree::print(TreeNode* node){
	if(node->getRightChild()){
		print(node->getRightChild());
	}
	cout << "\n" << node->getKey() << ", " << node->getValue();
	if(node->getLeftChild()){
		print(node->getLeftChild());
	}
}

bool AVLTree::find(int key, int& value){
	if(find(this->root, key, value)){
		return true;
	}
	else{
		return false;
	}
}

bool AVLTree::find(TreeNode* node, int key, int& value){
	if(node->getKey() == key){
		value = node->getValue();
		return true;
	}

	if(node->getRightChild()){
		if(find(node->getRightChild(), key, value)){
			return true;
		}
	}
	if(node->getLeftChild()){
		if(find(node->getLeftChild(), key, value)){
			return true;
		 }
	}
	return false;
}

vector<int> AVLTree::findRange(int lowkey, int highkey){
	vector<int> theRange;

	return theRange;
}

bool AVLTree::exists(int key, TreeNode* start){
	if(!start){
		return false;
	}

	TreeNode* temp = start;
	if(temp->getKey() == key){
		return true;
	}

	bool doesExist = false;
	doesExist = exists(key, temp->getLeftChild());
	doesExist = exists(key, temp->getRightChild());

	return doesExist;
}