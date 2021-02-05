#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int findK(int a[3][3], int n, int m, int k)
    {
        // Your code goes here
        int l=0,r=m-1,t=0,b=n-1;
        int count=0;
        int dir=1;
        while(l<=r && t<=b)
        {
            if(dir==1)
            {
                for(int i=l; i<=r; i++)
                {
                    count++;
                    if(count==k)
                    {
                        return a[t][i];
                    }
                }
                t++;
                dir = 3;
            }
            
            else if(dir==2)
            {
                for(int i=r; i>=l; i--)
                {
                    count++;
                    if(count==k)
                    {
                        return a[b][i];
                    }
                }
                b--;
                dir= 4;
            }
            else if(dir==3)
            {
                for(int i=t; i<=b; i++)
                {
                    count++;
                    if(count==k)
                    {
                        return a[i][r];
                    }
                }
                r--;
                dir=2;
            }
            else if(dir==4)
            {
                for(int i=b; i>=t; i--)
                {
                    count++;
                    if(count==k)
                    {
                        return a[i][l];
                    }
                }
                l++;
                dir=1;
            }
            dir=(dir+1)%4 +1;
        }
    }

int main()
{
    int m=3,n=3;
    int k=4,o;
    int a[3][3];
    for(int i=0; i<n; i++)
    {
    	for(int j=0; j<n; j++)
    	{
    		cin>>a[i][j];
		}
	}
    o= findK(a, n, m,k);
    cout<<a;
	return 0;
}
