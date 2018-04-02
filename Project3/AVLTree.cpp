#include "stdafx.h"
#include "AVLTree.h"
#include <vector>
using namespace std;	//This is bad style


AVLTree::AVLTree(){
	this->size = 0;
}

AVLTree::~AVLTree(){}



bool AVLTree::insert(int key, int value){
	if(exists(key, value)){
		return false;
	}
	return false;	//TODO - remove
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