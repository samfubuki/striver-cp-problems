#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    long long int sum = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i]<0)
	        {
	            arr[i]=sum/i;
	        }
	     sum = sum+arr[i];
	     cout<<arr[i]<<" ";
	    }
	  cout<<endl;
	}
	return 0;
}
