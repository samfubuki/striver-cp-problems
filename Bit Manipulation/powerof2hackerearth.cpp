#include<bits/stdc++.h>
using namespace std;
bool powerof2(long long int x)
{
    long long int a = x & (x-1);
    if(a==0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
  long long int n;
  cin>>n;
  long long int x;
  long long int cnt=0;
  while(n--)
  {
   cin>>x;
   if(powerof2(x)==true)
   {
       cnt++;
   }
  }
cout<<cnt;
return 0;
}
