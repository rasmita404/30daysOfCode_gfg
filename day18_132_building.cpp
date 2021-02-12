// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
 //User function template for C++

class Solution{
public:
	bool recreationalSpot(int arr[], int n){
		// Your code goes here 
		stack<int> st1, st2;
		st1.push(arr[0]);
		st2.push(arr[0]);
		for(int i=1; i<n; i++)
		{
		    if(arr[i] > st1.top() && arr[i] < st2.top())
		    return true;
		    if(arr[i]<st1.top()) 
		    st1.push(arr[i]);
		    if(arr[i]>st2.top())
		    st2.push(arr[i]);
		}
		return false;
		return false;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
} 
