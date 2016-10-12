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

void LevelOrderTraversal(node* root)
{
	queue<node*> q1;
	queue<int> q2;
	
	q1.push(root);
	q2.push(0);
	
	node* sr;
	int level;
	
	while(!q1.empty())
	{
		sr = q1.front(); q1.pop();
		level = q2.front();q2.pop();
		
		if(sr->left!=NULL)
		{
			q1.push(sr->left);
			q2.push(level+1);
		}
		if(sr->right!=NULL)
		{
			q1.push(sr->right);
			q2.push(level+1);
		}
		
		cout << level << " " << sr->data << endl;
	}
}

int main()
{
	// level 0
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
	
	//Traversal
	LevelOrderTraversal(root);
	
	return 0;
}

