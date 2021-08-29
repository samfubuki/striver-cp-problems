#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
    int n=0,x=0;
    cin>>n>>x;
    int coin[n];
    for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    long long int value[x+1];
    value[0]=1;
    for(int i=1;i<=x;i++)
    {
        value[i]=0;
        for(auto it:coin)
        {
            if(i-it>=0)
            {
                value[i]+=(value[i-it]%1000000007);
            }
        }
    }
  cout<<value[x]%(1000000007);
  return 0;
}
