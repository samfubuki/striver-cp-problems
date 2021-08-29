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
	stack<int> st;
	int cnt=0;
	st.push(arr[0]);
	for(int i=1;i<n;i++)
	{
		while(!st.empty() && st.top()<=arr[i])
		{
			st.pop();
		}
		if(!st.empty() && arr[i]<st.top())
		{
			cnt++;
		}
     st.push(arr[i]);
	}
	stack<int> st2;
	st2.push(arr[n-1]);
	for(int i=n-2;i>=0;i--)
	{
		while(!st2.empty() && st2.top()<=arr[i])
		{
			st2.pop();
		}
		if(!st2.empty() && arr[i]<st2.top())
		{
			cnt++;
		}
     st2.push(arr[i]);
	}
 cout<<cnt<<endl;
 return 0;
}
