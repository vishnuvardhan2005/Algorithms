#include <iostream>
using namespace std;

// Doubly linked list
class DLinkedList
{
	struct node
	{
		int data;
		node* next;
		node* prev;
		
		node(int data,node* next=NULL,node* prev=NULL)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};
	
	node* root;
	
	public:
		
	DLinkedList()
	{
		root = NULL;
	}
		
	// inserts data at begining	
	void insert(int data)
	{
		if(root==NULL)
		{
			root = new node(data);
		}
		else
		{
			//insert at begining
			//new node becomes root and current first node will become second node
			root = new node(data,root,NULL);
			root->next->prev = root;
		}
	}
	
	void display()
	{
		node* sr = root;
		while(sr!=NULL)
		{
			cout << sr->data << " ";
			sr = sr->next;
		}
		cout << endl;
	}
	
	void reverse()
	{
		node* currNode = root;
		node* nextNode;
		
		while(currNode!=NULL)
		{
			nextNode = currNode->next;
			
			// swap next and prev
			swap(currNode->prev,currNode->next);
			
			// This is to make last node as root;
			root = currNode;
			
			// traverse to next node
			currNode = nextNode;
		}
	}
};

// Main
int main()
{
	DLinkedList dlist;
	
	// insert elements
	dlist.insert(10);
	dlist.insert(5);
	dlist.insert(20);
	dlist.insert(45);
	dlist.insert(89);
	
	// print elements
	dlist.display();
	
	dlist.reverse();
	
	dlist.display();
	
	return 0;
}

