#include <iostream>
using namespace std;

int min(int a,int b,int c)
{
	if(a<b&&a<c)
		return a;
	else if(b<c)
		return b;
	else
		return c;
}

int EditDistance(string s1,string s2,int m,int n)
{
	if(m==0) // insert n chars from s2 to s1
		return n;
	if(n==0) // remove m chars from s1
		return m;
		
	// if last char is same, then need to work on remaining string
	if(s1[m-1]==s2[n-1])
		return EditDistance(s1,s2,m-1,n-1);
		
	return 1+min(EditDistance(s1,s2,m,n-1),  // insert last char of s2 in s1
				EditDistance(s1,s2,m-1,n),  // remove last char in s1
				EditDistance(s1,s2,m-1,n-1)  // replace last char from s2 to s1
				);
	
}

// Main
int main()
{
	string s1 = "sunday";
	string s2 = "saturday";
	cout << EditDistance(s1,s2,s1.length(),s2.length()) << endl;
	return 0;
}
