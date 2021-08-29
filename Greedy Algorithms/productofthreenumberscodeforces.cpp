#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    long long int cnt=0;
    while(t--)
    {
        long long int n;
        cin>>n;
        long long int N;
        N=n;
        cnt=0;
        vector<long long int> ans;
        for(int i=2;i*i<=N;i++)
        {
            if(n%i==0)
            {
                cnt++;
                n=n/i;
                ans.push_back(i);
            }
            if(cnt==2)
            {
              ans.push_back(n);
              break;
            }
        }
        if(cnt<2)
        {
            cout<<"NO"<<endl;
        }
        else if(ans[0]==ans[2] || ans[1]==ans[2])
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
            cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
        }
    }
 return 0;
}
