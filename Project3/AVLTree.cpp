#include "stdafx.h"
#include "AVLTree.h"
#include <vector>
#include "TreeNode.h"
#include <cmath>
using namespace std;	//This is bad style


AVLTree::AVLTree(){
	this->size = 0;
}

AVLTree::~AVLTree(){
	delete this->root;
}

static int max(int value1, int value2){
	return (value1 > value2) ? value1 : value2;	//Ternary operator
}

//bool AVLTree::insert(TreeNode*& node, int key){
//	if(node){
//
//	}
//	if(key < node->getKey()){
//		TreeNode* lc = node->getLeftChild();
//		insert(lc, key);
//		node->setLeftDepth(max(node->getLeftChild()->getLeftDepth(), node->getLeftChild()->getRightDepth()) + 1);
//	}
//}

bool AVLTree::insert(int key, int value){
	try{
		this->root = insert(this->root, key, value);
		this->size++;
		return true;
	}
	catch(...){	//If duplicate
		return false;
	}
}

TreeNode* AVLTree::insert(TreeNode* node, int key, int value){
	if(!node){
		return new TreeNode(key, value);
	}

	if(key < node->getValue()){
		node->setLeftChild(insert(node->getLeftChild(), key, value));
	}
	else if(key > node->getValue()){
		node->setRightChild(insert(node->getRightChild(), key, value));
	}
	else{	//If equals (duplicate value)
		throw "Duplicate";
		return node;
	}

	node->setHeight(max(node->getLeftChild()->getHeight(), node->getRightChild()->getHeight()) + 1);

	short balance = node->getBalance();

	//Rotations
	if(balance > 1 && key < node->getLeftChild()->getKey()){	//Left-left
		return rightRotate(node);
	}
	if(balance < -1 && key > node->getRightChild()->getKey()){	//Rihgt-right
		return leftRotate(node);
	}
	if(balance > 1 && key > node->getLeftChild()->getKey()){	//Left-right
		node->setLeftChild(leftRotate(node->getLeftChild()));
		return rightRotate(node);
	}
	if(balance < -1 && key < node->getRightChild()->getKey()){	//Right-left
		node->setRightChild(rightRotate(node->getRightChild()));
		return leftRotate(node);
	}

	return node;
}


//bool AVLTree::insert(int key, int value){	//BST iterative insert
//	if(exists(key, this->root)){
//		cout << "\n\nCannot add key that already exists!";
//		return false;
//	}
//
//	if(!this->root){
//		this->root = new TreeNode(key, value, 0, 0);
//		return true;
//	}
//
//	TreeNode* temp = this->root;
//
//	while(temp){
//		if(key < temp->getKey()){
//			if(temp->getLeftChild()){
//				temp->incrementLeftDepth();
//				temp = temp->getLeftChild();
//			}
//			else{
//		 		temp->setLeftChild(new TreeNode(key, value, temp->getLeftDepth() + 1, temp->getLeftDepth() + 1));
//				return true;
//			}
//		}
//		else{
//			if(temp->getRightChild()){
//				temp->incrementRightDepth();
//				temp = temp->getRightChild();
//			}
//			else{
//				temp->setRightChild(new TreeNode(key, value, temp->getLeftDepth() + 1, temp->getLeftDepth() + 1));
//				return true;
//			}
//		}
//	}
//	return false;
//}

int AVLTree::getHeight(){
	return this->root->getHeight() + 1;
}

int AVLTree::getSize(){
	return this->size;
}

void AVLTree::print(){
	print(this->root, 0);
}

void AVLTree::print(TreeNode* node, unsigned short height){
	if(node->getRightChild()){
		print(node->getRightChild(), height + 1);
	}

	cout << "\n";
	for(unsigned short i = 0; i < height; i++){
		cout << "\t";
	}
	cout << node->getKey() << ", " << node->getValue();

	if(node->getLeftChild()){
		print(node->getLeftChild(), height + 1);
	}
}

bool AVLTree::find(int key, int& value){
	return find(this->root, key, value);
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
	return *(findRange(this->root, lowkey, highkey, new vector<int>));
}

vector<int>* AVLTree::findRange(TreeNode* node, int lowkey, int highkey, vector<int>* theRange){	//Head recursion
	if(node->getValue() >= lowkey && node->getLeftChild()){
		theRange = findRange(node->getLeftChild(), lowkey, highkey, theRange);
	}
	if(node->getValue() <= highkey && node->getRightChild()){
		theRange = findRange(node->getRightChild(), lowkey, highkey, theRange);
	}

	if(node->getValue() >= lowkey && node->getValue() <= highkey){
		theRange->push_back(node->getKey());
		theRange->push_back(node->getValue());
	}

	return theRange;
}

//vector<int>* AVLTree::findRange(TreeNode* node, int lowkey, int highkey, vector<int>* theRange){	//Tail recursion
//
//	if(node->getValue() >= lowkey && node->getValue() <= highkey){
//		theRange->push_back(node->getKey());
//		theRange->push_back(node->getValue());
//	}
//
//	if(node->getValue() >= lowkey && node->getLeftChild()){
//		theRange = findRange(node->getLeftChild(), lowkey, highkey, theRange);
//	}
//	if(node->getValue() <= highkey && node->getRightChild()){
//		theRange = findRange(node->getRightChild(), lowkey, highkey, theRange);
//	}
//
//	return theRange;
//}

/***********************************
Purpose:	Checks if a node in the tree with the
				specified key already exists.
**********************************/
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

TreeNode* AVLTree::leftRotate(TreeNode* node){
	TreeNode* newRoot = node->getRightChild();
	TreeNode* temp = newRoot->getLeftChild();

	newRoot->setLeftChild(node);
	node->setRightChild(temp);

	node->setHeight(max(node->getLeftChild()->getHeight(), node->getRightChild()->getHeight()) + 1);
	newRoot->setHeight(max(newRoot->getLeftChild()->getHeight(), newRoot->getRightChild()->getHeight()) + 1);	//I apologize for the length of this line that I am now making longer by adding this comment...

	return newRoot;
}

TreeNode* AVLTree::rightRotate(TreeNode* node){
	TreeNode* newRoot = node->getLeftChild();
	TreeNode* temp = newRoot->getRightChild();

	newRoot->setRightChild(node);
	node->setLeftChild(temp);

	node->setHeight(max(node->getLeftChild()->getHeight(), node->getRightChild()->getHeight()) + 1);
	newRoot->setHeight(max(newRoot->getLeftChild()->getHeight(), newRoot->getRightChild()->getHeight()) + 1);

	return newRoot;
}
