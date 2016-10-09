#include <iostream>
using namespace std;

class LinkedList
{
	// linked list node
	struct node
	{
		int data;
		node* link;
		node()
		{
			
		}
		node(int data,node* link=NULL)
		{
			this->data = data;
			this->link = link;
		}
	};
	
	node* head;
	
	public:
		
	// constructor
	LinkedList()
	{
		head = NULL;
	}
	
	// Destructor
	~LinkedList()
	{
		// Delete all nodes in the list
		node* sr = head;
		while(sr!=NULL)
		{
			sr = sr->link;
			delete head;
			head = sr;
		}
	}
	
	// insert
	void insert(int data)
	{
		if(head==NULL)
		{
			head = new node(data);
		}
		else
		{
			// insert at start
			node* sr = new node(data,head);
			head = sr;
		}
	}
	
	// Reverses a linked list
	void reverse()
	{
		node* curr =  head;
		node* prev = NULL;
		node* next;
		
		while(curr!=NULL)
		{
			next = curr->link;
			curr->link = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
	}
		
	// Print list elements
	void display()
	{
		node* sr = head;
		while(sr!=NULL)
		{
			cout << sr->data << " ";
			sr = sr->link;
		}
		cout << endl;
	}
};
