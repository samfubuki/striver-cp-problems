#include<bits/stdc++.h>
using namespace std;
long long int n,w,wt[100009],val[100009];
long long int dp[109][100009];
long long int solve(long long int r, long long int idx) {
    if(idx == n)
        return r == 0 ? 0 : INT_MAX;

    if(dp[idx][r] != -1)
    	return dp[idx][r];

    long long int ans = solve(r, idx + 1);
    if(val[idx] <= r)
    	ans = min(ans, wt[idx] + solve(r - val[idx], idx + 1));

    return dp[idx][r] = ans;
}
int s(int val_max)
{
   for(int i=val_max;i>=0;i--)
   {
       if(solve(i,0)<=w)
       {
           return i;
       }
   }
  return 0;
}
int main()
{
    cin>>n>>w;
    memset(dp,-1,sizeof(dp));
    long long int val_max=0;
    for(long long int i=0;i<n;i++)
    {
        cin>>wt[i]>>val[i];
        val_max = val_max+val[i];
    }
     cout<<s(val_max)<<endl;
  return 0;
}
