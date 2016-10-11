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
		node* sr = root;
		node* temp;
		node* sr1;
		while(sr!=NULL)
		{
			sr1 = sr->next;
			
			// swap next and prev
			temp = sr->prev;
			sr->prev = sr->next;
			sr->next = temp;
			
			// This is to make last node as root;
			root = sr;
			
			// traverse to next node
			sr = sr1;
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

