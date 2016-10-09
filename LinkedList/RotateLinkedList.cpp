#include <iostream>
#include <LinkedList.h>
using namespace std;

// Main
int main()
{
	LinkedList list;
	
	// insert elements
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);
	
	// print
	list.display();
	
	// rotate
	list.rotate(10);
	
	// print again
	list.display();
	
	return 0;
}
