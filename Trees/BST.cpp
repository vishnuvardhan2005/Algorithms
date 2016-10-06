#include <iostream>
using namespace std;

class BST
{
	struct BSTNode
	{
		int data;
		BSTNode* left;
		BSTNode* right;
		BSTNode()
		{
			
		}
		BSTNode(int data,BSTNode* left=NULL,BSTNode* right=NULL)
		{
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};
	
	BSTNode* root;
	
	// Private methods
	
	BSTNode* insert(BSTNode* sr,int data)
	{
		if(sr==NULL)
		{
			sr = new BSTNode(data);
		}
		else
		{
			if(data > sr->data)
			{
				sr->right = insert(sr->right,data);
			}
			else if(data < sr->data)
			{
				sr->left = insert(sr->left,data);
			}
			else
			{
				throw "duplicate data not allowed";
			}
		}
		return sr;
	}
	
	void inOrder(BSTNode* sr)
	{
		if(sr!=NULL)
		{
			inOrder(sr->left);
			cout << sr->data << " ";
			inOrder(sr->right);
		}
	}
	public:
	
	// Constructor	
	BST()
	{
		root = NULL;
	}
	
	void insert(int data)
	{
		root = insert(root,data);
	}
	
	void inOrder()
	{
		inOrder(root);
	}
};

// Main
int main()
{
	BST bstObj;
	bstObj.insert(10);
	bstObj.insert(5);
	bstObj.insert(20);
	bstObj.insert(7);
	bstObj.insert(2);
	bstObj.insert(25);
	bstObj.insert(15);
	
	bstObj.inOrder();
	
	return 0;
}

