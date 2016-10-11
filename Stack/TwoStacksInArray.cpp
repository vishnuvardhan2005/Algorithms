#include <iostream>
using namespace std;
#define MAX_ARRAY_SIZE 10


// Very basic version of stack in a single array
// Overflows are not handled. todo. Just happy cases for now
class DoubleStack
{
	int* arr;
	int n1;
	int n2;
	int size;
	
	public:
	DoubleStack()
	{
		arr = new int[MAX_ARRAY_SIZE];
		n1 = 0;
		n2 = 0;
	}
	
	~DoubleStack()
	{
		delete[] arr;
	}
	
	void push(int data,int p)
	{
		if(p==1)
		{
			arr[n1++] = data;
		}
		else if(p==2)
		{
			n2++;
			arr[MAX_ARRAY_SIZE-n2] = data;
		}
		else
		{
			throw "Error";
		}
		
	}
	
	int pop(int p)
	{
		int data;
		if(p==1)
		{
			data = arr[n1-1];		
			n1--;
		}
		else if(p==2)
		{
			data = arr[MAX_ARRAY_SIZE-n2];
			n2--;
		}
		else
		{
			throw "Error";
		}
		return data;
	}
	
	bool empty(int p)
	{
		bool result;
		if(p==1)
		{
			result = n1==0?true:false;
		}
		else if(p==2)
		{
			result = n2==0?true:false;
		}
		else
		{
			throw "Error";
		}
		
		return result;
	}
};

// Main
int main()
{
	DoubleStack s;
	// push elements into stack1
	s.push(1,1);
	s.push(2,1);
	s.push(3,1);
	
	//  push elements into stack2
	s.push(4,2);
	s.push(5,2);
	s.push(6,2);
	
	// pop all from stack1
	while(!s.empty(1))
	{
		cout << s.pop(1) << endl;
	}
	
	// pop all from stack2
	while(!s.empty(2))
	{
		cout << s.pop(2) << endl;
	}
	return 0;
}

