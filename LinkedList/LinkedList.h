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
	
	// insert at end
	void insertAtEnd(int data)
	{
		if(head==NULL)
		{
			head = new node(data);
		}
		else
		{
			node* sr = head;
			while(sr->link!=NULL)
			{
				sr = sr->link;
			}
			// sr now pointing to last node;
			sr->link = new node(data);
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
	
	// Rotates the list
	void rotate(int k)
	{
		// This should be the first check. rotating a single node results in same list
		if(head==NULL||head->link==NULL)
			return;
			
		k = k % this->length(); // This shouldn't cause divide by zero
		
		// 0 and 1 node, don't do anything
		if(k<=0)
			return;
			
		node* sr = head;
		node* tail;
		while(k!=0)
		{
			tail = sr;
			sr = sr->link;
			k--;
		}
		tail->link = NULL;
		node* temp = sr;
		while(temp->link!=NULL)
		{
			temp = temp->link;
		}
		temp->link = head;
		head = sr;
	}
	
	// returns the length of linked list
	int length()
	{
		int len = 0;
		node* sr = head;
		while(sr!=NULL)
		{
			len++;
			sr = sr->link;
		}
		return len;
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
