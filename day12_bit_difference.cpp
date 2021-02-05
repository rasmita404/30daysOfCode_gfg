#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    long long sumBitDiff(int arr[], int n) 
    { 
        // Your code goes here
        sort(arr,arr+n);
        int ans =0;
        for (int i = 0; i < 32; i++) { 
        // count number of elements with i'th bit set 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if ((arr[j] & (1 << i))) 
                count++; 
  
        // Add "count * (n - count) * 2" to the answer 
        ans += (count * (n - count) * 2); 
    } 
  
    return ans; 
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
    	int arr[n];
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	Solution obj;
		cout << obj.sumBitDiff(arr, n) << "\n";
    }
	return 0; 
}
