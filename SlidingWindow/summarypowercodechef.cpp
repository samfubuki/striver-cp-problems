#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    string s;
	    cin>>s;
	    long long int ans=0,sum=0;
	    for(int i=0;i<k;i++)
	    {
	        if(s[i]!=s[i+1])
	        {
	            sum = sum+1;
	        }
	    }
	    for(int i=0;i<(n-k);i++)
	    {
	        ans = ans+sum;
	        if(i+k+1>n)
	        {
	            break;
	        }
	        if(s[i]!=s[i+1])
	        {
	            sum = sum-1;
	        }
	        if(s[i+k]!=s[i+k+1])
	        {
	            sum = sum+1;
	        }
	    }
	  cout<<ans<<endl;
	}
	return 0;
}
