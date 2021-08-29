#include <bits/stdc++.h>
using namespace std;
bool checkMin(long long int mid, long long int arr[], long long int n, long long int k)
{
    long long int sum=0;
    for(long long int i=0;i<n;i++)
    {
        if(arr[i]>=mid)
        {
            sum=sum+mid;
        }
        else
        {
            sum=sum+arr[i];
        }
    }
    if((sum/mid)>=k)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main() {
	long long int n,k;
	cin>>n>>k;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
	sort(arr,arr+n);
	long long int start=0, end=1e18;
	long long int mid,ans;
	while(start<=end)
	{
	    mid = start + (end-start)/2;
	    if(checkMin(mid,arr,n,k))
	    {
	        start=mid+1;
	        ans=mid;
	    }
	    else
	    {
	        end=mid-1;
	    }

	}
	cout<<ans<<endl;
	return 0;
}
