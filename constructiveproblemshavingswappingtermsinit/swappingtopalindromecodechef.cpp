#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    char arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    int visited[n];
	    memset(visited,0,sizeof(visited));
	    int operations=0;
	    bool flag=true;
	    for(int i=0;i<=n/2;i++)
	    {
	        if(arr[i]==arr[n-i-1])
	        {
	          continue;
	        }
	        else
	        {
	            if(arr[i+1]==arr[n-i-1] && visited[i]==0 && visited[i+1]==0 && (i+1)!=(n-i-1))
	            {
	                char temp=arr[i];
	                arr[i]=arr[i+1];
	                arr[i+1]=temp;

	                visited[i]=visited[i+1]=1;
	                operations++;
	            }
	            else if(arr[n-i-2]==arr[i] && visited[n-i-1]==0 && visited[n-i-2]==0 && i!=(n-i-2))
	            {
	                char temp=arr[n-i-1];
	                arr[n-i-1]=arr[n-i-2];
	                arr[n-i-2]=temp;
	                visited[n-i-1]=visited[n-i-2]=1;

	                operations++;
	            }
	            else
	            {
	                flag=false;
	                break;
	            }
	        }

	    }
	     if(flag==false)
	     {
	         cout<<"NO"<<endl;
	     }
	     else
	     {
	         cout<<"YES"<<endl;
	         cout<<operations<<endl;
	     }
	}
	return 0;
}

