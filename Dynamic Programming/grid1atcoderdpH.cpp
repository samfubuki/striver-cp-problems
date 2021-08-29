#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,m;
    cin>>n>>m;
    long long int mod = 1e9+7;
    vector< vector<long long int> > t(n+1, vector<long long int>(m+1,0));
    t[0][0]=1;
    for(long long int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        for(long long int j=0;j<m;j++)
        {
            if(s[j]=='.')
            {
                 if(i>0)
                {
                    t[i][j] += t[i-1][j];
                    t[i][j] %= mod;
                }
                if(j>0)
                {
                    t[i][j] += t[i][j-1];
                    t[i][j] %= mod;
                }
            }
            else
            {
                t[i][j]=0;
            }
        }
    }
    cout<<t[n-1][m-1]<<endl;
    return 0;
}
