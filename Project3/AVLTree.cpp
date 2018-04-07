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

void AVLTree::print(TreeNode* temp){
	if(temp->getRightChild()){
		print(temp->getRightChild());
	}
	cout << "\n" << temp->getKey() << ", " << temp->getValue();
	if(temp->getLeftChild()){
		print(temp->getLeftChild());
	}
}

bool AVLTree::find(int key, int& value){
	return false;	//TODO - remove
}

vector<int> AVLTree::findRange(int lowkey, int highkey){
	vector<int> hi;	//TODO - remove
	return hi;	//TODO - remove
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