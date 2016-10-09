#include <iostream>
#include <string.h>
using namespace std;

class Trie
{
	struct node
	{
		node* children[26]; // to accomidate 26 chars alphabets
		bool isLeaf;	
	};
	node* root;
	
	node* getNode()
	{
		node* sr = new node();
		for(int i=0;i<26;i++)
		{
			sr->children[i] = NULL;
		}
		sr->isLeaf = false;
	}
	
	public:
	Trie()
	{
		root = getNode();
	}
	
	void insert(char* key)
	{
		int len = strlen(key);
		int index = 0;
		node* sr = root;
		
		for(int i=0;i<len;i++)
		{
			index = key[i]-'A'; // key is capital letters
			if(sr->children[index]==NULL)
			{
				sr->children[index] = getNode();
			}
			sr = sr->children[index];
		}
		sr->isLeaf = true;
	}
	
	bool search(char* key)
	{
		int len = strlen(key);
		int index = 0;
		node* sr = root;
		bool result = true;
		
		for(int i=0;i<len;i++)
		{
			index = key[i] - 'A';
			if(sr->children[index]==NULL)
			{
				result = false;
				break;
			}
			else
			{
				sr = sr->children[index];
			}
		}
		
		if(result==true&&sr->isLeaf==false)
		{
			result = false;
		}
		return result;
	}
	
	// displays all the words in dictionary
	void display()
	{
		node* sr = root;
		for(int i=0;i<26;i++)
		{
			
		}
	}
};

// Main
int main()
{
	Trie t;
	t.insert("HELLO");
	t.insert("AND");
	t.insert("ANSWER");
	
	if(t.search("ANSWER")==true)
		cout << "Found" << endl;
	else
		cout << "Not Found" << endl;
	
	return 0;
}
