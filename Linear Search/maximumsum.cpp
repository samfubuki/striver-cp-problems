#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n;
	cin>>n;
	long long int arr[n];
	for(long long int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	long long int sum=0,cnt=0;
	for(long long int i=0;i<n;i++)
	{
	if(arr[i]>=0)
	{
      sum = sum + arr[i];
	  cnt++;
	}
	}
	sort(arr,arr+n);
	if(cnt==0)
	{
		cout<<arr[n-1]<<" "<<"1"<<endl;
	}
	else
	{
		cout<<sum<<" "<<cnt<<endl;
	}
return 0;
}
