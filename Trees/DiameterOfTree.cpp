#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
	
	node(int data,node* left=NULL,node* right=NULL)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}
};

int getHeight(node* sr)
{
	if(sr==NULL)
		return 0;
	if(sr->left==NULL&&sr->right==NULL)
		return 1;
	return 1+max(getHeight(sr->left),getHeight(sr->right));
}

int getDiameter(node* sr)
{
	if(sr==NULL)
		return 0;
	if(sr->left==NULL&&sr->right==NULL)
		return 1;
	
	// throught root
	int lHeight = getHeight(sr->left);
	int rHeight = getHeight(sr->right);
	
	// not through root
	int lDiameter = getDiameter(sr->left);
	int rDiameter = getDiameter(sr->right);
	
	return max(1+lHeight+rHeight, // throught root
	             max(lDiameter,rDiameter)  // not through root
				 );
}

int main()
{
	
	node* root = new node(1);
	
	// level 1
	root->left = new node(2);
	root->right = new node(3);
	
	// level 2
	root->left->left = new node(4);
	root->left->right = new node(55);
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	// level 3
	root->left->left->right = new node(10);
	
	
	cout << getDiameter(root) << endl;
	
	node* root1 = new node(1);
	root1->left = new node(2);
	root1->left->left = new node(3);
	root1->left->left->left = new node(4);
	root1->left->right = new node(5);
	root1->left->right->left = new node(6);
	
	// ans - 5
	cout << getDiameter(root1) << endl;
	
	return 0;
}
