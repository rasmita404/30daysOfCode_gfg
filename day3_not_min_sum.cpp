//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends


//User function Template for C++

class Solution
{   
public:
    long long smallestpositive(vector<long long> array, int n)
    { 
        // code here 
        sort(array.begin(), array.end());
        long long min_sum =1;
        for(int i=0; i<n && min_sum>=array[i]; i++)
        {
            min_sum += array[i];
        }
        return min_sum;
    } 
};


// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<long long> array(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>array[i];
        }
        Solution ob;
        cout<<ob.smallestpositive(array,n)<<"\n";
    }
    return 0; 
} 
  // } Driver Code Ends
