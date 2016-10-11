#include <iostream>
#include <stack>
using namespace std;

// Algorithm
// STEP1: If scanned character is operand, output it
// STEP2: IF scanner charater is operator and it's priority is greater than top() element of stack (and also empty stack), PUSH it
        //ELSE pop until less than or equal to operand is surfaced, print pop() elements and then finally, push the current
// STEP3: If "(", push it
// STEP4: If ")" pop until "("
// do above steps until infix expression is done
// POP and output the stack elements;

bool isOperator(char c)
{
	bool result = false;
	switch(c)
	{
		case '+':
		case '-':
		case '*':
		case '/':
		case '^':
			result = true;
			break;
		default:
			result = false;
	}	
	return result;
}

int priority(char c)
{
	int priority = -1;
	
	switch(c)
	{
		case '+':
		case '-':
			priority = 1;
			break;
		case '*':
		case '/':
			priority = 2;
			break;
		case '^':
			priority = 3;
			break;
		default:
			priority = -1;
	}
	return priority;
}

string infixToPostfix(char* s)
{
	stack<char> st;
	string output = "";
	char temp;
	
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]=='(')
		{
			st.push(s[i]);
		}
		else if(s[i]==')')
		{
			// pop until (
			while((temp=st.top())!='(')
			{
				st.pop();
				output = output + temp;
			}
			// pop final ( char also
			st.pop();
		}
		else if(isOperator(s[i]))
		{
			// stack empty OR
			// If operator priority is greater
			if(st.empty() || priority(s[i]) > priority(st.top()) )
			{
				// simple case. Just put it onto stack
				st.push(s[i]);
			}
			else
			{	
				// pop elements until we found a low priotity operator
				while( !st.empty() &&  priority(s[i]) <= priority(st.top()) )
				{
					temp = st.top(); st.pop();
					output = output + temp;
				}
				// Now good to push the current operator
				st.push(s[i]);
			}
		}
		else
		{
			// operand
			output = output + s[i];
		}
	}
	
	while(!st.empty())
	{
		temp = st.top();st.pop();
		output = output + temp;
	}
	return output;
}
 

// Main
int main()
{
	char str[] = "a+b*(c^d-e)^(f+g*h)-i";
	//char str[] = "a+b*c";
	
	cout << infixToPostfix(str) << endl;
	
	return 0;
}

