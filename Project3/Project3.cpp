// Project3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "AVLTree.h"
#include "TreeNode.h"
using namespace std;


int main(){

	AVLTree* hi = new AVLTree();
	hi->insert(40, 12);
	hi->insert(20, 16);
	hi->insert(50, 11);
	hi->insert(10, 54);
	hi->insert(30, 16);
	hi->insert(45, 72);
	hi->print();
	int test;
	hi->find(40, test);
	cout << endl << test;

	vector<int> howdy = hi->findRange(12, 16);
	cout << endl;
	for(unsigned short i = 0; i < howdy.size(); i++){
		cout << howdy[i] << " ";
	}


	cout << std::endl << std::endl;
	system("PAUSE");
	return 0;
}

