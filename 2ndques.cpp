// a binary search tree
// modify so that all the greater values are added
// reverse inorder traversal will be used
#include<bits/stdc++.h>
using namespace std;


int area(int side) {
	return side * side;
}

void addGreaterElement(node* root, int &sum) {
	if (root == NULL) return;
	addGreaterElement(root->right, sum);
	sum += root->val;
	root->val = sum;
	addGreaterElement(root->left, sum);
}


int main() {

}