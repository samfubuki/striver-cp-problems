#include<bits/stdc++.h>
using namespace std;
long long int n,arr[100005];
long long int dp[100005];
int func(int ind)
{
    if(ind==n-1)
    {
        return 0;
    }
    if(ind>=n)
    {
        return INT_MAX;
    }
    if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    long long int left = abs(arr[ind]-arr[ind+1])+func(ind+1);
    long long int right = INT_MAX;
    if(ind+2<n)
    {
        right = abs(arr[ind]-arr[ind+2])+func(ind+2);
    }
    return dp[ind]=min(left,right);
}
int main()
{
    cin>>n;
    memset(dp,-1,sizeof(dp));
    for(long long int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<func(0);
 return 0;
}
