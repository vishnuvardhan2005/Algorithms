#include <iostream>
using namespace std;

// rotates array by k elements. 
void rotateArray(int* a,int n,int k)
{
	// constraints on n
	if(n<=1)
		return;
	// constraints on k
	k = k%n;
	if(k<=0)
		return;
		
	// Shift first element to last
	// todo.. This is inefficient. can be improved.
	int firstElem;
	while(k!=0)
	{
		firstElem = a[0];
		for(int i=1;i<n;i++)
		{
			a[i-1] = a[i];
		}
		a[n-1] = firstElem;
		
		k--;
	}
}

void printArray(int* a,int n)
{
	for(int i=0;i<n;i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

// Main
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int n = sizeof(a)/sizeof(int);
	int k = 5;
	// Print array
	printArray(a,n);
	// Rotate array
	rotateArray(a,n,k);
	
	printArray(a,n);
	
	return 0;
}

