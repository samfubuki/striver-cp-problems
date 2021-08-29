#include<bits/stdc++.h>
using namespace std;
bool prime[100009];
long long int i,j;
void sieve()
{
  memset(prime,1,sizeof(prime));
  prime[0]=0,prime[1]=0;
  for(i=4;i<=100009;i+=2)
  {
     prime[i]=0;
  }
  for(i=3;i<=100009;i+=2)
  {
    if(prime[i]==1)
    {
        for(j=i*2;j<=100009;j=j+i)
        {
            prime[j]=0;
        }
    }
  }
}
int main()
{
    int n;
    cin>>n;
    sieve();
    if(n<3)
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"2"<<endl;
    }
    for(i=2; i<=n+1; i++)
    {
        if(prime[i]==1)
        {
         cout<<"1 ";
        }
        else
        {
          cout<<"2 ";
        }
    }
return 0;
}
