//find duplicates in an array of size n having elements in between 0 to n-1 in O(n) time and O(1) extra space

#include<iostream>
using namespace std;

void occurence(int a[], int n)
{
	//assume the input array as a dictionary where index i is the key and a[i] storing it's prev value and n is added the number of times element i occurs in a[] 
	for(int i=0; i<n; i++)
	{
		a[a[i]%n] = a[a[i]%n]+n; 
	}
	cout<<"number-occurence\n";
	for(int i=0; i<n; i++)
	{
		cout<<i<<" - "<<a[i]/n<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
	}
	occurence(a, n);
	return 0;
}
