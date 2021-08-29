#include<bits/stdc++.h>
using namespace std;
vector<long long int> prime;
long long int lowlim,highlim;
void intersection(long long int x, long long int y)
{
    long long int lim1;
    if(lowlim!=-1 && highlim!=-1)
    {
        lim1=max(x,lowlim);
        if(lim1<=highlim)
        {
            lowlim=lim1;
            highlim = min(highlim,y);
        }
        else
        {
            lowlim=-1;
            highlim=-1;
        }
    }

}
void countPrimes(long long int low, long long int high)
{
    int check[high-low+1]={0};
    long long int lim,i,j;
    if(low==1)
    {
        check[0]=1;
    }
    for(i=0;i<prime.size();i++)
    {
     lim=(low/prime[i])*prime[i];
     if(lim<low)
     {
         lim+=prime[i];
     }
     if(lim==prime[i])
     {
         lim+=prime[i];
     }
     for(j=lim;j<=high;j+=prime[i])
     {
         check[j-low]=1;
     }
    }
    long long int cnt=0;
    for(i=0;i<high-low+1;i++)
    {
        if(check[i]==0)
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
}

int main()
{
  int sieve[1000001]={0};
  long long int i,j;
  sieve[0]=1,sieve[1]=1;
  for(i=2;i<1000001;i++)
  {
      if(sieve[i]==0)
      {
          prime.push_back(i);
          for(j=2*i;j<1000001;j+=i)
          {
              sieve[j]=1;
          }
      }
  }
  long long int t,n;
  cin>>t;4
  long long int x,y;
  while(t--)
  {
      cin>>n;
      cin>>x>>y;
      lowlim=x;
      highlim=y;
      for(int i=0;i<n-1;i++)
      {
          cin>>x>>y;
          intersection(x,y);
      }
      if(lowlim!=-1 && highlim!=-1)
      {
          countPrimes(lowlim,highlim);
      }
      else
      {
          cout<<"-1"<<endl;
      }
  }
return 0;
}
