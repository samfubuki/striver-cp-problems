#include<bits/stdc++.h>
using namespace std  ;
int isprime[10000001];
void sieve()
{
    int maxN = 10000000;
    for(int i=1;i<=maxN;i++)
    {
        isprime[i]=1;
    }
    isprime[0]=isprime[1]=0;
    for(int i=2;i*i<=maxN;i++)
    {
        if(isprime[i])
        {
            for(int j=i*i;j<=maxN;j+=i)
            {
              isprime[j]=0;
            }
        }
    }
}
int main()
{
  int p;
  cin>>p;
  int t;
  cin>>t;
  sieve();
  while(t--)
  {
    int n;
    cin>>n;
    long long int cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            if(isprime[i])
            {
                cnt++;
            }
        }
    }
    if(cnt>=p)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
  }
return 0;
}
