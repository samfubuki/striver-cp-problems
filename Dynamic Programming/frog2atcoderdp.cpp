#include<bits/stdc++.h>
using namespace std;
const long long int maxN = (1*1e5+10);
long long int arr[maxN];
long long int n,k;
long long int dp[maxN];
long long int func(long long int ind)
{
    if(ind==(n-1))
    {
        return 0;
    }
    else if(dp[ind]!=-1)
    {
        return dp[ind];
    }
    else
    {
        long long int ans = 1e9+5;
        for(int i=1;i<=k;i++)
        {
            if(ind+i<n)
            {
                ans = min(ans,abs(arr[ind+i]-arr[ind])+func(ind+i));
            }
        }
       return dp[ind]=ans;
    }
}
int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<func(0);
    return 0;

}


