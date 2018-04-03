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
	if(exists(key, value)){
		return false;
	}

	TreeNode* temp = this->root;
	
	while(true){
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
}


int AVLTree::getHeight(){
	return 0;	//TODO - remove
}

int AVLTree::getSize(){
	return this->size;
}

void AVLTree::print(){

}

bool AVLTree::find(int key, int& value){
	return false;	//TODO - remove
}

vector<int> AVLTree::findRange(int lowkey, int highkey){
	vector<int> hi;	//TODO - remove
	return hi;	//TODO - remove
}

bool AVLTree::exists(int key, int value){

}