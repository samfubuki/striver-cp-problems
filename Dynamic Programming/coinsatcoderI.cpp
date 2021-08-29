#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    cout<<setprecision(10);
    vector<double> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    vector<vector<double> > dp(n+1,vector<double>(n+1,0.0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0)
            {
                dp[i][j]=dp[i-1][j]*(1-a[i-1]);
            }
            else
            {
                dp[i][j]=dp[i-1][j]*(1-a[i-1]) + dp[i-1][j-1]*(a[i-1]);
            }
        }
    }
    double ans = 0.0;
    for(int i=n;i>n/2;i--)
    {
        ans = ans + dp[n][i];
    }
    cout<<ans;
}


