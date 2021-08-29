#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int x=0;
	for(int i=0;i<n;i++)
	{
		x=x^arr[i];
	}
	int pos = floor(log2(x)+1);
	int ans1=0,ans2=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i] & (1<<(pos-1)))
		{
         ans1=ans1^arr[i];
		}
		else
		{
			ans2=ans2^arr[i];
	 	}
	}
	if(ans1<ans2)
	{
		cout<<ans1<<" "<<ans2;
	}
	else
	{
		cout<<ans2<<" "<<ans1;
	}
return 0;
}
