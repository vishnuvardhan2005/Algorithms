#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int>& s,int data)
{
	int temp;
	if(s.empty())
	{
		s.push(data);
	}
	else
	{
		temp = s.top();s.pop();
		insertAtBottom(s,data);
		s.push(temp);
	}
}

void reverse(stack<int>& s)
{
	int data;
	if(!s.empty())
	{
		data = s.top();s.pop();
		reverse(s);
		insertAtBottom(s,data);
	}
}

void print(stack<int> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

// Main
int main()
{
	stack<int> s;
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(45);
	
	//print
	print(s);
	
	//reverse
	reverse(s);
	
	//print
	print(s);
	
	return 0;
}

