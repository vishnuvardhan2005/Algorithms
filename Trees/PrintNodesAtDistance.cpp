#include <iostream>
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

void inorder(node* sr,int& d,int k)
{
	if(sr!=NULL)
	{
		d++;
		inorder(sr->left,d,k);
		d--;
		if(d==k)
			cout << sr->data << " " << k << endl;
		d++;
		inorder(sr->right,d,k);
		d--;
	}
}

void printNodesAtDistance(node* root,int k)
{
	int d = 0;
	inorder(root,d,k);
}

int main()
{
	int k = 1;
	
	node* root = new node(1);
	
	// level 1
	root->left = new node(2);
	root->right = new node(3);
	
	// level 2
	root->left->left = new node(4);
	root->left->right = new node(5);
	
	root->right->left = new node(6);
	root->right->right = new node(7);
	
	// prints nodes at distance k from root
	printNodesAtDistance(root,k);
	
	return 0;
}
