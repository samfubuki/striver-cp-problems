#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long long int n,a,b,i,j;
	    cin>>n>>b>>a;
	    long long int arr[n];
	    for(long long int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	     double avg,temp;
	    avg=0.0;
	    for(long long int i=a;i<=b;i++)
	    {
	        temp=0;
	        for(j=0;j<i;j++)
	        {
	            temp=temp+arr[j];
	        }
	        avg=max(avg,temp/i);
	        for(long long int j=i;j<n;j++)
	        {
	            temp = temp + arr[j]-arr[j-i];
	            avg = max(avg,temp/i);
	        }
	    }
	  cout<<fixed<<setprecision(6)<<avg<<endl;
	}
	return 0;
}
