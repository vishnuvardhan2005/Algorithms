#include <iostream>
#include <LinkedList.h>
using namespace std;

// Main
int main()
{
	LinkedList list;
	
	// insert data
	list.insert(10);
	list.insert(20);
	list.insert(30);
	list.insert(40);
	
	// print
	list.display();
	
	return 0;
}

