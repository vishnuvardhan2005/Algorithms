#include <iostream>
#include <stack>
using namespace std;

// Algorithm
// STEP1: Traverse the postfix expresssion
// STEP2: If operand, push onto stack
// STPE3: else if operator, pop 2 elements from stack and perform the operation and push the result
// STEP4: Return the stack top element as result

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

int evaluate(int n1,int n2,char oper)
{
	int result = 0;
	
	switch(oper)
	{
		case '+':
			result = n1+n2;
			break;
		case '-':
			result = n1-n2;
			break;
		case '*':
			result = n1*n2;
			break;
		case '/':
			if(n2==0)
				throw "Error";
			result = n1/n2;
			break;
		default:
			break;
	}
	return result;
}


int evaluatePostfix(char* s)
{
	int n1;
	int n2;
	stack<int> st;
	
	for(int i=0;s[i]!='\0';i++)
	{
		if(isOperator(s[i]))
		{
			n2 = st.top();st.pop();
			n1 = st.top();st.pop();
			st.push(evaluate(n1,n2,s[i]));
		}
		else
		{
			st.push(s[i]-'0');
		}
	}
	
	if(st.empty())
		throw "Error";
		
	return st.top();
}

// Main
int main()
{
	char s[] = "231*+9-";
	cout << evaluatePostfix(s) << endl;
 	return 0;
}

