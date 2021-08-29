#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int arr[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    long long int sum=0,ans=0;
	    int j=0;
	    for(int i=0;i<k;i++)
	    {
	        sum = sum + arr[i];
	    }
	    ans =sum;
	    for(int i=k;i<n+k;i++)
	    {
	        sum = sum + arr[i%n];
	        sum = sum - arr[j];
	        j++;
	        ans = max(ans,sum);
	    }
	   cout<<ans<<endl;
	}
	return 0;
}
