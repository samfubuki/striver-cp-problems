#include<bits/stdc++.h>
using namespace std;
int getSum(int n)
{
 int sum = 0;
 while (n != 0)
 {
  sum = sum + n % 10;
  n = n / 10;
 }
return sum;
}
bool isPrime(int n)
{
    if (n <= 1)
        return false;

    for (int i = 2; i*i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}
int main()
{
  int n;
  cin>>n;
  while(n--)
  {
      int t1,t2;
      cin>>t1>>t2;
      int cnt = 0;
      for(int i=t1;i<=t2;i++)
      {
          int ans = getSum(i);
          if(isPrime(ans)==true)
          {
              cnt++;
          }
      }
    cout<<cnt<<endl;
  }
 return 0;
}
